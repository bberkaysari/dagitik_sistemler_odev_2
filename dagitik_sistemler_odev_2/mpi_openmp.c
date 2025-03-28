#include <mpi.h>
#include <omp.h>
#include <stdio.h>

void process_data(int rank, int* data) {
    printf("\n[DÜĞÜM %d] Gelen veri: %d\n", rank, *data);

    // Paralel hesaplama başlatılıyor
    printf("[DÜĞÜM %d] Paralel hesaplama yapılıyor...\n", rank);
    
    // OpenMP ile paralel hesaplama (Ancak artık thread'lerin ID'leri ekrana yazdırılmıyor)
    #pragma omp parallel for
    for (int i = 0; i < 1; i++) {  // Tek bir veri olduğu için döngü 1 kere çalışıyor
        *data = (*data * 3) - rank;
    }

    printf("[DÜĞÜM %d] Güncellenmiş veri: %d\n", rank, *data);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size, data = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Master başlangıç değerini belirler
        printf("\n[MASTER] Hesaplama başlıyor. Başlangıç değeri: %d\n", data);
        data = 4;
        printf("[MASTER] Düğüm 1'e veri gönderildi: %d\n", data);
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }

    for (int i = 1; i < size; i++) {
        if (rank == i) {
            MPI_Recv(&data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            process_data(rank, &data);

            // Eğer son düğüm değilse, veriyi bir sonraki düğüme gönder
            if (rank != size - 1) {
                printf("[DÜĞÜM %d] Veri düğüm %d'e gönderildi: %d\n", rank, rank + 1, data);
                MPI_Send(&data, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
            } else {
                // Son düğüm sonucu Master'a gönderir
                printf("[DÜĞÜM %d] Son düğüm. Master’a sonuç gönderildi: %d\n", rank, data);
                MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            }
        }
    }

    if (rank == 0) {
        MPI_Recv(&data, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\n[MASTER] Tüm işlemler tamamlandı. Nihai sonuç: %d\n", data);
    }

    MPI_Finalize();
    return 0;
}
