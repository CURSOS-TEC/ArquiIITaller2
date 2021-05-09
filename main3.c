#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x = 5;
    #pragma omp parallel shared(x)
    {
        x = x + 1;
        printf("private: x is %d\n", x);
    }
    printf("after: x is %d\n", x); 
}