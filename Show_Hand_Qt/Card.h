// This is the header file for class Cards
//It should store the color, number of cards
#ifndef CARD_H
#define CARD_H

//There are four types of cards:

//white heart /u2661
//white diamond /u2662
//black spade /u2660
//black club /u2663

//Note to myself: white heart is red heart in the common sense; white diamond is red diamond
//in the common Poker.





#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Card{
    //the fields:
private:
    string suit;
    string rank;
    //number is used to represent the order of the card,while rank represents
    int number;
public:
    //the member functions:
    //Constructors:
    Card();
    Card(string csuit, string crank);
    Card(string csuit,int cnumber);
    string get_suit() const;
    string get_rank() const;
    int get_number() const;
    void set_number(int a);

};





//Non-member functions:
ostream& operator<<(ostream& out, const Card& card);

void create_deck(vector<Card>& cards);

#endif /* Card_h */

