/*
##################################################
Alunos: Lucas Viana, João Galhard, Kevin
Versão: 0.5
##################################################
*/

#include <stdio.h>
#include <string.h>

#define NOME_MAX_LEN 0x20
#define TAREFAS_MAX_LEN 0x40
#define LISTAS_MAX_LEN 0x40
#define NILL -1

enum status_m {
    EXCLUIDO,
    EM_ANDAMENTO,
    CONCLUIDO
};

enum prioridade_m{
    ALTA,
    MEDIA,
    BAIXA
};

char const PRIORIDADE[3][6] = {"ALTA", "MEDIA", "BAIXA"};
char const STATUS[3][13] = {"EXCLUIDO", "EM ANDAMENTO", "CONCLUIDO"};
int listas_top_id = 0;
char listas_nome[LISTAS_MAX_LEN][NOME_MAX_LEN];
int listas_status[LISTAS_MAX_LEN];

int tarefas_top_id = 0;
int tarefas_id[TAREFAS_MAX_LEN];
int tarefas_prioridade[TAREFAS_MAX_LEN];
char tarefas_nome[TAREFAS_MAX_LEN][NOME_MAX_LEN];
char tarefas_descricao[TAREFAS_MAX_LEN][280];
char tarefas_vencimento[TAREFAS_MAX_LEN][NOME_MAX_LEN];
int tarefas_status[TAREFAS_MAX_LEN];

int tarefas_listas[TAREFAS_MAX_LEN]; //Cria relação entre tarefas e listas

// Funções principais
void tarefas_editar(int); //Usado para criar tarefas se o argumento for NILL/-1
void gerenciar_tarefas();
void gerenciar_listas();
void filtros();

// Funções auxiliares
void tarefas_exibir();
int tarefas_gerar_id();
int tarefas_selecionar();

void listas_exibir();
int listas_selecionar();
int listas_gerar_id();

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
            op = 0;
            break;
        }

    } while (op);

    return 0;
}

int tarefas_gerar_id() {
    if (tarefas_top_id < TAREFAS_MAX_LEN - 1) {
        tarefas_top_id++;
        return tarefas_top_id;
    }

    //reciclando ids
    for (int i = 0; i < TAREFAS_MAX_LEN; i++) {
        if (tarefas_status[i] == EXCLUIDO) {
            tarefas_top_id = i;
            return tarefas_top_id;
        }
    }

    return NILL;
}

int listas_gerar_id() {
    if (listas_top_id < TAREFAS_MAX_LEN - 1) {
        listas_top_id++;
        return listas_top_id;
    }

    return NILL;
}

void tarefas_exibir()
{
    if (tarefas_top_id == 0)
        return;

    printf("ID |        NOME        | VENCIMENTO | PRIORIDADE |   STATUS   | DESCRIÇÃO\n");
    printf("--------------------------------------------------------------------------\n");

    for (int id = 0; id < tarefas_top_id; id++)
    {
        if (tarefas_status[id] == EXCLUIDO)
            continue;

        printf("%3d|%20s|%12s|%12s|%12s|%s\n", id, tarefas_nome[id], tarefas_vencimento[id], PRIORIDADE[tarefas_prioridade[id]], STATUS[tarefas_status[id]], tarefas_descricao[id]);
    }

    return;
}

int tarefas_selecionar(){
    int t = 0;

    do {
        printf("Selecione a tarefa: \n");
        tarefas_exibir();

        scanf("%d", &t);
    } while(t >= tarefas_top_id);

    return t;
}

void listas_exibir()
{
    printf("TAREFAS: \n");
    for (int id = 0; id < listas_top_id; id++)
    {
        if(listas_status[id] == EXCLUIDO)
            continue;

        printf("%d - %s\n", id, listas_nome[id]);
    }

    return;
}

int listas_selecionar(){
    int l = 0;

    do
    {
        printf("Selecione a tarefa: \n");
        listas_exibir();

        scanf("%d", &l);
    } while(l >= listas_top_id);

    return l;
}

void tarefas_editar(int sel)
{
    int id;

    if(sel == NILL){
        if(id == NILL)
        {
            printf("limite de tarefas atingido!\n");
            return;
        }

        id = tarefas_top_id;
    }
    else
    {
        id = sel;
    }
    
    getchar();
    printf("Digite o nome da tarefa: ");
    fgets(tarefas_nome[id], NOME_MAX_LEN, stdin);
    tarefas_nome[id][strcspn(tarefas_nome[id], "\n")] = '\0';

    printf("Digite a descrição da tarefa: ");
    fgets(tarefas_descricao[id], 280, stdin);
    tarefas_descricao[id][strcspn(tarefas_descricao[id], "\n")] = '\0';

    printf("Digite a data de vencimento da tarefa: ");
    fgets(tarefas_vencimento[id], NOME_MAX_LEN, stdin);
    tarefas_vencimento[id][strcspn(tarefas_vencimento[id], "\n")] = '\0';

    do {
        printf("Selecione a prioridade da tarefa: \n");
        printf("0 - ALTA\n");
        printf("1 - MEDIA\n");
        printf("2 - BAIXA\n");
        scanf("%d", &tarefas_prioridade[id]);
    } while((tarefas_prioridade[id] > 2) || (tarefas_prioridade[id] < 0));


    if (sel == NILL) {
        tarefas_status[id] = EM_ANDAMENTO;
        tarefas_gerar_id();
    }

    //TODO: registrar definir lembrete
    return;
}

//PRINCIPAIS
void gerenciar_tarefas()
{
    int op;
    int aux_id;

    printf(
            "\nSelecione uma opção:\n"
            "0 - SAIR\n"
            "1 - Adicionar tarefa\n"
            "2 - Editar tarefa\n"
            "3 - Marcar como concluida\n"
            "4 - Excluir tarefa\n"
    );
        
    scanf("%d", &op);
    switch (op)
    {
    case 0:
    // MENU INICIAL
        break;
    case 1:
        tarefas_editar(NILL); //Criar tarefa
        break;
    case 2:
        aux_id = tarefas_selecionar(); //Editar Tarefa
        tarefas_editar(aux_id);
        break;
    case 3:
        aux_id = tarefas_selecionar(); //Marcar como concluida
        tarefas_status[aux_id] = CONCLUIDO;
        break;
    case 4:
        aux_id = tarefas_selecionar();
        tarefas_status[aux_id] = EXCLUIDO;
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
    getchar();
    switch (op)
    {
    case 0:
        // MENU INICIAL
        break;
    case 1:
        //ADICIONAR LISTA
        if(listas_top_id == NILL)
        {
            printf("Limite de listas atingido!\n");
            break;
        }
        aux_id = listas_top_id;

        printf("Digite o nome da lista: ");
        fgets(listas_nome[aux_id], NOME_MAX_LEN, stdin);
        listas_nome[aux_id][strcspn(listas_nome[aux_id], "\n")] = '\0';
        listas_status[aux_id] = EM_ANDAMENTO;

        listas_gerar_id();

        break;
    case 2:
        //RENOMEAR LISTA
        aux_id = listas_selecionar();
        printf("Digite o nome da lista: ");
        fgets(listas_nome[aux_id], NOME_MAX_LEN, stdin);
        listas_nome[aux_id][strcspn(listas_nome[aux_id], "\n")] = '\0';
        break;
    case 3:
        aux_id = listas_selecionar();
        listas_status[aux_id] = EXCLUIDO;

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
