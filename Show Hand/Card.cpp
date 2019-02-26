// Definitions of the member functions of class Cards
#include "Card.h"
using namespace std;

Card::Card(){

    suit="";
    rank="";
    number = 0;
    
}

Card::Card( string csuit, string crank){
    suit=csuit;
    rank=crank;
    if(crank=="2")number=1;
    if(crank=="3")number=2;
    if(crank=="4")number=3;
    if(crank=="5")number=4;
    if(crank=="6")number=5;
    if(crank=="7")number=6;
    if(crank=="8")number=7;
    if(crank=="9")number=8;
    if(crank=="10")number=9;
    if(crank=="J")number=10;
    if(crank=="Q")number=11;
    if(crank=="K")number=12;
    if(crank=="A")number=13;
}



string Card::get_suit() const{
    return suit;
}

string Card::get_rank()const{
    return rank;
}

int Card::get_number() const{
    return number;
}

void Card::set_number(int a){
    number=a;
}


//Non-member functions:
ostream& operator<<(ostream& out, const Card& card){
out<<card.get_suit()<<card.get_rank()<<endl;

    return out;
}
