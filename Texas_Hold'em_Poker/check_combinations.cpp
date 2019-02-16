#include"check_combinations.h"


bool check_royal_flush(vector<Card> cards){
    vector<Card> first_sequence=get_smallest_sequence(cards);
    vector<Card> second_sequence=get_2ndlarge_sequence(cards);
    vector<Card> third_sequence=get_largest_sequence(cards);
    
    if(same_colors(first_sequence)){
        return true;
    }
    else if(same_colors(second_sequence)){
        return true;
    }
    else if(same_colors(third_sequence)){
        return true;
    }
    
    return false;
}
