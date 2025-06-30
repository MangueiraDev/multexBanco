#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "../include/multex.h"

// 10 depósitos de 20 reais a cada 1 seg
void codigo_tarefa_deposito(void)
{
	for (int ns = 0; ns < 10; ++ns)
	{
		sleep(1);
		printf("Depositar 20.00 reais\n");
		pthread_mutex_lock(&mutex_saldo);
		saldo += 20;
		pthread_mutex_unlock(&mutex_saldo);
		printf("Depositou 20.00 reais\n");
	}
}

// 10 saques de 20 reais a cada 1 seg
void codigo_tarefa_saque(void)
{
	double sacou;
	for (int ns = 0; ns < 10; ++ns)
	{
		sleep(1);
		printf("Sacar 20.00 reais\n");
		pthread_mutex_lock(&mutex_saldo);
		if (saldo >= 20.0)
			sacou = 20.0;
		else
			sacou = saldo;
		saldo -= sacou;
		pthread_mutex_unlock(&mutex_saldo);
		printf("Sacou %0.2lf reais\n", sacou);
	}
}

pthread_t th_deposito[4];
pthread_t th_saque[4];
pthread_mutex_t mutex_saldo = PTHREAD_MUTEX_INITIALIZER;
double saldo = 0.0;

int multex_main(void)
{
	printf("Inicio\n");
	printf("Saldo inicial %0.2lf\n", saldo);

	// Cria todas as threads que sacam
	for (int i = 0; i < 4; ++i)
		pthread_create(&th_saque[i], NULL, (void *)codigo_tarefa_saque, NULL);

	// Cria todas as threads que depositam
	for (int i = 0; i < 4; ++i)
		pthread_create(&th_deposito[i], NULL, (void *)codigo_tarefa_deposito, NULL);

	// Espera por todas as threads que sacam
	for (int i = 0; i < 4; ++i)
		pthread_join(th_saque[i], NULL);

	// Espera por todas as threads que depositam
	for (int i = 0; i < 4; ++i)
		pthread_join(th_deposito[i], NULL);

	printf("Saldo final ficou %0.2lf\n", saldo);
	printf("Fim\n");
	return 0;
}
