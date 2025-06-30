#ifndef MULTEX_H
#define MULTEX_H

void *codigo_tarefa_deposito(void *arg);
void *codigo_tarefa_saque(void *arg);
int multex_main(void);

#endif // MULTEX_H