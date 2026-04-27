#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *proximo;
} No;


typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;


void enfileirar(int valor, Fila *fila);
void percorrer(Fila *fila);
void desenfileirar(Fila *fila);


void enfileirar(int valor, Fila *fila){
    No *no;
    no = (No *)malloc(sizeof(No));
    if (no) {
        no->valor = valor;
        no->proximo = NULL;
        if (fila->fim != NULL) {
            fila->fim->proximo = no;
        }
        else {
            fila->inicio = no;
        }
        fila->fim = no;
    }
    else {
        printf("Erro na alocação de memória.\n");
    }
}


void percorrer(Fila *fila){
    No *inicio;
    inicio = fila->inicio;
    if (inicio != NULL) {
        while (inicio != NULL) {
            printf("%d\n", inicio->valor);
            inicio = inicio->proximo;
        }
    }
    else {
        printf("Não é possível percorrer uma fila vazia.\n");
    }
}


void desenfileirar(Fila *fila){
    No *remover;
    remover = fila->inicio;
    if (remover != NULL) {
        if (fila->inicio->proximo != NULL) {
            fila->inicio = fila->inicio->proximo;
        }
        else {
            fila->inicio = NULL;
            fila->fim = NULL;
        }
        free(remover);
    }
    else {
        printf("Não é possível remover em uma fila vazia.\n");
    }
}


void limparFila(Fila *fila) {
    No *inicio, *temp;
    inicio = fila->inicio;
    if (inicio != NULL) {
        while (inicio != NULL) {
            temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        }
    }
    
    fila->inicio = NULL;
    fila->fim = NULL;
}


int main()
{
    int opcao, valor;
    
    Fila *fila;
    fila = (Fila *)malloc(sizeof(Fila));
    if (fila) {
        fila->inicio = NULL;
        fila->fim = NULL;
       
        do {
            printf("Digite uma opção: 0 - Sair 1 - Enfileirar 2 - Percorrer 3 - Desenfileirar: ");
            scanf("%d", &opcao);
            
            switch (opcao) {
                case 0:
                    break;
                case 1:
                    printf("Digite um valor para inserir: ");
                    scanf("%d", &valor);
                    enfileirar(valor, fila);
                    break;
                case 2:
                    percorrer(fila);
                    break;
                case 3:
                    desenfileirar(fila);
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
    
    limparFila(fila);
    free(fila);
    
    return 0;
}
