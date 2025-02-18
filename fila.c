#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct Fila{
    struct No *fim;
    struct No *inicio;
} Fila;


void inserir(int valor, Fila *fila){
    No *no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    if(fila->inicio == NULL){
        fila->fim = no;
        fila->inicio = no;
    }
    else{
        fila->fim->proximo = no;
        fila->fim = no;
    }
}


void remover(Fila *fila){
    No *aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(aux);
};


void imprimir(Fila *fila){
    No *inicio = fila->inicio;
    while(inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->proximo; 
    }
};


int main()
{
    Fila *fila;
    int opcao, valor;
    
    fila->inicio = NULL;
    fila->fim = NULL;
    
    do{
        printf("Escolha uma opção: 1 - Inserir 2 - Remover 3 - Imprimir: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Escolha um número: ");
                scanf("%d", &valor);
                inserir(valor, fila);
                break;
            case 2:
                remover(fila);
                break;
            case 3:
                imprimir(fila);
                break;
            default:
                printf("Opção inválida!");
                break;
        }
    } while(opcao != 4);
}