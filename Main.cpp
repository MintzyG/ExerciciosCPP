#include <iostream>
#include <cmath>

void Somar(int n, int m){

int valor = 0;

int Matriz2[n][m];
int Matriz[n][m];
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
            printf("\nQual e a dimensao das matrizes a serem somadas? \n");
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

