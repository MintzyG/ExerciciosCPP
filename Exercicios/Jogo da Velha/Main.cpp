#include <iostream>

using namespace std;

void Escrever (int jogada[][3]){
    for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout<<"| ";
                if (jogada[i][j] == 0){
                    if(i == 0){
                        cout<<j+1;
                    }else if (i == 1){
                        cout<<(i+1)*2+(j+1)-1;
                    }else{
                        cout<<(i+1)*2+(j+1);
                    }
                }
                if (jogada[i][j] == 1){
                    cout<<"x";
                }
                if (jogada[i][j] == 2){
                    cout<<"o";
                }
            cout<<" |";
        }
        cout<<"\n";
    }

}

int Jogo (int jogador){
    
    int jogada[3][3];
    int coluna, linha, valido, lixo, ganhou;
    int jogo = 1;

    // Limpa a matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            jogada[i][j] = 0;
        }
    }
    
    
    // 1 = robo  // 2 = pessoa
    if  (jogador == 0){
        linha = rand() % 3;
        coluna = rand() % 3;
        jogada[linha][coluna] = 1;
        jogador = 1;
    }

    Escrever(jogada);

    while (jogo == 1){
        valido = 0;
        while (valido == 0){
            cout<<"\n"<<"\n";
            cout<<"Onde voce quer jogar?\n";
            cout<<"Linha: ";
            cin>>linha;
            linha = linha - 1;
            cout<<"Coluna: ";
            cin>>coluna;
            coluna = coluna - 1;
            if (jogada[linha][coluna] == 0){
                jogada[linha][coluna] = 2;
                valido = 1;
            }else{
                cout<<"Jogada Invalida";
            }
            jogador = 0;
        }

        if(ganhou == 1){
            return 0;
        }

        Escrever(jogada);
        for (int i = 0; i < 3; i++){
            if (jogada[i][0] == jogada[i][1] && jogada[i][2] == jogada[i][0] && jogada[i][0] != 0 && jogada[i][1] != 0 && jogada[i][2] != 0){
                if (jogada[i][0] != 0 && jogada[i][0] == 1){
                    cout<<"O computador ganhou!";
                    ganhou = 1;
                    return 0;
                }else{
                    cout<<"Voce ganhou!"; 
                    ganhou = 1;
                    return 0;
                }
                jogo = 0;
            }else if (jogada[0][i] == jogada[1][i] && jogada[2][i] == jogada[0][i] && jogada[0][i] != 0 && jogada[1][i] != 0 && jogada[2][i] != 0){
                if (jogada[0][i] != 0 && jogada[0][i] == 1){
                    cout<<"O computador ganhou!";
                    ganhou = 1;
                    return 0;
                }else{
                    cout<<"Voce ganhou!"; 
                    ganhou = 1;
                    return 0;
                }
                jogo = 0;
            }
        }
        if(jogada[1][1] != 0 && jogada[0][0] == jogada[1][1] && jogada[2][2] == jogada[0][0] || jogada[0][2] == jogada[1][1] && jogada[2][0] == jogada[0][2] ){
            if (jogada[1][1] != 0){
                if (jogada[1][1] == 1){
                    cout<<"O computador ganhou!";
                    ganhou = 1;
                    return 0;
                }else{
                    cout<<"Voce ganhou!"; 
                    ganhou = 1;
                    return 0;
                }
            jogo = 0;
            }
        }
        if (jogada[0][0] != 0 && jogada[0][1] != 0 && jogada[0][2] != 0 && jogada[1][0] != 0 && jogada[1][1] != 0 && jogada[1][2] != 0 && jogada[2][0] != 0 && jogada[2][1] != 0 && jogada[2][2] != 0){
            cout<<"Deu velha!";
            jogo = 0;
            ganhou = 1;
            return 0;
        }



        cout<<"\n Agora e o bot, digite um numero e de enter para prosseguir";
        cin>>lixo;

        if  (jogador == 0){
            valido = 0;  
            while (valido == 0){
                linha = rand() % 3;
                coluna = rand() % 3;
                if (jogada[linha][coluna] == 0){
                    jogada[linha][coluna] = 1;
                    valido = 1;
                }
                jogador = 1;
            }
        }

        cout<<"\n";
        Escrever(jogada);

    }
}




int main() {

int velha[3][3];
int chance, escolha, jogador;
srand(time(0));

while(escolha != -1){
    cout<<"Quem joga primeiro?\n"<<"1: Voce \n"<<"2: O computador \n"<<"3: sair \n";
    cin>>escolha;
    switch (escolha){
        case 1:
            jogador = 1;
            escolha = -1;
            break;

        case 2:
            jogador = 0;
            escolha = -1;
            break;

        case 3:
            cout<<"tchau!";
            return 0;
            break;

        default:
            cout<<"Erro!";
            break;
        }
}
Jogo(jogador);
return 0;
}
