#ifndef MULTEX_H
#define MULTEX_H

#include <pthread.h>

extern pthread_t th_deposito[4];
extern pthread_t th_saque[4];
extern pthread_mutex_t mutex_saldo;
extern double saldo;

void codigo_tarefa_deposito(void);
void codigo_tarefa_saque(void);
int multex_main(void); // <-- Adicione esta linha

#endif // MULTEX_H