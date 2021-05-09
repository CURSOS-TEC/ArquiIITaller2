#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "backUpData.c"
int vectorSize = 100000000;
int main(int argc, char const *argv[])
{
    if (argc == 2) vectorSize = atoi(argv[1]);
    omp_set_num_threads(8);
    float *Y = malloc(vectorSize * sizeof(float));
    float *X = malloc(vectorSize * sizeof(float));
    float *Z = malloc(vectorSize * sizeof(float));
    float scalar = 3.5;
    double start_time, run_time;
    start_time = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for
        for (size_t i = 0; i < vectorSize; i++)
        {
            X[i] = 5.5;
            Y[i] = 6.3;
            Z[i] = scalar * X[i] + Y[i];
        }
    }
    run_time = omp_get_wtime() - start_time;
    printf("SAXPY %f \n", run_time);
    return 0;
}
