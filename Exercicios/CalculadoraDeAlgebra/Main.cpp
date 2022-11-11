#include <iostream>
#include <vector>
using namespace std;

    /* pra relmebrar como modifica vetores caso necessario abrir aqui <
    void modificaVetor(vector<vector<int>>& ModVetor){ 

        for (int i = 0; i < ModVetor.size(); i++){
            for (int j = 0; j < ModVetor[i].size(); j++){
                ModVetor[i][j] += 1;
            }
        }

    }
    */

    void userFillMatrix(vector<vector<int>>& MatPreencher, int linhas, int colunas){

        int lugar = 0;
        int input;
        for (int i = 0; i < linhas; i++){
            vector<int> v1;
            for (int j = 0; j < colunas; j++){
                lugar += 1;
                cout<<"valor "<< lugar <<" da matriz: ";
                cin>>input;
                v1.push_back(input);
            }
            MatPreencher.push_back(v1);
        }

        cout<<endl<<endl;

    }
    void escrevaVetor(vector<vector<int>>& MatEscreve){

        for (vector<int> v1 : MatEscreve){
            for (int x : v1){

                cout<< x << "  ";

            }
            cout<<endl;
        }
        cout<<endl;
    }
    void info(vector<vector<int>> matrixInfo){

        cout<<"\n\nInformacao sobre a matriz";
        cout<<"\nQuantidade de linhas: "<<matrixInfo.size();
        cout<<"\nQuantidade de colunas: "<<matrixInfo[0].size();
        cout<<"\nA matriz esta vazia? ";
            if (matrixInfo.empty() == 0){
                cout<<"False";
            }else{
                cout<<"True";
            }
        cout<<endl;
        cout<<"Matriz visualizada: ";
        cout<<endl;
        cout<<endl;
        escrevaVetor(matrixInfo);
        cout<<endl;
        cout<<endl;

    }
    void userSum(vector<vector<int>>& MatrixSum){

        int choice = 0;
        int especifico;
        vector<vector<int>> sumMatrix;

        cout<<"\nSomar valor fixo ou uma matriz a sua matriz?";
        cout<<"\n1: Valor especifico para a matriz toda";
        cout<<"\n2: Uma matriz especifica\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            
            cout<<"\nQual valor voce quer adicionar a sua matriz?\n";
            cin>>especifico;
            
            for (int i = 0; i < MatrixSum.size(); i++){
                for (int j = 0; j < MatrixSum[i].size(); j++){
                    MatrixSum[i][j] += especifico;
                }
            }
            break;
        
        case 2:

            cout<<"\nPreencha a matriz que vai ser adicionada a sua\n";
            userFillMatrix(sumMatrix, MatrixSum.size(), MatrixSum[0].size());

            for (int i = 0; i < MatrixSum.size(); i++){
                for (int j = 0; j < MatrixSum[i].size(); j++){
                    MatrixSum[i][j] += sumMatrix[i][j];
                }
            }


        default:
            break;
        }



    }

    void somar(int n, int m){

    int valor = 0;

    int Matriz[n][m];
    int Matriz2[n][m];
    int Resultante[n][m];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            Resultante[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            valor += 1;
            cout<<"Digite o valor "<< valor <<" da matriz 1: ";
            cin>>Matriz[i][j];
        }
    }

    cout<<"\n";

    valor = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            valor += 1;
            cout<<"Digite o valor "<< valor <<" da matriz 2: ";
            cin>>Matriz2[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            Resultante[i][j] = Matriz[i][j] + Matriz2[i][j];
        }
    }

    cout<<"\nResultado:\n";

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<Resultante[i][j]<<" ";
        }
        cout<<endl;
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

        for (int i = 0; i < lm1; i++){
            for (int j = 0; j < cm2; j++){
                receptor[i][j] = 0;
            }
        }

        for (int i = 0; i < lm1; i++){
            for (int j = 0; j < cm2; j++){
                for (int k = 0; k < cm1; k++){
                    receptor[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

    cout<<"Resultado:\n";
        for (int i = 0; i < lm1; i++){
            for (int j = 0; j < cm2; j++){
                cout<<receptor[i][j] << " ";
            }    
            cout<<"\n";
        }
    cout<<"\n";

    }
    void fazerCalculo(int Tipo){
        cout<<"\nMonte suas matrizes \n";

        int linhasM1, linhasM2, colunasM1, colunasM2;
        bool seguir;
        switch (Tipo)
        {
        case 1:
            // Somar
            cout<<"\nDimensoes das matrizes para soma:\n";
            cout<<"Quantidade de linhas: ";
            cin>>linhasM1;
            cout<<"Quantidade de colunas: ";
            cin>>colunasM1;
            somar(linhasM1, colunasM1);
            break;
        case 2:
            // Multiplicar
            cout<<"\nDimensoes para as matrizes da multiplicacao:\n\n";
            seguir = false;
            while (seguir == false)
            {
                cout<<"Linhas da Matriz 1: ";
                cin>>linhasM1;
                cout<<"Colunas da Matriz 1: ";       
                cin>>colunasM1;
                cout<<"Linhas da Matriz 2: ";
                cin>>linhasM2;
                cout<<"Colunas da Matriz 2: ";       
                cin>>colunasM2;
                if (colunasM1 == linhasM2){
                    seguir = true;
                }else if (colunasM1 != linhasM2 || linhasM1 < 1 || linhasM2 < 1 || colunasM1 < 1 || colunasM2 < 1){
                    cout<<"\nDimensoes invalidas:\nPara que as matrizes sejam multiplicaveis as Colunas da matriz 1 devem equivaler as Linhas da matriz 2\nTente Novamente\n";
                }
            }
            cout<<"\n";
            multiplicar(linhasM1, colunasM1, linhasM2, colunasM2);
            break;
            
        default:
            cout<<"Erro!";
            break;
        }

    }

    int main(){
        int i;
        int linhas, colunas;
        vector<vector<int>> inicial;
        vector<vector<int>> operadora;

        cout<<"Bem vindo a calculadora de Matrizes\n";
        cout<<"Entre com uma matriz!\n";
        cout<<"Linhas: "; cin>>linhas;
        cout<<"Colunas: "; cin>>colunas;
        cout<<endl<<"Preencha sua matriz!"<<endl<<endl;
        userFillMatrix(inicial, linhas, colunas);
        cout<<endl;
        cout<<"Sua matriz eh: "<<endl<<endl;
        escrevaVetor(inicial);
       
        while (true){
            cout<<"O que voce deseja fazer com sua matriz?\n";
            cout<<"1: Somar e Subtrair Matrizes \n";
            cout<<"2: Multiplicar Matrizes \n";
            cout<<"3: Informacao\n";
            cout<<"0: Sair do Programa \n";
            cout<<"Escolha: ";
            cin>>i;
            switch (i){
                case (1):
                    userSum(inicial);
                    break;
                
                case (2):
                    fazerCalculo(2);
                    break;

                case (3):
                    info(inicial);
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