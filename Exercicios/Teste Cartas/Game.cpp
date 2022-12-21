#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

enum Color { BLACK, WHITE, YELLOW, BLUE, GREEN, RED, EMPTY_COLOR };
enum Number { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, EMPTY_NUMBER };
enum Animal { OCTOPUS, OWL, MOOSE, WOLF, GOAT, BEAR, EMPTY_ANIMAL };
enum Type { HAND, INVENTORY, TERRITORY, EMPTY_TYPE };
enum Strength { LOW, HIGH, SPECIAL, EMPTY_STRENGTH };  

struct Card{

    Color card_color;
    Number card_number;
    Animal card_animal;
    Type card_type;
    Strength card_strength;
    int num_number = 10;
    int num_color = 6;

};

struct Deck{

    vector<Card> cards;
    string card_back;
    int max_deck_size = 60;

};



void initialize(Deck&);
void print_deck(const Deck&);
void print_card(const Card&);
void shuffle_deck(Deck&);

int main(){

    Deck my_deck;
    srand(time(NULL));

    initialize(my_deck);
    //print_deck(my_deck);
    shuffle_deck(my_deck);
    //print_deck(my_deck);

}

void initialize(Deck& deck){



        Card card;
        card.card_strength = Strength::LOW;
        card.card_type = Type::HAND;
        
        for (int number = 0; number < card.num_number; number++){
            for (int color = 0; color < card.num_color; color++){

                card.card_color = Color(color);
                card.card_number = Number(number);

                switch (color){
                    case 0:
                        card.card_animal = Animal::OWL;
                        break;

                    case 1:
                        card.card_animal = Animal::OCTOPUS;
                        break;

                    case 2:
                        card.card_animal = Animal::GOAT;
                        break;

                    case 3:
                        card.card_animal = Animal::WOLF;
                        break;

                    case 4:
                        card.card_animal = Animal::MOOSE;
                        break;
                        
                    case 5:
                        card.card_animal = Animal::BEAR;
                        break;
                                    
                    default:
                        card.card_animal = Animal::EMPTY_ANIMAL;
                        break;
                }

                deck.cards.push_back(card);

            }
        }


}

void print_deck(const Deck& deck){

    for (Card c : deck.cards){

        print_card(c); 

    }

}

void print_card(const Card& card){

    cout << "Number = " << card.card_number << "   " 
    << " Animal = " << card.card_animal << "   "
    << " Color = " << card.card_color << "   "
    << " Type = " << card.card_type << "   "
    << " Strength = " << card.card_strength << endl; 

}

void shuffle_deck(Deck& deck){

    Deck shuffled;

    while (!deck.cards.empty()){

        size_t rand_index = rand() % deck.cards.size();
        shuffled.cards.push_back(deck.cards[rand_index]);
        deck.cards.erase(deck.cards.begin() + rand_index);

    }

    deck = shuffled;

}