#include <iostream>
#include <cmath>

void Somar(int n, int m){

int Matriz[n][m];
for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
        printf("%d", j);
        Matriz[i][j] = i + j + 1;
    }
    printf("%d", i);
}

printf("\n");

for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
        printf("%d  ", Matriz[i][j]);
    }
    printf("\n");
}

}

int main(){
    int i, m, n = 0;
    printf("Bem vindo a calculadora de Matrizes O que voce gostaria de fazer? \n");
    printf("1: Somar e Subtrair Matrizes \n");
    printf("2: Multiplicar Matrizes \n");
    printf("0: Sair do Programa \n");
    scanf("%d", &i);
    printf("%d", i);
    switch (i){
        case (1):
            printf("Qual e a dimensao das matrizes a serem somadas? \n");
            printf("Quantidade de Colunas: ");
            scanf("%d", &n);
            printf("Quantidade de Linhas: ");
            scanf("%d", &m);
            Somar(n, m);
            break;
        
        case (2):
            printf("Voce multiplicou matrizes");
            break;
        case (0):
            printf("0");
            break;

        default:
            break;
        } 
}

