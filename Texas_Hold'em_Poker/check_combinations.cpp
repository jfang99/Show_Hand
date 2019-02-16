#include"check_combinations.h"


bool check_royal_flush(vector<Card> cards){
    vector<Card> sequence=get_largest_sequence(cards);
 
    if(same_colors(sequence)&&((sequence[0].get_number())==10)){
        return true;
    }
    
    return false;
}

bool check_straight_flush(vector<Card> cards){
    return true;
}
