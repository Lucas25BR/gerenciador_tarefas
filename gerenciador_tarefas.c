#include <stdio.h>

#define STR_MAX_LEN 0x20
#define TAREFAS_LEN 0x40

lista_nome[64];

int tarefa_id[TAREFAS_LEN];
int tarefa_prioridade[TAREFAS_LEN];
int tarefa_lista[TAREFAS_LEN];

char tarefa_nome[TAREFAS_LEN][STR_MAX_LEN];
char tarefa_data[TAREFAS_LEN][STR_MAX_LEN];


int main() {

    //MENU
    do{
        int sel[3];

        //EXIBIR LISTA DE TAREFAS
        {}
        //MENU DE OPÇÕES
        
        switch (sel[0]){
        //SAIR
        case 0:
            break;
        case 1:
            //GERENCIAR TAREFAS
            switch (sel[1]) {
            //MENU INCIAL
            case 0:
                break;
                
            case 1:
                //CRIAR NOVA TAREFA
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
}