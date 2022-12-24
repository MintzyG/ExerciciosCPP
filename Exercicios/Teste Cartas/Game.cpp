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
    int max_deck_size = 60;

};

struct PlayedDeck{

    vector<Card> played_cards;

};

struct Player{

    vector<Card> hand;
    vector<Card> possible_plays;
    string name;
    int score;
    int card_quantity = 0;

};

struct Game{

    vector<Player> players;
    PlayedDeck played_deck;
    Deck deck;
    Color starting_color;
    Card last_played_card;
    Player winner;
    int first_player = 0;
    int current_player = 0;
    int num_players = 8;
    int num_cards_per_hand = 7;
    int game_turns_played = 0;
    bool game_over = false;
    
};

void initialize_deck(Deck&);
void print_deck(const Deck&);
void print_card(const Card&);
void shuffle_deck(Deck&);
bool deal_cards(Game&); 
void print_hand(const vector<Card>&);
void initialize_game(Game&);
void add_players(Game&);
void print_game(const Game&); 
void play_game(Game&);
void start_color(Game&);
void first_player(Game&);
void turn(Game&);
bool check_win_condition(Game&);
void last_played_info(Game&);
void play_action(Game&, int);
void get_next_player(Game&, bool);
void screen_clear();
void choose_winner(Game&);
void show_finished_game(Game&);
void show_turns(Game&);

int main(){

    srand(time(NULL));

    Game game;
    play_game(game);

}

