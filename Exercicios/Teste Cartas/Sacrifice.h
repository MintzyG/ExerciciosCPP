#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

enum class Cor{

    BRANCO,
    PRETO,
    AMARELO,
    AZUL,
    VERMELHO,
    VERDE,
    ROXO,
    CINZA,
    VAZIO

};

enum class Animal{

    POLVO,
    CORUJA,
    ALCE,
    LOBO,
    BODE,
    URSO,
    VAZIO

};

enum class Tipo{

    MAO,
    INVENTARIO,
    TERRENO,
    VAZIO

};

enum class Forca{

    NORMAL,
    FORTE,
    ESPECIAL,
    VAZIO

};

enum class Numero{

    ZERO = 1,
    UM,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    VAZIO

};

struct Carta
{
    Cor CorCarta;
    Animal AnimalCarta;
    Tipo TipoCarta;
    Forca ForcaCarta;
    Numero NumeroCarta;

};

struct Deck
{
    Carta Baralho[60];  

    void InicializarDeck() {

        for (int cor = (int)Cor::BRANCO; cor <= (int)Cor::VERDE; cor++){
            for (int numeros = (int)Numero::ZERO; numeros <= (int)Numero::NOVE; numeros++){

                Carta cartas;
                
                cartas.CorCarta = (Cor)cor;
                cartas.NumeroCarta = (Numero)numeros;
                cartas.TipoCarta = Tipo::MAO;
                cartas.ForcaCarta = Forca::NORMAL;

                switch (cartas.CorCarta){
                case (Cor::BRANCO):
                    cartas.AnimalCarta = Animal::POLVO;
                    break;
                
                case (Cor::PRETO):
                    cartas.AnimalCarta = Animal::CORUJA;
                    break;
                
                case (Cor::AMARELO):
                    cartas.AnimalCarta = Animal::BODE;
                    break;

                case (Cor::AZUL):
                    cartas.AnimalCarta = Animal::LOBO;
                    break;

                case (Cor::VERMELHO):
                    cartas.AnimalCarta = Animal::URSO;
                    break;

                case (Cor::VERDE):
                    cartas.AnimalCarta = Animal::ALCE;
                    break;

                default:
                    cartas.AnimalCarta = Animal::VAZIO;
                    break;
                }

                int index = ((cor * 10) + numeros) - 1;
                Baralho[index] = cartas;
           }
        }
    }

    void PrintDeck(const Deck& deck) {

        for (int i = 0; i < 60; i++){

            switch (Baralho[i].NumeroCarta){

            case (Numero::ZERO):
                std::cout<<"Zero ";
                break;
                
            case (Numero::UM):
                std::cout<<"Um ";
                break;
                            
            case (Numero::DOIS):
                std::cout<<"Dois ";
                break;
                            
            case (Numero::TRES):
                std::cout<<"Tres ";
                break;
                            
            case (Numero::QUATRO):
                std::cout<<"Quatro ";
                break;
                            
            case (Numero::CINCO):
                std::cout<<"Cinco ";
                break;
                            
            case (Numero::SEIS):
                std::cout<<"Seis ";
                break;
                            
            case (Numero::SETE):
                std::cout<<"Sete ";
                break;
                            
            case (Numero::OITO):
                std::cout<<"Oito ";
                break;
                            
            case (Numero::NOVE):
                std::cout<<"Nove ";
                break;
                        
            default:
                std::cout<<"vazio";
                break;
            }

            switch (Baralho[i].CorCarta){

            case (Cor::BRANCO):
                std::cout<<"branco";
                break;

            case (Cor::PRETO):
                std::cout<<"preto";
                break;
            
            case (Cor::AMARELO):
                std::cout<<"amarelo";
                break;
            
            case (Cor::AZUL):
                std::cout<<"azul";
                break;
            
            case (Cor::VERMELHO):
                std::cout<<"vermelho";
                break;
            
            case (Cor::VERDE):
                std::cout<<"verde";
                break;
                        
            default:
                std::cout<<"vazio";
                break;
            }

            std::cout<<" do animal ";

            switch (Baralho[i].AnimalCarta){

            case (Animal::POLVO):
                std::cout<<"polvo";
                break;
                
            case (Animal::CORUJA):
                std::cout<<"coruja";
                break;
                            
            case (Animal::ALCE):
                std::cout<<"alce";
                break;
                            
            case (Animal::LOBO):
                std::cout<<"lobo";
                break;
                            
            case (Animal::BODE):
                std::cout<<"bode";
                break;
                            
            case (Animal::URSO):
                std::cout<<"urso";
                break;
                        
            default:
                std::cout<<"vazio";
                break;
            }

            std::cout<<" do tipo ";

            switch (Baralho[i].TipoCarta){

            case (Tipo::MAO):
                std::cout<<"Mao";
                break;

            case (Tipo::INVENTARIO):
                std::cout<<"Inventario";
                break;
            
            case (Tipo::TERRENO):
                std::cout<<"Terreno";
                break;
                        
            default:
                std::cout<<"Vazio";
                break;
            }

            std::cout<<" de forca ";

            switch (Baralho[i].ForcaCarta){

            case (Forca::NORMAL):
                std::cout<<"normal";
                break;
                
            case (Forca::FORTE):
                std::cout<<"forte";
                break;
                            
            case (Forca::ESPECIAL):
                std::cout<<"especial";
                break;
                        
            default:
                std::cout<<"vazio";
                break;
            }

            std::cout<<std::endl;

        }

    }

};

int main() {
Deck baralho;
baralho.InicializarDeck();
baralho.PrintDeck(baralho);

}