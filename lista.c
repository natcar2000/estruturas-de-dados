#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *proximo;
    struct No *anterior;
} No;


typedef struct Lista {
    No *inicio;
    No *fim;
} Lista;


void inserir(int valor, Lista *lista);
void percorrer(Lista *lista);
void remover(Lista *lista);


void inserir(int valor, Lista *lista){
    No *no;
    no = (No *)malloc(sizeof(No));
    if (no) {
        no->valor = valor;
        no->proximo = NULL;
        no->anterior = lista->fim;
        if (lista->inicio != NULL) {
            lista->fim->proximo = no;
        }
        else {
            lista->inicio = no;
        }
        lista->fim = no;
    }
    else {
        printf("Erro na alocação de memória.\n");
    }
}


void percorrer(Lista *lista){
    No *inicio;
    inicio = lista->inicio;
    if (inicio != NULL) {
        while (inicio != NULL) {
            printf("%d\n", inicio->valor);
            inicio = inicio->proximo;
        }
    }
    else {
        printf("Não é possível percorrer uma lista vazia.\n");
    }
}


void remover(Lista *lista){
    No *remover;
    remover = lista->fim;
    if (remover != NULL) {
        if (lista->fim->anterior != NULL) {
            lista->fim = lista->fim->anterior;
            lista->fim->proximo = NULL;
        }
        else {
            lista->inicio = NULL;
            lista->fim = NULL;
        }
        free(remover);
    }
    else {
        printf("Não é possível remover em uma lista vazia.\n");
    }
}


void limparLista(Lista *lista) {
    No *inicio, *temp;
    inicio = lista->inicio;
    if (inicio != NULL) {
        while (inicio != NULL) {
            temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        }
    }
    
    lista->inicio = NULL;
    lista->fim = NULL;
}


int main()
{
    int opcao, valor;
    
    Lista *lista;
    lista = (Lista *)malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
       
        do {
            printf("Digite uma opção: 0 - Sair 1 - Inserir 2 - Percorrer 3 - Remover: ");
            scanf("%d", &opcao);
            
            switch (opcao) {
                case 0:
                    break;
                case 1:
                    printf("Digite um valor para inserir: ");
                    scanf("%d", &valor);
                    inserir(valor, lista);
                    break;
                case 2:
                    percorrer(lista);
                    break;
                case 3:
                    remover(lista);
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
    
    limparLista(lista);
    free(lista);
    
    return 0;
}
