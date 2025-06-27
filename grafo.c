#include <stdio.h>


void consultar(int origem, int destino){
    if(origem == 0 && destino == 0 || origem == 1 && destino == 1 || origem == 2 && destino == 2){
        printf("O destino não pode ser igual à origem.\n");
    }
    else if(origem == 0 && destino == 1 || origem == 1 && destino == 0){
        printf("Paraná faz fronteira com Santa Catarina.\n");
    }
    else if(origem == 0 && destino == 2 || origem == 2 && destino == 0){
        printf("Paraná não faz fronteira com Rio Grande do Sul.\n");
    }
    else if(origem == 1 && destino == 2 || origem == 2 && destino == 1){
        printf("Santa Catarina faz fronteira com Rio Grande do Sul.\n");
    }
    else{
        printf("Origem ou destino inválido");
    }
}


int main(){
    int opcao, origem, destino, regiao_sul[3][3];
    regiao_sul[0][0] = 0;
    regiao_sul[0][1] = 1;
    regiao_sul[0][2] = 0;
    regiao_sul[1][0] = 1;
    regiao_sul[1][1] = 0;
    regiao_sul[1][2] = 1;
    regiao_sul[2][0] = 0;
    regiao_sul[2][1] = 1;
    regiao_sul[2][2] = 0;
    
    do{
        printf("Digite uma opção - [1] Consultar [2] Encerrar: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Digite o número da origem - [0] Paraná [1] Santa Catarina [2] Rio Grande do Sul: ");
                scanf("%d", &origem);
                printf("Digite o número do destino - [0] Paraná [1] Santa Catarina [2] Rio Grande do Sul: ");
                scanf("%d", &destino);
                consultar(origem, destino);
                break;
            case 2:
                break;
        }
        
    } while(opcao != 2);
    
    return 0;
}
