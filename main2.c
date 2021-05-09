#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
#pragma omp parallel
    printf("Number of threads = %d\n", omp_get_num_threads());
}