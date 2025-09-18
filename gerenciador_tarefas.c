/*
##################################################
Alunos: Lucas Viana, João Galhard, Kevin
Versão:
##################################################
*/

#include <stdio.h>

#define NOME_MAX_LEN 0x20
#define TAREFAS_LEN 0x40
#define LISTAS_LEN 0x40
#define NILL -1

enum status {
    EXCLUIDO,
    EM_ANDAMENTO,
    CONCLUIDO
};

enum prioridade {
    ALTA,
    MEDIA,
    BAIXA
};

int listas_top_id = 0;
char listas_nome[LISTAS_LEN][NOME_MAX_LEN];
int listas_status[LISTAS_LEN];

int tarefas_top_id = 0;
int tarefas_id[TAREFAS_LEN];
int tarefas_prioridade[TAREFAS_LEN];
char tarefas_nome[TAREFAS_LEN][NOME_MAX_LEN];
char tarefas_descricao[TAREFAS_LEN][280];
char tarefas_vencimento[TAREFAS_LEN][NOME_MAX_LEN];
int tarefas_status[TAREFAS_LEN];

int tarefas_listas[TAREFAS_LEN]; //Cria relação entre tarefas e listas

// Funções principais
void tarefas_editar(int);
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
        printf(
            "\nDigite uma opção:\n"
            "0 - SAIR\n"
            "1 - Gerenciar tarefas\n"
            "2 - Gerenciar listas\n"
            "3 - FILTROS\n"
        );
        
        scanf("%d", &op);
        // MENU DE OPÇÕES
        switch (op)
        {
        // SAIR
        case 0:
            printf("SAINDO...\n");
            break;
        case 1:
            gerenciar_tarefas();
            break;
        case 2:
            gerenciar_listas();
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

void tarefas_editar(int sel)
{
    int id;

    if(sel == -1)
        id = tarefas_top_id;
    else
        id = sel;

    printf("Digite o nome da tarefa: ");
    fgets(tarefas_nome[id], NOME_MAX_LEN, stdin);
    printf("Digite a descrição da tarefa: ");
    fgets(tarefas_descricao[id], 280, stdin);
    printf("Digite a data de vencimento da tarefa: ");
    fgets(tarefas_vencimento[id], NOME_MAX_LEN, stdin);

    printf("Selecione a prioridade da tarefa: \n");
    printf("0 - ALTA\n");
    printf("1 - MEDIA\n");
    printf("2 - BAIXA\n");
    scanf("%d", &tarefas_prioridade[id]);

    //TODO: registrar definir lembrete

    return;
}
void gerenciar_tarefas()
{
    int op;
    int aux_id;

    printf(
            "\nDigite uma opção:\n"
            "0 - SAIR\n"
            "1 - Adicionar tarefa\n"
            "2 - Editar tarefa\n"
            "3 - Excluir tarefa\n"
    );
        
    scanf("%d", &op);
    switch (op)
    {
    case 0:
    // MENU INICIAL
        break;
    case 1:
        tarefas_editar(NILL);
        tarefas_top_id++;
        break;
    case 2:
        aux_id = tarefas_selecionar();
        tarefas_editar(aux_id);
        break;
    case 3:
        //TODO: EXCLUIR TAREFA
        printf("TODO!\n");
    default:
        break;
    }

    return;
}

void gerenciar_listas()
{
    int op;
    int aux_id;

        printf(
            "\nDigite uma opção:\n"
            "0 - SAIR\n"
            "1 - Adicionar lista\n"
            "2 - Editar lista\n"
            "3 - Excluir tarefa\n"
    );
        
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        // MENU INICIAL
        break;
    case 1:
        //ADICIONAR LISTA
        printf("Digite o nome da lista: ");
        fgets(listas_nome[listas_top_id], NOME_MAX_LEN, stdin);
        listas_top_id++;        
        break;
    case 2:
        //RENOMEAR LISTA
        aux_id = listas_selecionar();
        printf("Digite o nome da lista: ");
        fgets(listas_nome[aux_id], NOME_MAX_LEN, stdin);
        break;
    case 3:
        //TODO: EXCLUIR LISTA
        printf("TODO!\n");
        break;
    default:
        break;
    }

    return;
}

void filtros()
{
    //TODO: implementar os filtros
    printf("TODO!\n");
    return;
    

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
