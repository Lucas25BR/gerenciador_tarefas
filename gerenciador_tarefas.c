/*
##################################################
Alunos: Lucas Viana, João Galhard, Kevin
Versão:
##################################################
*/

#include <stdio.h>

#define STR_MAX_LEN 0x20
#define TAREFAS_LEN 0x40
#define LISTAS_LEN 0x40

int top_id = 0;

listas_nome[LISTAS_LEN];

int tarefas_id[TAREFAS_LEN];
int tarefas_prioridade[TAREFAS_LEN];
int tarefas_lista[TAREFAS_LEN];

char tarefas_nome[TAREFAS_LEN][STR_MAX_LEN];
char tarefas_data[TAREFAS_LEN][STR_MAX_LEN];

void exibir_tarefas();
void adicionar_tarefa();
void gerenciar_tarefas();
void gerenciar_listas();
void filtros();

int main()
{

    // MENU
    int op;
    do
    {
        exibir_tarefas();

        // MENU DE OPÇÕES
        switch (op)
        {
            // SAIR
        case 0:
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;

        default:
            break;
        }

    } while (op);
    return 0;
}

void exibir_tarefas()
{
    printf("TAREFAS: \n");
    for (int id = 0; id < top_id; id++)
    {
        printf("%d - %s\n", id, tarefas_nome[id]);
    }

    return;
}

void adicionar_tarefa()
{
    int op;

    switch (op)
    {
    // MENU INICIAL
    case 0:
        break;

    default:
        break;
    }

    return;
}
void gerenciar_tarefas()
{
    int op;

    switch (op)
    {
    // MENU INCIAL
    case 0:
        break;

    case 1:

        break;
    default:
        break;
    }

    return;
}

void gerenciar_listas()
{
    int op;

    switch (op)
    {
    // MENU INICIAL
    case 0:
        break;

    default:
        break;
    }

    return;
}

void filtros()
{
    int op;

    switch (op)
    {
        // MENU INICIAL
    case 0:
        break;

    default:
        break;
    }

    return;
}
