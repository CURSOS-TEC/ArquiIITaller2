/*

This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.

The program was parallelized using OpenMP by adding just
four lines 

(1) A line to include omp.h -- the include file that 
contains OpenMP's function prototypes and constants.

(2) A pragma that tells OpenMP to create a team of threads

(3) A pragma to cause one of the threads to print the
number of threads being used by the program.

(4) A pragma to split up loop iterations among the team
of threads.  This pragma includes 2 clauses to (1) create a 
private variable and (2) to cause the threads to compute their
sums locally and then combine their local sums into a 
single global value.

History: Written by Tim Mattson, 11/99.

*/
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "backUpData.c"

long num_steps = 100000000;
double step;
int main(int argc, char *argv[])
{

	if (argc == 2)
	{
		num_steps = atoi(argv[1]);
	}
	int i;
	double x, pi, sum = 0.0;
	double start_time, run_time;

	step = 1.0 / (double)num_steps;
	// for (i = 1; i <= 8; i++)
	// {
	// }
	sum = 0.0;
	omp_set_num_threads(8);
	start_time = omp_get_wtime();
#pragma omp parallel
	{
#pragma omp single
		printf(" num_threads = %d", omp_get_num_threads());

#pragma omp for reduction(+ \
						  : sum)
		for (i = 1; i <= num_steps; i++)
		{
			x = (i - 0.5) * step;
			sum = sum + 4.0 / (1.0 + x * x);
		}
	}
	pi = step * sum;
	run_time = omp_get_wtime() - start_time;
	printf("\n pi is %f in %f seconds and %d threads\n", pi, run_time, 8);
	char* dataToStore = (char*)malloc(100 * sizeof(char));;
	// Prints "Hello world!" on hello_world
	sprintf(dataToStore, "%ld %lf %lf \n", num_steps, pi, run_time);
	writeData(dataToStore);
}
