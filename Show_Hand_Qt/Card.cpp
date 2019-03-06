// Definitions of the member functions of class Cards
#include "Card.h"
using namespace std;

Card::Card(){

    suit="";
    rank="";
    number = 0;
    facedown=false;
    
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

Card::Card(string csuit, int cnumber){
    suit=csuit;
    number=cnumber;
    if(cnumber==1)rank="2";
    if(cnumber==2)rank="3";
    if(cnumber==3)rank="4";
    if(cnumber==4)rank="5";
    if(cnumber==5)rank="6";
    if(cnumber==6)rank="7";
    if(cnumber==7)rank="8";
    if(cnumber==8)rank="9";
    if(cnumber==9)rank="10";
    if(cnumber==10)rank="J";
    if(cnumber==11)rank="Q";
    if(cnumber==12)rank="K";
    if(cnumber==13)rank="A";
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

void Card::face_it_down(){
    facedown=true;
}

//Non-member functions:
ostream& operator<<(ostream& out, const Card& card){
out<<card.get_suit()<<card.get_rank()<<endl;

    return out;
}

//create a deck:
void create_deck(vector<Card>& cards){
    for(int i=0;i<13;i++){
    cards.push_back(Card("\u2660",i));
    cards.push_back(Card("\u2661",i));
    cards.push_back(Card("\u2662",i));
    cards.push_back(Card("\u2663",i));
    }
    return;
}
