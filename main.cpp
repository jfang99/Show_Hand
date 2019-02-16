//This main.cpp file is just for testing functions or operations I just learned.

#include<iostream>
#include"Card.h"
#include"Compare.h"
using namespace std;

int main(){
    cout<<"\u2661";
    cout<<"\u2662"<<"\u2660"<<"\u2663";
    
    
    Card card1("red","\u2661","9");
    Card card2("red","\u2661","J");
    Card card3("red","\u2661","10");
    Card card4("red","\u2661","10");
    Card card5("red","\u2661","K");
    Card card6("red","\u2661","8");
    Card card7("red","\u2661","7");
    
    vector<Card> cards={card1,card2,card3,card4,card5,card6,card7};
    sort_in_order(cards);
    for(int i=0;i<7;i++){
        cout<<cards[i].get_rank();

    }
    cout<<endl;
    for(int i=0;i<7;i++){
        cout<<cards[i].get_number();
    }
    
    if(!check_sequence(cards))cout<<"woshizhu";
    else{cout<<"ggod sequence";}
    if(check_royal_flush(cards)){
    vector<Card> ji=get_largest_sequence(cards);
    for(int i=0;i<ji.size();i++){
        cout<<ji[i];
    }
    }
}
