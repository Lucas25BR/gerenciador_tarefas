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

listas_nome[LISTA_LEN];

int tarefas_id[TAREFAS_LEN];
int tarefas_prioridade[TAREFAS_LEN];
int tarefas_lista[TAREFAS_LEN];

char tarefas_nome[TAREFAS_LEN][STR_MAX_LEN];
char tarefas_data[TAREFAS_LEN][STR_MAX_LEN];


int main() {

    //MENU
    do {
        int sel[3];

        //EXIBIR LISTA DE TAREFAS
        printf("TAREFAS: \n");
        for (int id = 0; id < top_id; i++) {
            printf("%d - %s\n", id, tarefas_nome[id]);
        }
        //MENU DE OPÇÕES
        
        switch (sel[0]) {
        //SAIR
            case 0:
            break;
            case 1:
                //GERENCIAR TAREFAS
                switch (sel[1]) {
                    //MENU INCIAL
                    case 0:
                    break;
                    //CRIAR NOVA TAREFA
                    case 1:
                        switch (sel[2])
                        {
                            //MENU INICIAL
                            case 0:
                            break;
                    
                            default:
                            break;
                        }
                    break;
                    default:
                    break;        
                }
            break;
            case 2:
                //GERENCIAR LISTAS
                switch (sel[1]) {
                //MENU INICIAL
                    case 0:        
                    break;

                    default:
                    break;
                }
            break;
            case 3:
                //FILTROS
                switch (sel[1]) {
                //MENU INICIAL
                    case 0:            
                    break;                    
 
                    default:
                    break;
                }
            break;
                
            default:
            break;
        }
        
    } while(sel[0]);

return 0;
