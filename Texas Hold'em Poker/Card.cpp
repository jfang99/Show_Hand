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






//Non-member functions:
ostream& operator<<(ostream& out, const Card& card){
out<<"Color:"<<card.color<<endl;
out<<"Number:"<<card.number<<endl;
    return out;
}
