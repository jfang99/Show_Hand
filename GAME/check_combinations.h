
#ifndef check_combinations_h
#define check_combinations_h

#include"Compare.h"

bool check_royal_flush(vector<Card> cards);

bool check_straight_flush(vector<Card> cards);

bool check_four_of_kind(vector<Card> cards);

bool check_full_house(vector<Card>cards);

bool check_flush(vector<Card>cards);

bool check_straight(vector<Card> cards);

bool check_three_of_kind_only(vector<Card> cards);

bool check_two_pairs_only(vector<Card> cards);

bool check_one_pair_only(vector<Card> cards);
#endif /* check_combinations_h */
