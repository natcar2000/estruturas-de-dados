#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *proximo;
} No;


typedef struct Fila{
    No *primeiro;
    No *ultimo;
} Fila;


void enfileirar(int valor, Fila *fila){
    No *no = (No*)malloc(sizeof(No));
    if(no){
        no->valor = valor;
        no->proximo = NULL;
        if(fila->primeiro == NULL){
            fila->primeiro = no;
            fila->ultimo = no;
        }
        else{
            fila->ultimo->proximo = no;
            fila->ultimo = no;
        }
    }
    else{
        printf("Erro na alocação de memória para o nó.\n");
    }
}


void imprimir(Fila *fila){
    if(fila->primeiro != NULL){
        No *primeiro = fila->primeiro;
        while(primeiro != NULL){
            printf("%d\n", primeiro->valor);
            primeiro = primeiro->proximo;
        }
    }
    else{
        printf("Não se pode imprimir uma fila vazia.\n");
    }
}


void desenfileirar(Fila *fila){
    if(fila->primeiro != NULL){
        No *primeiro = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;
        free(primeiro);
    }
    else{
        printf("A fila está vazia.\n");
    }
}


int main(){
    Fila *fila;
    int opcao, valor;
    
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    
    do{
        printf("Escolha uma opção: 1 - Inserir 2 - Remover 3 - Imprimir: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Escolha um número: ");
                scanf("%d", &valor);
                enfileirar(valor, fila);
                break;
            case 2:
                desenfileirar(fila);
                break;
            case 3:
                imprimir(fila);
                break;
        }
    } while(opcao != 0);
    return 0;
}
