#include <iostream>
#include <cmath>

void somar(int n, int m){

int valor = 0;

int Matriz[n][m];
int Matriz2[n][m];

for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
        valor += 1;
        printf("Digite o valor %d da matriz 1: ", valor);
        scanf("%d", &Matriz[i][j]);
    }
}

printf("\n");

valor = 0;
for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
        valor += 1;
        printf("Digite o valor %d da matriz 2: ", valor);
        scanf("%d", &Matriz2[i][j]);
    }
}

printf("\n");

for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
        printf("%d ", Matriz[i][j] + Matriz2[i][j]);
    }
    printf("\n");
}

}

void multiplicar(int lm1, int cm1, int lm2, int cm2){
int valor = 0;

int mat1[lm1][cm1];
int mat2[lm2][cm2];

for (int i = 0; i < lm1; i++){
    for (int j = 0; j < cm1; j++){
        valor += 1;
        printf("Digite o valor %d da matriz 1: ", valor);
        scanf("%d", &mat1[lm1][cm1]);
    }
}

valor = 0;
for (int i = 0; i < lm2; i++){
    for (int j = 0; j < cm2; j++){
        valor += 1;
        printf("Digite o valor %d da matriz 2: ", valor);
        scanf("%d", &mat2[lm2][cm2]);
    }
}

    // Onde acontecera a multiplicação

}

int main(){
    int i, linhasMat1, linhasMat2, colMat1, colMat2, r;
    printf("Bem vindo a calculadora de Matrizes O que voce gostaria de fazer? \n");
    while (true){
        printf("1: Somar e Subtrair Matrizes \n");
        printf("2: Multiplicar Matrizes \n");
        printf("0: Sair do Programa \n");
        scanf("%d", &i);
        switch (i){
            case (1):
                printf("\nQual e a dimensao das matrizes a serem somadas? \n");
                printf("Quantidade de Colunas: ");
                scanf("%d", &colMat1);
                printf("Quantidade de Linhas: ");
                scanf("%d", &linhasMat1);
                somar(colMat1, linhasMat1);
                break;
            
            case (2):
                r = 0;
                while (r == 0){
                    printf("\nQual e a dimensao das matrizes a serem multiplicadas?");
                    printf("Quantidade de Linhas da Matriz 1: ");
                    scanf("%d", &linhasMat1);
                    printf("Quantidade de Colunas da Matriz 1: ");
                    scanf("%d", &colMat1);
                    printf("Quantidade de Linhas da Matriz 2: ");
                    scanf("%d", &linhasMat2);
                    printf("Quantidade de Colunas da Matriz 2: ");
                    scanf("%d", &colMat2);
                    if (colMat1 == linhasMat2){
                        r = 1;
                        multiplicar(linhasMat1, colMat1, linhasMat2, colMat2);
                        
                    } else {
                        printf("O numero de colunas da primeira matriz deve equivaler ao numero de linhas da segunda matriz");
                    }
                }
                break;
            case (0):
                printf("Tchau!");
                return 0;
                break;

            default:
                printf("Erro!");
                break;
        } 
    }
}


teste