void initialize_deck(Deck& deck){



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

    switch (card.card_color){
    case Color::BLACK:
        cout<<"Black ";
        break;
    case Color::WHITE:
        cout<<"White ";
        break;
    case Color::YELLOW:
        cout<<"Yellow ";
        break;
    case Color::BLUE:
        cout<<"Blue ";
        break;
    case Color::GREEN:
        cout<<"Green ";
        break;
    case Color::RED:
        cout<<"Red ";
        break;
    case Color::EMPTY_COLOR:
        cout<<"Empty ";
        break;
    default:
        cout<<"error ";
        break;
    }

    switch (card.card_number){
    case Number::ZERO:
        cout<<"zero";
        break;
    case Number::ONE:
        cout<<"one";
        break;
    case Number::TWO:
        cout<<"two";
        break;
    case Number::THREE:
        cout<<"three";
        break;
    case Number::FOUR:
        cout<<"four";
        break;
    case Number::FIVE:
        cout<<"five";
        break;
    case Number::SIX:
        cout<<"six";
        break;
    case Number::SEVEN:
        cout<<"seven";
        break;
    case Number::EIGHT:
        cout<<"eight";
        break;
    case Number::NINE:
        cout<<"nine";
        break;
    case Number::EMPTY_NUMBER:
        cout<<"empty";
        break;
    default:
        cout<<"error";
        break;
    }
    cout<< endl; 

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

bool deal_cards(Game& game){

    if (game.deck.cards.size() < game.num_players * game.num_cards_per_hand){
        return false;
    }


     for (int card = 0; card < game.num_cards_per_hand; card++){
        for (int player = 0; player < game.num_players; player++){

            game.players[player].hand.push_back(game.deck.cards[0]);
            game.deck.cards.erase(game.deck.cards.begin());

        }
     }

    return true;

}

void print_hand(const vector<Card>& hand){

    int counter = 1;
    for (Card c : hand){

        cout<<counter<<": ";
        counter++;
        print_card(c);

    }
    cout<<endl;

}

void initialize_game(Game& game){

    initialize_deck(game.deck);
    shuffle_deck(game.deck);
    add_players(game);
    start_color(game);
    first_player(game);
}

void add_players(Game& game){

    string names;
    for(int player = 0; player < game.num_players; player++){
        
        Player new_player;
        game.players.push_back(new_player);
        cout<<"Choose player " << (player + 1) << " name" << endl;
        cin>>names;
        game.players[player].name = names;

    }

}

void print_game(const Game& game){

    for(int player = 0; player < game.num_players; player++){

        print_hand(game.players[player].hand);
        
    }

    print_deck(game.deck);

    cout << "Starting color: " << game.starting_color << endl;

}

void start_color(Game& game){

    int rand_color = rand() % Color::RED; 
    game.starting_color = Color(rand_color);

}

void first_player(Game& game){

    game.first_player = rand() % game.num_players;
    game.current_player = game.first_player;

}

void last_played_info(Game& game){

    if (game.played_deck.played_cards.empty()){
        cout<< "The starting color is: ";
        switch (game.starting_color)
        {
        case Color::BLACK:
            cout<<" Black";
            break;
        case Color::WHITE:
            cout<<" White";
            break;
        case Color::YELLOW:
            cout<<" Yellow";
            break;
        case Color::BLUE:
            cout<<" Blue";
            break;
        case Color::GREEN:
            cout<<" Green";
            break;
        case Color::RED:
            cout<<" Red";
            break;
        
        default:
            break;
        }
        cout<<endl;
    }

    if (!(game.played_deck.played_cards.empty())){
        cout << "The last played card was: ";
        print_card(game.last_played_card);
    }


}

void play_card(Game& game, int current_player, int action){

    Card temp_card;
    
    for (int card = 0; card < game.players[current_player].possible_plays.size(); card++){

        if (card == action){

            temp_card.card_color = game.players[current_player].possible_plays[card].card_color;
            temp_card.card_number = game.players[current_player].possible_plays[card].card_number;

        }
    }

    for (int card = 0; card < game.players[current_player].hand.size(); card++){
     
        if ((game.players[current_player].hand[card].card_color == temp_card.card_color) && (game.players[current_player].hand[card].card_number == temp_card.card_number)){

            cin.get();
            
            game.played_deck.played_cards.push_back(game.players[current_player].hand[card]);
            game.last_played_card = game.players[current_player].hand[card];
            game.players[current_player].hand.erase(game.players[current_player].hand.begin() + (card));

        }
    
    }

    game.game_over = check_win_condition(game);

} 

void player_draw(Game& game, int current_player){

    game.players[current_player].hand.push_back(game.deck.cards[0]);
    game.deck.cards.erase(game.deck.cards.begin());

    cout<<"There are " << game.deck.cards.size() << " cards left in the deck";

    if (game.deck.cards.empty()){
        
        for (int players = 0; players < game.players.size(); players++){
            for (int card = 0; card < game.players[players].hand.size(); card++){

                game.players[players].card_quantity = game.players[players].hand.size();

            }
        }

        for (int hand = 0; hand < game.players.size(); hand++){
            
            if (hand == 0){
                game.winner = game.players[hand]; 
            }else if ((game.winner.card_quantity) > (game.players[hand].card_quantity)){
                game.winner = game.players[hand];
            }


        }

        game.game_over = true;  

    }
}

void play_action(Game& game, int current_player){

        size_t count = 0;
        int action;
        
        if (game.played_deck.played_cards.empty()){
            for (int card = 0; card < game.players[current_player].hand.size(); card++){
                if (game.players[current_player].hand[card].card_color == game.starting_color){
                    count++;
                    cout << count << ": ";
                    print_card(game.players[current_player].hand[card]);
                    game.players[current_player].possible_plays.push_back(game.players[current_player].hand[card]);
                } 
            }
            if (count == 0){
                cout << endl << game.players[current_player].name << " draws" << endl;
                player_draw(game, current_player);
                get_next_player(game, true);
                return;
            }
            
            cout << "What card do you want to play?" << endl;
            while ((action < 0) || (action > ((game.players[current_player].possible_plays.size()) - 1))){
            
                cin >> action;
                action--;
            
            }   

            play_card(game, current_player, action);
            game.players[current_player].possible_plays.clear();
            return;
        }

        for (int card = 0; card < game.players[current_player].hand.size(); card++){
            if ((game.players[current_player].hand[card].card_color == game.last_played_card.card_color) || (game.players[current_player].hand[card].card_number == game.last_played_card.card_number)){

                count++;
                cout << count << ": ";
                print_card(game.players[current_player].hand[card]);
                game.players[current_player].possible_plays.push_back(game.players[current_player].hand[card]);

            }
        }
        if (count == 0){
            cout << endl << game.players[current_player].name <<" draws" << endl;
            player_draw(game, current_player);
            return;
        }
        
        cout << "What card do you want to play?" << endl;
        while ((action < 0) || (action > ((game.players[current_player].possible_plays.size()) - 1))){
            
            cin >> action;
            action--;
            
        }   

        play_card(game, current_player, action);
        game.players[current_player].possible_plays.clear();
        return;

    }

void get_next_player(Game& game, bool next_on_first){

    if (!next_on_first){

        int next_player = (game.current_player + 1) % game.num_players;
        game.current_player = next_player;

    }else{

        game.first_player = (game.current_player + 1) % game.num_players; 
        game.current_player = game.first_player;

    }
}

void turn(Game& game){

    if (game.played_deck.played_cards.empty()){
        int playing = game.first_player;
        cout << game.players[game.current_player].name << " starts!"<<endl;
        last_played_info(game);     
        cout<< endl;
        cout << game.players[game.current_player].name << "'s hand: " << endl; 
        print_hand(game.players[playing].hand);
        play_action(game, playing);
        cout<< endl << "Press enter to end turn" << endl;
        cin.get();
        return;
    }

    get_next_player(game, false);
    int playing = game.current_player;
    cout << game.players[game.current_player].name << " turn!"<<endl;
    last_played_info(game);     
    cout<< endl;
    cout << game.players[game.current_player].name << "'s hand: " << endl; 
    print_hand(game.players[playing].hand);
    play_action(game, playing);
    cout<< endl << "Press enter to end turn" << endl;
    cin.get();
    return;    

}

bool check_win_condition(Game& game){

    for (int player = 0; player < game.num_players; player++){

        if (game.players[player].hand.empty()){
            return true;
        }

    }
    return false;

}

void play_game(Game& game){

    initialize_game(game);
    deal_cards(game);

    game.game_over = check_win_condition(game);
    int turn_counter = 0;

    while (!game.game_over) {

        turn(game);
        turn_counter++;
        game.game_turns_played = turn_counter;
        screen_clear();

    }

    show_finished_game(game);
    choose_winner(game);
    show_turns(game);

}

void screen_clear(){

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
    <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
    <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
    <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

}

void choose_winner(Game& game){

    bool winner = false;
    for (int players = 0; players < game.num_players; players++){

        if (game.players[players].hand.empty()){

            cout << game.players[players].name << " was the winner!!!";
            winner = true;

        }

    }

    if (!winner){

        cout << "The winner was " << game.winner.name;
        cout << " they had the least cards at " << game.winner.hand.size() << " cards";

        cout << endl << " Everybody card count: " << endl;

        for (int player = 0; player < game.num_players; player++){

            cout << game.players[player].name << ": " << game.players[player].hand.size() << " cards" << endl;

        }
    }



}

void show_finished_game(Game& game){

    cout<<endl<<endl;

    cout<<"The game sequence was: "<<endl<<endl;
    print_hand(game.played_deck.played_cards);
    cout<<endl<<endl;

}

void show_turns(Game& game){

    cout<<endl<<endl;
    cout<<"The game was played for "<< game.game_turns_played<<" turns";
    cout<<endl;

}

