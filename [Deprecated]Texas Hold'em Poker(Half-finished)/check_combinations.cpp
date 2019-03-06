#include"check_combinations.h"


bool check_royal_flush(vector<Card> cards){
    if(check_sequence(cards)){
    vector<Card> sequence=get_largest_sequence(cards);
    //9 represents rank 10, as 10JQKA is royal flush
    if(same_colors(sequence)&&same_suits(sequence)&&((sequence[0].get_number())==9)){
        return true;
    }
    }
    return false;
}

bool check_straight_flush(vector<Card> cards){
    return true;
}
