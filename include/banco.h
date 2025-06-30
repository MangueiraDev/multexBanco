#ifndef BANCO_H
#define BANCO_H

#include <pthread.h>

extern pthread_mutex_t mutex_saldo;
extern double saldo;

void deposito(double valor);
double saque(double valor);

#endif // BANCO_H