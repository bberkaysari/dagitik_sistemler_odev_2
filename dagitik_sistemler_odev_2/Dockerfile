FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    openmpi-bin \
    openmpi-common \
    libopenmpi-dev \
    gcc \
    build-essential

COPY mpi_openmp.c /mpi_openmp.c
RUN mpicc -fopenmp mpi_openmp.c -o mpi_openmp.out

ENV OMPI_ALLOW_RUN_AS_ROOT=1
ENV OMPI_ALLOW_RUN_AS_ROOT_CONFIRM=1

CMD ["mpirun", "-np", "4", "./mpi_openmp.out"]