#include <cstdio>
#include <omp.h>

int main(int argc, char *argv[]){

#pragma omp parallel num_threads(5)
	{
		int tid = omp_get_thread_num();
		if (tid == 0) printf("Numero de hilos: %d\n", omp_get_num_threads());
#pragma omp barrier
		printf("Hilo %d\n", tid);
	}

#pragma omp parallel sections num_threads(5)
	{
#pragma omp section
		{
			int tid = omp_get_thread_num();
			printf("Hilo %d pasa por la seccion 1\n", tid);
		}

#pragma omp section
		{
			int tid = omp_get_thread_num();
			printf("Hilo %d pasa por la seccion 2\n", tid);
		}

#pragma omp section
		{
			int tid = omp_get_thread_num();
			printf("Hilo %d pasa por la seccion 3\n", tid);
		}
	}


	std::getchar();
	return 0;
}