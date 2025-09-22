#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
} No;


typedef struct Lista{
    No *primeiro;
    No *ultimo;
} Lista;


void inserir(int valor, Lista *lista){
    No *no = (No*)malloc(sizeof(No));
    if(no){
        no->valor = valor;
        no->proximo = NULL;
        
        if(lista->primeiro == NULL){
            lista->primeiro = no;
            lista->ultimo = no;
        }
        else{
            No *ultimo = lista->ultimo;
            lista->ultimo->proximo = no;
            no->anterior = ultimo;
            lista->ultimo = no;
        }
    }
    else{
        printf("Erro na alocação de memória para o nó.\n");
    }
}


void imprimir(Lista *lista){
    if(lista->primeiro != NULL){
        No *primeiro = lista->primeiro;
        while(primeiro != NULL){
            printf("%d\n", primeiro->valor);
            primeiro = primeiro->proximo;
        }
    }
    else{
        printf("Não pode imprimir uma lista vazia.\n");
    }
}


void remover(Lista *lista){
    if(lista->primeiro == lista->ultimo){
        lista->primeiro = NULL;
        lista->ultimo = NULL;
    }
    else{
        No *anterior = NULL;
        No *ultimo = lista->ultimo;
        No *primeiro = lista->primeiro;
        lista->ultimo = lista->ultimo->anterior;
        lista->ultimo->proximo = NULL;
        while(primeiro != lista->ultimo){
            anterior = primeiro;
            primeiro = primeiro->proximo;
        }
        lista->ultimo->anterior = anterior;
    }
}


int main()
{
    Lista *lista;
    
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    
    int opcao, valor;
    do{
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite um número: ");
                scanf("%d", &valor);
                inserir(valor, lista);
                break;
            case 2:
                imprimir(lista);
                break;
            case 3:
                remover(lista);
                break;
        }
    } while(opcao != 0);
    return 0;
}
