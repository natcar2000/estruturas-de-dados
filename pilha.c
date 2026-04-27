#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *anterior;
} No;


typedef struct Pilha {
    No *topo;
} Pilha;


void empilhar(int valor, Pilha *pilha);
void percorrer(Pilha *pilha);
void desempilhar(Pilha *pilha);


void empilhar(int valor, Pilha *pilha) {
    No *no;
    no = (No *)malloc(sizeof(No));
    if (no) {
        no->valor = valor;
        if (pilha->topo != NULL) {
            no->anterior = pilha->topo;
        }
        else {
            no->anterior = NULL;
        }
        pilha->topo = no;
    }
    else {
        printf("Erro na alocação de memória.\n");
    }
}


void percorrer(Pilha *pilha){
    No *topo;
    topo = pilha->topo;
    if (topo != NULL) {
        while (topo != NULL) {
            printf("%d\n", topo->valor);
            topo = topo->anterior;
        }
    }
    else {
        printf("Não é possível percorrer uma pilha vazia.\n");
    }
}


void desempilhar(Pilha *pilha){
    No *remover;
    remover = pilha->topo;
    if (remover != NULL) {
        if (pilha->topo->anterior != NULL) {
            pilha->topo = pilha->topo->anterior;
        }
        else {
            pilha->topo = NULL;
        }
        free(remover);
    }
    else {
        printf("Não é possível remover em uma pilha vazia.\n");
    }
}


void limparPilha(Pilha *pilha) {
    No *topo, *temp;
    topo = pilha->topo;
    if (topo != NULL) {
        while (topo != NULL) {
            temp = topo;
            topo = topo->anterior;
            free(temp);
        }
    }
    
    pilha->topo = NULL;
}


int main()
{
    int opcao, valor;
    
    Pilha *pilha;
    pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha) {
        pilha->topo = NULL;
       
        do {
            printf("Digite uma opção: 0 - Sair 1 - Empilhar 2 - Percorrer 3 - Desempilhar: ");
            scanf("%d", &opcao);
            
            switch (opcao) {
                case 0:
                    break;
                case 1:
                    printf("Digite um valor para inserir: ");
                    scanf("%d", &valor);
                    empilhar(valor, pilha);
                    break;
                case 2:
                    percorrer(pilha);
                    break;
                case 3:
                    desempilhar(pilha);
                    break;
                default:
                    printf("opção inválida.\n");
                    break;
            }
        } while (opcao != 0);
    } 
    else {
        printf("Erro na alocação de memória.\n");
    }
    
    limparPilha(pilha);
    free(pilha);
    
    return 0;
}
