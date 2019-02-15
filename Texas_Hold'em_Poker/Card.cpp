// Definitions of the member functions of class Cards
#include "Card.h"
using namespace std;

Card::Card(){
    color = "";
    number = 0;
}

Card::Card(string ccolor, int cnumber){
    color=ccolor;
    number=cnumber;
   
}

string Card::get_color() const{
    return color;
}

int Card::get_number() const{
    return number;
}

void Card::set_number(int a){
    number=a;
}

//Non-member functions:
ostream& operator<<(ostream& out, const Card& card){
out<<"Color:"<<card.get_color()<<endl;
out<<"Number:"<<card.get_number()<<endl;
    return out;
}
