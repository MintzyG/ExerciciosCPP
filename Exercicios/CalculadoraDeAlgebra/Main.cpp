#include <iostream>
#include <vector>
using namespace std;

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
    void printVector(vector<vector<int>>& MatEscreve){

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
        cout<<endl<<"Matriz visualizada: "<<endl<<endl;
        printVector(matrixInfo);
        cout<<endl<<endl;

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
    void userMultiply(vector<vector<int>>& MatrixMultiply){

        vector<vector<int>> MultiplyMatrix;
        vector<vector<int>> ReceptorMatrix;

        int linhas = MatrixMultiply[0].size();
        int colunas;
        int value = 0;

        cout<<"\nEspecifique a matrix que voce quer que multiplique a sua!";
        cout<<"\nA matriz multiplicadora tera "<<linhas<<" linhas";
        cout<<"\nQuantas colunas voce quer que a matriz multiplicadora tenha? ";
        cin>>colunas;
        userFillMatrix(MultiplyMatrix, linhas, colunas);

        info(MultiplyMatrix);

        for (int i = 0; i < MatrixMultiply.size(); i++){
            vector<int> v1;
            for (int j = 0; j < colunas; j++){
                for (int k = 0; k < linhas; k++){
                
                    value += MatrixMultiply[i][k] * MultiplyMatrix[k][j];

                }
                v1.push_back(value);
                value = 0;
            }
            ReceptorMatrix.push_back(v1);
        }

        MatrixMultiply.swap(ReceptorMatrix);

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
        cout<<endl<<"Sua matriz eh: "<<endl<<endl;
        printVector(inicial);
       
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
                    userMultiply(inicial);
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