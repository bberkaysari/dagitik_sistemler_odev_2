# Dağıtık Paralel Hesaplama Sistemi (MPI + OpenMP + Docker)

Bu proje, **Docker, MPI ve OpenMP** kullanarak **dağıtık bir paralel hesaplama sistemi** oluşturur. Docker Compose kullanarak birden fazla konteynerde çalışan bir mimari kurulmuş ve bu sistemde **MPI ile veri iletişimi** ve **OpenMP ile çok çekirdekli hesaplama** gerçekleştirilmiştir.

## 🛠️ Proje Bileşenleri

- **Docker & Docker Compose**: Dağıtık sistem altyapısını oluşturmak için.
- **MPI (Message Passing Interface)**: Düğümler arası veri iletişimini sağlamak için.
- **OpenMP (Open Multi-Processing)**: Her düğümde çok çekirdekli paralel hesaplama yapmak için.
- **C Programlama Dili**: Paralel hesaplama için kodlama dili.

## 🔄 Mimari

Proje, Docker kullanarak **bir master ve birden fazla worker düğümü** oluşturur. Master düğüm veriyi parçalar ve worker düğümlere yollar. Her worker, OpenMP kullanarak paralel hesaplama yapar ve sonucu geri gönderir.

```plaintext
+-----------------+
|  Master Node   |
+-----------------+
        |
        v
+----------------+
| Worker Node 1  |
+----------------+
        |
        v
+----------------+
| Worker Node 2  |
+----------------+
        |
        v
+----------------+
| Worker Node N  |
+----------------+
```

## 💻 Kurulum ve Çalıştırma

### 1. Gereksinimler

- **Docker** ve **Docker Compose** yükleyin.
- **Git** kurulu olmalı.

### 2. Projeyi Klonlayın

```sh
git clone https://github.com/kullaniciadi/mpi-openmp-dagitik.git](https://github.com/bberkaysari/dagitik_sistemler_odev_2.git
cd mpi-openmp-dagitik
```

### 3. Docker Konteynerlerini Oluşturun ve Çalıştırın

```sh
docker-compose up --build -d
```

### 4. Master Konteynerine Bağlanın

```sh
docker exec -it mpi-master bash
```

### 5. Bir Worker Düğümünü Pingleyin

```sh
ping dagitik_sistemler_odev_2-worker-5
```

### 6. Logları Görmek İçin

```sh
docker logs -f mpi_master
```

### 7. Tüm Konteynerleri Durdurmak İçin

```sh
docker-compose down
```

## 📊 Performans Karşılaştırması

Bu projede **MPI ve OpenMP** kullanarak performans farkları incelenmiştir.

| **Metodoloji** | **Zaman (sn)** |
| -------------- | -------------- |
| Tek Thread     | 10.24          |
| OpenMP         | 3.81           |
| MPI + OpenMP   | 1.92           |

### Sonuç

- **OpenMP**, **tek thread'li** koddan 2.7 kat hızlı.
- **MPI + OpenMP**, en iyi performansı sunarak **yaklaşık 5.3 kat hız artışı** sağladı.
- Özellikle **büyük veri setlerinde** MPI'nin etkili olduğu gözlemlendi.


