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
public:
    vector<Card> cards;
    
};

#endif /* Person_hpp */
