#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *anterior;
} No;


typedef struct Pilha{
    No *topo;
} Pilha;


void empilhar(int valor, Pilha *pilha){
    No *no = (No*)malloc(sizeof(No));
    if(no){
        no->valor = valor;
        if(pilha->topo == NULL){
            pilha->topo = no;
        }
        else{
            no->anterior = pilha->topo;
            pilha->topo = no;
        }
    }
    else{
        printf("Erro na alocação de memória para o nó.\n");
    }
}


void imprimir(Pilha *pilha){
    if(pilha->topo != NULL){
        No *topo = pilha->topo;
        while(topo != NULL){
            printf("%d\n", topo->valor);
            topo = topo->anterior;
        }
    }
    else{
        printf("Não se pode imprimir uma pilha vazia.\n");
    }
}


void desempilhar(Pilha *pilha){
    if(pilha->topo != NULL){
        No *topo = pilha->topo;
        pilha->topo = pilha->topo->anterior;
        free(topo);
    }
    else{
        printf("A pilha está vazia.\n");
    }
}


int main(){
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
                empilhar(valor, pilha);
                break;
            case 2:
                desempilhar(pilha);
                break;
            case 3:
                imprimir(pilha);
                break;
        }
    } while(opcao != 0);
    return 0;
}
