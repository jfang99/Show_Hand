// This is the header file for class Cards
//It should store the color, number of cards
#ifndef Card_h
#define Card_h

//There are four types of cards:

//white heart /u2661
//white diamond /u2662
//black spade /u2660
//black club /u2663

//Note to myself: white heart is red heart in the common sense; white diamond is red diamond
//in the common Poker.





#include<iostream>
#include<string>
using namespace std;


class Card{
    //the fields:
private:
    string color;
    int number;
public:
    //the member functions:
    //Constructors:
    Card();
    Card(string ccolor, int cnumber);
    string get_color() const;
    int get_number() const;
    void set_number(int a);
};





//Non-member functions:
ostream& operator<<(ostream& out, const Card& card);



#endif /* Card_h */

