//
//  Person.hpp
//  Texas Hold'em Poker
//
//  Created by Jfei on 2019/2/14.
//  Copyright © 2019 Jfei. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include"Card.h"
#include<vector>

using namespace std;

class Person:public Card{
protected:
    vector<Card> cards;
    int money;
    int bid;
public:
    Person();
    void add_bid();
    void set_bid(int a);
    int get_bid() const;
    void add_card(Card card);
    int get_money() const;
    void decrease_money();
    void set_money(int a);

    string get_suit();
    string get_rank();

    void face_down();
    int handsize();
    void resize();
    vector<Card> get_hand();
};

#endif /* Person_hpp */
