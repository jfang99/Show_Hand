//This main.cpp file is just for testing functions or operations I just learned.

#include<iostream>
#include"Card.h"
#include"Compare.h"
using namespace std;

int main(){
    cout<<"\u2661";
    cout<<"\u2662"<<"\u2660"<<"\u2663";
    Card card1("red",8);
    Card card2("red",4);
    Card card3("red",5);
    Card card4("red",3);
    Card card5("red",2);
    vector<Card> cards={card1,card2,card3,card4,card5};
    sort_in_order(cards);
    for(int i=0;i<5;i++){
        cout<<cards[i].get_number();
    }
    if(!check_sequence(cards))cout<<"woshizhu";
    else{cout<<"ggod sequence";}
}
