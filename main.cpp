//This main.cpp file is just for testing functions or operations I just learned.

#include<iostream>
#include"Card.h"
#include"Compare.h"
using namespace std;

int main(){
    cout<<"\u2661";
    cout<<"\u2662"<<"\u2660"<<"\u2663";
    
    
    Card card1("\u2661","9");
    Card card2("\u2661","10");
    Card card3("\u2661","Q");
    Card card4("\u2661","J");
    Card card5("\u2661","K");
 
    
    vector<Card> cards={card1,card2,card3,card4,card5};
    sort_in_order(cards);
    for(int i=0;i<5;i++){
        cout<<cards[i].get_rank();

    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<cards[i].get_number();
    }
    
    if(!check_sequence(cards))cout<<"woshizhu";
    else{cout<<"ggod sequence";}
    if(check_royal_flush(cards)){
    vector<Card> ji=get_sequence(cards);
    for(int i=0;i<ji.size();i++){
        cout<<ji[i];
    }
    }
}
