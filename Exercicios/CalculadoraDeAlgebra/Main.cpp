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
        cout<<endl;
    }
    void userSum(vector<vector<int>>& MatrixSum){

        int choice = 0;
        int especifico;
        vector<vector<int>> sumMatrix;

        cout<<"\nSomar valor fixo ou uma matriz a sua matriz?";
        cout<<"\n1: Valor especifico para a matriz toda"<<"\n2: Uma matriz especifica\n";
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
    void determinant(vector<vector<int>> MatrixDeterminant){

        int diagonalP, diagonalP2, diagonalP3, diagonalS, diagonalS2, diagonalS3 = 1;
        int count = 1;
        diagonalP = diagonalP2 = diagonalP3 = diagonalS = diagonalS2 = diagonalS3 = 1;

        if ((MatrixDeterminant.size() == 2) && (MatrixDeterminant[0].size() == 2)){
            for (int i = 0; i < MatrixDeterminant.size(); i++){
                diagonalP *= MatrixDeterminant[i][i]; 
            }

            for (int i = 0; i < 2; i++){
                diagonalS *= MatrixDeterminant[i][count];
                count--;
            }

            cout<<endl<<"O determinante da matriz eh: "<<diagonalP - diagonalS<<endl;

        }else if ((MatrixDeterminant.size() == 3) && (MatrixDeterminant[0].size() == 3)){

            vector<vector<int>> Extendida;

            for (int i = 0; i < 3; i++){
                vector<int> V;
                for (int j = 0; j < 3; j++){
                    V.push_back(MatrixDeterminant[i][j]);
                }
                Extendida.push_back(V);    
            }

            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 2; j++){
                    Extendida[i].push_back(MatrixDeterminant[i][j]);
                }    
            }

            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){

                    if (j == 1){
                        diagonalP2 *= Extendida[i][j+i];
                        diagonalS2 *= Extendida[i][3-i];
                    }else if (j == 2){
                        diagonalP3 *= Extendida[i][j+i];
                        diagonalS3 *= Extendida[i][2-i];
                    }else{
                        diagonalP *= Extendida[i][i];
                        diagonalS *= Extendida[i][4-i];
                    }
                }
            }

            int determinante = diagonalP + diagonalP2 + diagonalP3 - diagonalS - diagonalS2 - diagonalS3;
            cout<<endl<<"O determinante da matriz eh: "<<determinante;            

        }
    }
    void transpose(vector<vector<int>>& TranposeMatrix){

        vector<vector<int>> Temp;

        for (int i = 0; i < TranposeMatrix[0].size(); i++){
            vector<int> V;
            for (int j = 0; j < TranposeMatrix.size(); j++){
                V.push_back(TranposeMatrix[j][i]);
            }
            Temp.push_back(V);
        }

        TranposeMatrix.swap(Temp);

    }

    int main(){
        int i;
        int linhas, colunas;
        vector<vector<int>> inicial;
        vector<vector<int>> operadora;

        cout<<"Bem vindo a calculadora de Matrizes\n"<<"Entre com uma matriz!\n";
        cout<<"Linhas: "; cin>>linhas;
        cout<<"Colunas: "; cin>>colunas;
        cout<<endl<<"Preencha sua matriz!"<<endl<<endl;
        userFillMatrix(inicial, linhas, colunas);
        cout<<endl<<"Sua matriz eh: "<<endl<<endl;
        printVector(inicial);
       
        while (true){
            cout<<"\n\nO que voce deseja fazer com sua matriz?\n";
            cout<<"1: Somar e Subtrair Matrizes "<<"\n2: Multiplicar Matrizes \n"<<"3: Visualizar Informacoes\n"<<
            "4: Calcular a determinante da matriz \n"<<"5: Transpor a matriz\n"<<"0: Sair do Programa "<<"Escolha: ";
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

                case (4):
                    determinant(inicial);
                    break;

                case (5):
                    transpose(inicial);
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