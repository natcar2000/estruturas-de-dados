#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct Pilha{
    No *topo;
} Pilha;


void inserir(int valor, Pilha *pilha){
    No *no = (No*)malloc(sizeof(No));
    no->valor = valor;
    if(pilha->topo == NULL){
        no->proximo = NULL;
        pilha->topo = no;
    }
    else{
        no->proximo = pilha->topo;
        pilha->topo = no;
    }
}


void remover(Pilha *pilha){
    No *topo = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(topo);
}


void imprimir(Pilha *pilha){
    No *topo = pilha->topo;
    while(topo != NULL){
        printf("%d\n", topo->valor);
        topo = topo->proximo; 
    }
}


int main()
{
    Pilha *pilha;
    int opcao, valor;
    
    pilha->topo = NULL;
    
    do{
        printf("Escolha uma opção: 1 - Inserir 2 - Remover 3 - Imprimir: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Escolha um número: ");
                scanf("%d", &valor);
                inserir(valor, pilha);
                break;
            case 2:
                remover(pilha);
                break;
            case 3:
                imprimir(pilha);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 4);
}