#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include "../include/multex.h"
#include "../include/banco.h"

#define N_THREADS 4

pthread_t th_deposito[N_THREADS];
pthread_t th_saque[N_THREADS];

void *codigo_tarefa_deposito(void *arg)
{
	for (int ns = 0; ns < 10; ++ns)
	{
		sleep(1);
		printf("Depositar 20.00 reais\n");
		deposito(20.0);
	}
	return NULL;
}

void *codigo_tarefa_saque(void *arg)
{
	for (int ns = 0; ns < 10; ++ns)
	{
		sleep(1);
		printf("Sacar 20.00 reais\n");
		saque(20.0);
	}
	return NULL;
}

int multex_main(void)
{
	printf("Inicio\n");
	printf("Saldo inicial %.2lf\n", saldo);

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);

	for (int i = 0; i < N_THREADS; ++i)
		pthread_create(&th_saque[i], NULL, codigo_tarefa_saque, NULL);

	for (int i = 0; i < N_THREADS; ++i)
		pthread_create(&th_deposito[i], NULL, codigo_tarefa_deposito, NULL);

	for (int i = 0; i < N_THREADS; ++i)
		pthread_join(th_saque[i], NULL);

	for (int i = 0; i < N_THREADS; ++i)
		pthread_join(th_deposito[i], NULL);

	clock_gettime(CLOCK_MONOTONIC, &end);

	double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

	printf("Saldo final ficou %.2lf\n", saldo);
	printf("Tempo total de execução: %.4f segundos\n", elapsed);
	printf("Fim\n");
	return 0;
}
