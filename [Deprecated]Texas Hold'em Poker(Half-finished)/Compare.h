//This is the implementation of the compare function for two set of cards.
//Only 1 "Compare" function even if sets of 5,6,7 cards need to be compared.

#ifndef Compare_h
#define Compare_h

#include"Card.h"
#include"check_combinations.h"

#include<vector>
using std::vector;

//bool Compare(const vector<Card>& card1, const vector<Card>& card2);




//helper function for Compare
//This function helps me turn sets of cards into integers. Then I can compare the integers to determine who should
int transf_cards_to_int( vector<Card> cards);

bool check_sequence(vector<Card> cards);

vector<Card> get_smallest_sequence(vector<Card> cards);

vector<Card> get_2ndlarge_sequence(vector<Card> cards);

vector<Card> get_largest_sequence(vector<Card> cards);
//int find_min(const vector<Card>& cards);


bool same_colors(const vector<Card>& cards);

bool same_suits(const vector<Card>& cards);

bool find(const vector<Card>& cards, int target);

void sort_in_order(vector<Card>& card);

#endif /* Compare_h */
