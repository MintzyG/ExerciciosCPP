#include <iostream>

enum class Suits{

    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,

};

enum class CardNames{

    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,

};

struct Card{

    CardNames name;
    Suits suit;
    int value;

    void PrintCard(){
        
        PrintName();
        std::cout<<" of ";
        PrintSuit();

        std::cout<<std::endl;

    }

    void PrintName(){

        if (name == CardNames::JACK){
            std::cout<<"Jack";
        }else if (name == CardNames::QUEEN){
            std::cout<<"Queen";
        }else if (name == CardNames::KING){
            std::cout<<"King";
        }else if (name == CardNames::ACE){
            std::cout<<"Ace";
        }else{
            std::cout<<value;
        }

    }

    void PrintSuit(){
        if (suit == Suits::CLUBS){
            std::cout<<"Clubs";
        } else if (suit == Suits::DIAMONDS){
            std::cout<<"Diamonds";
        } else if (suit == Suits::HEARTS){
            std::cout<<"Hearts";
        } else if (suit == Suits::SPADES){
            std::cout<<"Spades";
        }
    }

};

struct Deck{

    Card arrCards[52];

    void PrintAll(){
       
        for (int Linha = (int)Suits::CLUBS; Linha <= (int)Suits::SPADES; Linha++){
            for (int Coluna = (int)CardNames::ACE; Coluna <= (int)CardNames::KING; Coluna++){
                
                int index = ((13 * Linha) + Coluna) - 1 ;
                arrCards[index].PrintCard();

            }
            std::cout<<std::endl;
        }
    }



    void SetupCards(){

        for (int Linha = (int)Suits::CLUBS; Linha <= (int)Suits::SPADES; Linha++){
            for (int Coluna = (int)CardNames::ACE; Coluna <= (int)CardNames::KING; Coluna++){

                Card card;
                card.suit = (Suits)Linha;
                card.name = (CardNames)Coluna;

                if (card.name == CardNames::JACK){
                    card.value = 10;
                } else if (card.name == CardNames::QUEEN){
                    card.value = 10;
                } else if (card.name == CardNames::KING){
                    card.value = 10;
                } else{
                    card.value = (int)card.name;
                }

                int index = ((13 * Linha) + Coluna) - 1;
                arrCards[index] = card;

            }
        }
    }


    void DeckShuffle(){

        arrCards[]

    }


};

int main(){

    Deck deck;
    deck.SetupCards();

    std::cout<<std::endl;

    deck.PrintAll();

    

}