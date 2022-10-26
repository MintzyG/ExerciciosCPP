#include <iostream>

int main(){
    int i = 0;
    printf("Bem vindo a calculadora de Matrizes O que voce gostaria de fazer? \n");
    printf("1: Somar e Subtrair Matrizes \n");
    printf("2: Multiplicar Matrizes \n");
    printf("0: Sair do Programa \n");
    scanf("%d", &i);
    printf("%d", i);
    switch (i){
        case (1):
            printf("Voce somou matrizes");
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
        printf("teste");
}