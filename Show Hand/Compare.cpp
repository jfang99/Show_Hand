//Definition of the "Compare" function"s"
#include"Compare.h"

using std::vector;

bool operator >( vector<Card> card1,  vector<Card> card2){
    //psudocode
    int a=transf_cards_to_int(card1);
    int b=transf_cards_to_int(card2);
    
    if(a>b)return true;
    else if(a<b)return false;
    else if(a==b){
        sort_in_order(card1);
        sort_in_order(card2);
        
        //if royal flush:
        if(a==10){
            return false;
        }
        
        //if straight flush:
        else if(a==9){
            if(card1[0].get_number()>card1[0].get_number())return true;
            else return false;
        }
        
        //if four of a kind:
        else if(a==8){
            vector<Card> carda=get_four_of_kind(card1);
            vector<Card> cardb=get_four_of_kind(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
            else return false;
        }
        
        //if full house:
        else if(a==7){
            vector<Card> carda=get_three(card1);
            vector<Card> cardb=get_three(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
            else{
                carda=get_two(card1);
                cardb=get_two(card2);
                if(carda[0].get_number()>cardb[0].get_number())return true;
                else return false;
            }
        }
        
        //if flush:
        else if(a==6){
            if(card1[4].get_number()>card2[4].get_number())return true;
            else return false;
        }
        
        //if straight:
        else if(a==5){
            if(card1[0].get_number()>card2[0].get_number())return true;
            else return false;
        }
        
        //if three of a kind:
        else if(a==4){
            //note: this is reusing get_three:
            vector<Card> carda=get_three_only(card1);
            vector<Card> cardb=get_three_only(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
            else return false;
        }
        
        //if two pairs:
        else if(a==3){
            vector<Card> carda=get_larger_pair(card1);
            vector<Card> cardb=get_larger_pair(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
            else{
                carda=get_smaller_pair(card1);
                cardb=get_smaller_pair(card2);
                if(carda[0].get_number()>cardb[0].get_number())return true;
            }
            
            return false;
        }
        
        //if one pair:
        else if(a==2){
            
        }
    }
    return false;
    }
        








//helper function:

//Royal flush = 10
//Straight flush = 9
//Four of a kind = 8
//Full house = 7
//Flush = 6
//Straight = 5
//Three of a kind = 4
//Two pair = 3
//One pair = 2
//High card = 1

int transf_cards_to_int(vector<Card> cards){
    //check if contains royal flush:
    if(check_royal_flush(cards)){
        return 10;
    }
    if(check_straight_flush(cards)){
        return 9;
    }
    if(check_four_of_kind(cards)){
        return 8;
    }
    if(check_full_house(cards)){
        return 7;
    }
    if(check_flush(cards)){
        return 6;
    }
    if(check_straight(cards)){
        return 5;
    }
    if(check_three_of_kind_only(cards)){
        return 4;
    }
    if(check_two_pairs_only(cards)){
        return 3;
    }
    if(check_one_pair_only(cards)){
        return 2;
    }
    return 0;
}


//HELPER FUNCTION FOR "TRANSFER":




//"check_sequnce" can be used for checking Royal Flush, Straight Flush, and Straight:
bool check_sequence(vector<Card> cards){
    sort_in_order(cards);
    bool flag=true;

    for(int i=0;i<4&&flag;i++){
        if(cards[i+1].get_number()==cards[i].get_number()+1)flag=true;
        else flag=false;
    }
    
    return flag;
}


//get the sequence in the vector:
vector<Card> get_sequence(vector<Card> cards){
    vector<Card> result;
    if(check_sequence(cards)){
        sort_in_order(cards);
        for(int i=0;i<5;i++){
            result.push_back(cards[i]);
        }
    }
        //can't find sequence?
        else{
            result=vector<Card>();
        }
        
        return result;
}
    



bool same_suits(const vector<Card>& cards){
    for(int i=0;i<cards.size();i++){
        if(cards[i].get_suit()!=cards[i+1].get_suit()){
            return false;
        }
    }
    return true;
    }



//sort cards from smallest to biggest
//using selection sort:
void sort_in_order(vector<Card>& cards){
    for(int i=0;i<(cards.size()-1);i++){
        int k=i;
        int min=cards[k].get_number();
        for(int m=i;m<cards.size();m++){
            if(cards[m].get_number()<min)
            {k=m;
            min=cards[m].get_number();}
        }
        //swap k and i
        std::swap(cards[k],cards[i]);
    }
    return;
}



vector<Card> get_four_of_kind(vector<Card> cards){
    vector<Card> result;
    //first check if there's four of kind:
    if(check_four_of_kind(cards)){
        sort_in_order(cards);
        if(cards[0].get_number()==cards[1].get_number()){
            for(int i=0;i<4;i++){
                result.push_back(cards[i]);
            }
        }
        else{
            for(int i=1;i<5;i++){
                result.push_back(cards[i]);
            }
        }
    }
    return result;
}

vector<Card> get_three(vector<Card> cards){
    vector<Card> result;
    if(check_full_house(cards)){
        if(cards[1].get_number()==cards[2].get_number()){
            for(int i=0;i<3;i++){
                result.push_back(cards[i]);
            }
        }
        else{
            for(int i=2;i<5;i++){
                result.push_back(cards[i]);
            }
        }
    }
    return result;
}

vector<Card> get_two(vector<Card> cards){
    vector<Card> result;
    if(cards[1].get_number()==cards[2].get_number()){
        result.push_back(cards[3]);
        result.push_back(cards[4]);
    }
    else{
        result.push_back(cards[0]);
        result.push_back(cards[1]);
    }
    return result;
}

//works only for three_of_kind
vector<Card> get_three_only(vector<Card> cards){
    vector<Card> result;
    sort_in_order(cards);
    if(!check_full_house(cards)&&check_three_of_kind_only(cards)){
        int i=0;
        if(cards[0].get_number()==cards[1].get_number()&&cards[1].get_number()==cards[2].get_number())
            i=0;
        if(cards[1].get_number()==cards[2].get_number()&&cards[2].get_number()==cards[3].get_number())
            i=1;
        if(cards[2].get_number()==cards[3].get_number()&&cards[3].get_number()==cards[4].get_number())
            i=2;
        
        for(int j=i;j<i+3;j++){
            result.push_back(cards[j]);
        }
    }
    
    return result;
}


vector<Card> get_larger_pair(vector<Card>cards){
    sort_in_order(cards);
    vector<Card> result;
    if(check_two_pairs_only(cards)){
        if(cards[0].get_number()==cards[1].get_number()&&cards[2].get_number()==cards[3].get_number()){
            result.push_back(cards[2]);
            result.push_back(cards[3]);
        }
        if(cards[1].get_number()==cards[2].get_number()&&cards[3].get_number()==cards[4].get_number()){
            result.push_back(cards[3]);
            result.push_back(cards[4]);
        }
        if(cards[0].get_number()==cards[1].get_number()&&cards[3].get_number()==cards[4].get_number()){
            result.push_back(cards[3]);
            result.push_back(cards[4]);
        }
    }
    return result;
}

vector<Card> get_smaller_pair(vector<Card> cards){
    sort_in_order(cards);
    vector<Card> result;
    if(check_two_pairs_only(cards)){
        if(cards[0].get_number()==cards[1].get_number()&&cards[2].get_number()==cards[3].get_number()){
            result.push_back(cards[0]);
            result.push_back(cards[1]);
        }
        if(cards[1].get_number()==cards[2].get_number()&&cards[3].get_number()==cards[4].get_number()){
            result.push_back(cards[1]);
            result.push_back(cards[2]);
        }
        if(cards[0].get_number()==cards[1].get_number()&&cards[3].get_number()==cards[4].get_number()){
            result.push_back(cards[0]);
            result.push_back(cards[1]);
        }
    }
    return result;
}
