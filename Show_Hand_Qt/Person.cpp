//
//  Person.cpp
//  Texas Hold'em Poker
//
//  Created by Jfei on 2019/2/14.
//  Copyright © 2019 Jfei. All rights reserved.
//

#include "Person.h"


 Person::Person(){bid=0;cards.resize(0);money=1000;}

 void Person::add_bid(){
     bid+=50;
 }

 void Person::set_bid(int a){
     bid=a;
 }


 int Person::get_bid() const{
     return bid;
 }

 void Person::add_card(Card card){
     cards.push_back(card);
     return;
 }

 int Person::get_money()const{
     return money;
 }

 void Person::decrease_money(){
     money-=50;
 }

 void Person::set_money(int a){
     money=a;
 }

 string Person::get_suit(){
 return cards[cards.size()-1].get_suit();
 }

 string Person::get_rank(){
 return cards[cards.size()-1].get_rank();
 }

 void Person::face_down(){
     cards[cards.size()-1].face_it_down();
     return;
 }

 int Person::handsize(){
     return cards.size();
 }

 void Person::resize(){
     cards.resize(0);
     return;
 }

 vector<Card> Person::get_hand(){
     return cards;
 }
