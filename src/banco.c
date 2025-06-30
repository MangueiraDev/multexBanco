#include "../include/banco.h"
#include <stdio.h>

pthread_mutex_t mutex_saldo = PTHREAD_MUTEX_INITIALIZER;
double saldo = 0.0;

void deposito(double valor)
{
    pthread_mutex_lock(&mutex_saldo);
    saldo += valor;
    printf("Depositou %.2lf reais | Saldo atual: %.2lf\n", valor, saldo);
    pthread_mutex_unlock(&mutex_saldo);
}

double saque(double valor)
{
    pthread_mutex_lock(&mutex_saldo);
    double sacado = (saldo >= valor) ? valor : saldo;
    saldo -= sacado;
    printf("Sacou %.2lf reais | Saldo atual: %.2lf\n", sacado, saldo);
    pthread_mutex_unlock(&mutex_saldo);
    return sacado;
}