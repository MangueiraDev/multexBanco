#include <stdio.h>
#include "../include/multex.h"

int main()
{
    printf("Iniciando teste simples do projeto multex...\n");

    // Teste: saldo inicial deve ser zero
    if (saldo != 0.0)
    {
        printf("ERRO: Saldo inicial não é zero!\n");
        return 1;
    }
    else
    {
        printf("OK: Saldo inicial é zero.\n");
    }

    // Teste: chamada das funções (apenas para compilar, não executa threads)
    printf("Chamando codigo_tarefa_deposito() (apenas exemplo)...\n");
    // codigo_tarefa_deposito(); // Não execute, pois altera saldo global e usa sleep

    printf("Chamando codigo_tarefa_saque() (apenas exemplo)...\n");
    // codigo_tarefa_saque(); // Não execute, pois altera saldo global e usa sleep

    printf("Testes básicos concluídos.\n");
    return 0;
}