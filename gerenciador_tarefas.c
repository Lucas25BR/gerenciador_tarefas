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

enum{
    EXCLUIDO,
    EM_ANDAMENTO,
    CONCLUIDO
};


int listas_top_id = 0;
char listas_nome[LISTAS_LEN][STR_MAX_LEN];

int tarefas_top_id = 0;
int tarefas_id[TAREFAS_LEN];
int tarefas_prioridade[TAREFAS_LEN];
char tarefas_nome[TAREFAS_LEN][STR_MAX_LEN];
char tarefas_descricao[TAREFAS_LEN][280];
char tarefas_vencimento[TAREFAS_LEN][STR_MAX_LEN];

int tarefas_listas[TAREFAS_LEN]; //Cria relação entre tarefas e listas

// Funções principais
void adicionar_tarefa();
void gerenciar_tarefas();
void gerenciar_listas();
void filtros();

// Funções auxiliares
void tarefas_exibir();
void listas_exibir();
int tarefas_selecionar();
int listas_selecionar();

int main()
{
    // MENU
    int op;
    do
    {
        tarefas_exibir();

        // MENU DE OPÇÕES
        switch (op)
        {
        // SAIR
        case 0:
            break;
        case 1:
            gerenciar_listas();
            break;
        case 2:
            gerenciar_tarefas();
            break;
        case 3:
            filtros();
            break;

        default:
            break;
        }

    } while (op);

    return 0;
}

void tarefas_exibir()
{
    printf("TAREFAS: \n");
    for (int id = 0; id < tarefas_top_id; id++)
    {
        printf("%d - %s\n", id, tarefas_nome[id]);
    }

    return;
}

int tarefas_selecionar(){
    int t = 0;

    printf("Selecione a tarefa: \n");
    tarefas_exibir();

    scanf("%d", &t);

    return t;
}

void listas_exibir()
{
    printf("TAREFAS: \n");
    for (int id = 0; id < listas_top_id; id++)
    {
        printf("%d - %s\n", id, listas_nome[id]);
    }

    return;
}

int listas_selecionar(){
    int l = 0;

    printf("Selecione a tarefa: \n");
    listas_exibir();

    scanf("%d", &l);

    return l;
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
    case 0:
    // MENU INICIAL
        break;

    case 1:
        adicionar_tarefa();
        break;
    case 2:
        

        break;
    default:
        break;
    }

    return;
}

void gerenciar_listas()
{
    int op;
    int sel;

    switch (op)
    {
    case 0:
        // MENU INICIAL
        break;
    case 1:
        //ADICIONAR LISTA
        printf("Digite o nome da lista: ");
        fgets(listas_nome[listas_top_id], STR_MAX_LEN, stdin);
        listas_top_id++;        
        break;
    case 2:
        //RENOMEAR LISTA
        sel = listas_selecionar();
        printf("Digite o nome da lista: ");
        fgets(listas_nome[sel], STR_MAX_LEN, stdin);
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
    case 0:
    // MENU INICIAL
        break;

    default:
        break;
    }

    return;
}
