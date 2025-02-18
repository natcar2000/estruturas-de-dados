#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct Lista{
    No *inicio;
    No *fim;
} Lista;


void inserir(int valor, Lista *lista){
    No *no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    if(lista->inicio == NULL){
        lista->inicio = no;
        lista->fim = no;
    }
    else{
        no->anterior = lista->fim;
        lista->fim->proximo = no;
        lista->fim->anterior = no->anterior;
        lista->fim = no;
    }
}


void remover(Lista *lista){
    No *anterior =  NULL;
    No *inicio = lista->inicio;
    No *fim = lista->fim;
    lista->fim = lista->fim->anterior;
    lista->fim->proximo = NULL;
    while(inicio != lista->fim){
        anterior = inicio;
        inicio = inicio->proximo;
    }
    lista->fim->anterior = anterior;
    free(fim);
}


void imprimir(Lista *lista){
    No *inicio = lista->inicio;
    while(inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->proximo; 
    }
}


int main()
{
    Lista *lista;
    int opcao, valor;
    
    lista->inicio = NULL;
    lista->fim = NULL;
    
    do{
        printf("Escolha uma opção: 1 - Inserir 2 - Remover 3 - Imprimir: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Escolha um número: ");
                scanf("%d", &valor);
                inserir(valor, lista);
                break;
            case 2:
                remover(lista);
                break;
            case 3:
                imprimir(lista);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 4);
}