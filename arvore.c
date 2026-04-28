#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *primeiro_filho;
    struct No *proximo_irmao;
} No;


typedef struct Arvore {
    No *raiz;
} Arvore;


void inserir_na_raiz(int valor, Arvore *arvore);
void inserir(int valor, int chave, Arvore *arvore);
No *buscar(int chave, No *raiz);
No *buscar_pai(int chave, No *raiz);
void remover(int chave, No *raiz);
void liberarSubarvore(No *no);
void percorrer(No *raiz);


void inserir_na_raiz(int valor, Arvore *arvore) {
    No *no;
    no = (No *)malloc(sizeof(No));
    if (no) {
        no->valor = valor;
        no->primeiro_filho = NULL;
        no->proximo_irmao = NULL;
        arvore->raiz = no;
    }
    else {
        printf("Erro na alocação de memória.\n");
    }
}


void inserir(int valor, int chave, Arvore *arvore) {
    No *no, *busca, *atual, *filho;
    no = (No *)malloc(sizeof(No));
    if (no) {
        no->valor = valor;
        no->primeiro_filho = NULL;
        no->proximo_irmao = NULL;
        if (arvore->raiz != NULL) {
            busca = buscar(chave, arvore->raiz);
            if (busca != NULL) {
                if(busca->primeiro_filho != NULL) {
                    atual = busca->primeiro_filho;
                    while (atual->proximo_irmao != NULL) {
                        atual = atual->proximo_irmao;
                    }
                    atual->proximo_irmao = no;
                }
                else {
                    busca->primeiro_filho = no;
                }
            }
            else {
                printf("Chave não encontrada.\n");
                free(no);
            }
        }
    }
    else {
        printf("Erro na alocação de memória.\n");
    }
}


No *buscar(int chave, No *raiz) {
    No *resultado;
    if (raiz != NULL) {
        if (raiz->valor == chave) {
            return raiz;
        }
        else {
            resultado = buscar(chave, raiz->primeiro_filho);
            if (resultado != NULL) {
                return resultado;
            }
            else {
                return buscar(chave, raiz->proximo_irmao);
            }
        }
    }
    else {
        return NULL;
    }
}


void percorrer(No *raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->valor);
        percorrer(raiz->primeiro_filho);
        percorrer(raiz->proximo_irmao);
    }
}


No *buscar_pai(int chave, No *raiz) {
    No *filho, *resultado;
    if (raiz != NULL) {
        filho = raiz->primeiro_filho;
        while (filho != NULL) {
            if (filho->valor == chave) {
                return raiz;
            }
            resultado = buscar_pai(chave, filho);
            if (resultado != NULL) {
                return resultado;
            }
            else {
                filho = filho->proximo_irmao;
            }
        }
    }
    else {
        return NULL;
    }
}


void liberarSubarvore(No *no) {
    No *filho, *aux;
    if (no == NULL){
        return;
    }
    else {
       filho = no->primeiro_filho;
       if (filho != NULL) {
           while (filho != NULL) {
                aux = filho->proximo_irmao;
                liberarSubarvore(filho);
                filho = aux;
           }
       }
       free(no);
    }
}


void remover(int chave, No *raiz) {
    No *pai, *remover, *atual, *filho;
    if (raiz != NULL) {
        if (chave == raiz->valor) {
            printf("Não é permitido remover a raiz.\n");
            return;
        }
        else {
            pai = buscar_pai(chave, raiz);
            remover = buscar(chave, raiz);
            if (pai != NULL && remover != NULL) {
                if (remover == pai->primeiro_filho) {
                    pai->primeiro_filho = remover->proximo_irmao;
                }
                else {
                    atual = pai->primeiro_filho;
                    while (atual != NULL && atual->proximo_irmao != remover) {
                        atual = atual->proximo_irmao;
                    }
                    if (atual != NULL) {
                        atual->proximo_irmao = remover->proximo_irmao;
                    }
                }
                liberarSubarvore(remover);
            }
            else {
                printf("Chave não encontrada.\n");
                return;
            }
        }
    }
}


int main()
{
    int opcao, valor, chave;
    Arvore *arvore;
    arvore = (Arvore *)malloc(sizeof(Arvore));
    if (arvore) {
        arvore->raiz = NULL;
        do {
            printf("Digite uma opção: 0 - Sair 1 - Inserir 2 - Percorrer 3 - Remover: ");
            scanf("%d", &opcao);
            
            switch (opcao) {
                case 0:
                    break;
                case 1:
                    printf("Valor a inserir: ");
                    scanf("%d", &valor);
                    if (arvore->raiz == NULL) { 
                        inserir_na_raiz(valor, arvore);
                    }
                    else {
                        printf("Digite a chave de busca para inserção: ");
                        scanf("%d", &chave);
                        inserir(valor, chave, arvore);
                    }
                    break;
                case 2:
                    percorrer(arvore->raiz);
                    break;
                case 3:
                    printf("Chave de busca para remoção: ");
                    scanf("%d", &chave);
                    remover(chave, arvore->raiz);
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
            }
            
        }  while (opcao != 0);
    }
    else {
        printf("Erro na alocação de memória.\n");
    }
    
    liberarSubarvore(arvore->raiz);
    return 0;
}
