#include <iostream>
#include <stdlib.h>
using namespace std;

    void somar(int n, int m){

    int valor = 0;

    int Matriz[n][m];
    int Matriz2[n][m];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            valor += 1;
            cout<<"Digite o valor "<< valor <<" da matriz 1: ";
            cin>>Matriz[i][j];
        }
    }

    cout<<"\n";

    valor = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            valor += 1;
            cout<<"Digite o valor "<< valor <<" da matriz 2: ";
            cin>>Matriz2[i][j];
        }
    }

    cout<<"\n";

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout<<Matriz[i][j] + Matriz2[i][j] << " ";
        }
        cout<<"\n";
    }

    }
    void multiplicar(int lm1, int cm1, int lm2, int cm2){
    int valor = 0;

    int mat1[lm1][cm1];
    int mat2[lm2][cm2];
    int receptor[lm1][cm2];

    for (int i = 0; i < lm1; i++){
        for (int j = 0; j < cm1; j++){
            valor += 1;
            cout<<"Digite o valor "<< valor <<" da matriz 1: ";
            cin>>mat1[i][j];
        }
    }

    valor = 0;
    for (int i = 0; i < lm2; i++){
        for (int j = 0; j < cm2; j++){
            valor += 1;
            cout<<"Digite o valor "<< valor <<" da matriz 2: ";
            cin>>mat2[i][j];
        }
    }

    cout<<"\n";

        // dessa parte pra frente de multi nao funfa
        for (int i = 0; i < lm1; i++){
            for (int j = 0; j < cm2; j++){
                for (int k = 0; k < lm2; k++){
                    receptor[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        for (int i = 0; i < lm1; i++){
            for (int j = 0; j < cm2; j++){
                cout<<receptor[i][j] << " ";
            }    
            cout<<"\n";
        }


    }

    int main(){
        int i, linhasMat1, linhasMat2, colMat1, colMat2, r;
        cout<<"Bem vindo a calculadora de Matrizes O que voce gostaria de fazer? \n";
        while (true){
            cout<<"1: Somar e Subtrair Matrizes \n";
            cout<<"2: Multiplicar Matrizes \n";
            cout<<"0: Sair do Programa \n";
            cin>>i;
            switch (i){
                case (1):
                    cout<<"\nQual e a dimensao das matrizes a serem somadas? \n";
                    cout<<"Quantidade de Colunas: ";
                    cin>>colMat1;
                    cout<<"Quantidade de Linhas: ";
                    cin>>linhasMat1;
                    somar(colMat1, linhasMat1);
                    break;
                
                case (2):
                    r = 0;
                    while (r == 0){
                        cout<<"\nQual e a dimensao das matrizes a serem multiplicadas? \n";
                        cout<<"Quantidade de Linhas da Matriz 1: ";
                        cin>>linhasMat1;
                        cout<<"Quantidade de Colunas da Matriz 1: ";
                        cin>>colMat1;
                        cout<<"Quantidade de Linhas da Matriz 2: ";
                        cin>>linhasMat2;
                        cout<<"Quantidade de Colunas da Matriz 2: ";
                        cin>>colMat2;
                        if (colMat1 == linhasMat2){
                            r = 1;
                            multiplicar(linhasMat1, colMat1, linhasMat2, colMat2);
                            
                        } else {
                            cout<<"O numero de colunas da primeira matriz deve equivaler ao numero de linhas da segunda matriz";
                        }
                    }
                    break;

                case (0):
                    cout<<"Tchau!";
                    return 0;
                    break;

                default:
                    cout<<"Erro!";
                    break;
            } 
        }
    }