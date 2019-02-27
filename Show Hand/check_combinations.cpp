#include"check_combinations.h"


bool check_royal_flush(vector<Card> cards){
    if(check_sequence(cards)){
    vector<Card> sequence=get_sequence(cards);
    //9 represents rank 10, as 10JQKA is royal flush
    if(same_suits(sequence)&&((sequence[0].get_number())==9)){
        return true;
    }
    }
    return false;
}

bool check_straight_flush(vector<Card> cards){
    if(check_sequence(cards)&&same_suits(cards)){
            return true;
        }
    return false;
}

bool check_four_of_kind(vector<Card> cards){
    sort_in_order(cards);
    bool flag=true;
    for(int i=0;i<3&&flag;i++){
        if(cards[i].get_number()==cards[i+1].get_number()){
            flag=true;
        }
        else{
            flag=false;
        }
    }
    
    if(flag==true)return flag;
    
    flag=true;
    for(int i=1;i<4&&flag;i++){
        if(cards[i].get_number()==cards[i+1].get_number()){
            flag=true;
        }
        else{
            flag=false;
        }
    }
    return flag;
}

bool check_full_house(vector<Card> cards){
    sort_in_order(cards);
    //22333
    //22233
    bool flag=true;
        if(cards[0].get_number()==cards[1].get_number()&&flag){
            flag=true;}
        else{return false; //because the first two terms have to be the same.
            }
    if(cards[1].get_number()==cards[2].get_number()){
       if(cards[3].get_number()==cards[4].get_number())
           return true;
    }
    else{
 if((cards[2].get_number()==cards[3].get_number())&&(cards[3].get_number()==cards[4].get_number()))
    return true;
    else return false;
          
    }
    return false;
}

bool check_flush(vector<Card> cards){
    sort_in_order(cards);
    if(same_suits(cards))return true;
    return false;
}

bool check_straight(vector<Card> cards){
    if(check_sequence(cards))return true;
    else return false;
}

bool check_three_of_kind_only(vector<Card> cards){
    sort_in_order(cards);
    if(!check_full_house(cards)){
    if(cards[0].get_number()==cards[1].get_number()&&cards[1].get_number()==cards[2].get_number())return true;
    if(cards[1].get_number()==cards[2].get_number()&&cards[2].get_number()==cards[3].get_number()) return true;
    if(cards[2].get_number()==cards[3].get_number()&&cards[3].get_number()==cards[4].get_number()) return true;
    }
    return false;
}


bool check_two_pairs_only(vector<Card> cards){
    sort_in_order(cards);
    //44556
    //45566
    //44566
    if(!check_full_house(cards)){
        if(cards[0].get_number()==cards[1].get_number()&&cards[2].get_number()==cards[3].get_number())return true;
        if(cards[1].get_number()==cards[2].get_number()&&cards[3].get_number()==cards[4].get_number())return true;
        if(cards[0].get_number()==cards[1].get_number()&&cards[3].get_number()==cards[4].get_number())return true;
    }
    return false;
}

bool check_one_pair_only(vector<Card> cards){
    sort_in_order(cards);
    if(!check_four_of_kind(cards)&&!check_full_house(cards)&&!check_two_pairs_only(cards)){
        //44567
        //45567
        //45667
        //45677
        if(cards[0].get_number()==cards[1].get_number())return true;
        if(cards[1].get_number()==cards[2].get_number())return true;
        if(cards[2].get_number()==cards[3].get_number())return true;
        if(cards[3].get_number()==cards[4].get_number())return true;
    }
    return false;
}

