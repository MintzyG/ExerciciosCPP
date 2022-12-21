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

};

struct Deck{

    Card arrCards[52];

    void InitializeDeck(){

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

    void printDeck(const Deck& deck){

        for (int i = 0; i < 52; i++){
            if (arrCards[i].name == CardNames::ACE){
                std::cout<<"Ace";
            }else if (arrCards[i].name == CardNames::JACK){
                std::cout<<"Jack";
            }else if (arrCards[i].name == CardNames::QUEEN){
                std::cout<<"Queen";
            }else if (arrCards[i].name == CardNames::KING){
                std::cout<<"King";
            }else{
                std::cout<<arrCards[i].value;
            }

            std::cout<<" of ";

            if (arrCards[i].suit == Suits::CLUBS){
                std::cout<<"clubs";
            }else if (arrCards[i].suit == Suits::DIAMONDS){
                std::cout<<"diamonds";
            }else if (arrCards[i].suit == Suits::HEARTS){
                std::cout<<"hearts";
            }else if (arrCards[i].suit == Suits::SPADES){
                std::cout<<"spades";
            }

            std::cout<<std::endl;
        }
    }

    void DeckShuffle(Deck& deck){

    }

};

int main(){

    Deck deck;
    deck.InitializeDeck();
    deck.printDeck(deck);

    std::cout<<std::endl;

}