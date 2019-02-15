//Definition of the "Compare" function"s"
#include"Compare.h"

using std::vector;

//bool Compare(const vector<Card>& card1, const vector<Card>& card2){
    
//}







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
//int transf_cards_to_int(const vector<Card>& cards){
    //check if contains royal flush:
 
    
//}


//helper function for transfer:

//"check_sequnce" can be used for Royal Flush, Straight Flush, and Straight:
bool check_sequence(vector<Card>& cards){
    sort_in_order(cards);
    bool flag=false;
    int loop_time=cards.size()-4;
    for(int i=0;i<loop_time&&(!flag);i++){
        
        for(int k=i;(k<i+4)&&(!flag);k++){
            if((cards[k+1].get_number()==(cards[k].get_number()+1)))
            {flag=false;}
            else{flag=true;}
            }
        }
    return !flag;
}

    


//find minimum:
/*int find_min(const vector<Card>& cards){
    int min=13;
    for(int i=0; i<cards.size();i++){
        if(((cards[i]).get_number())<=min){
            min=cards[i].get_number();
        }
    }
    return min;
}*/

//decide if certain number is found in the vector:
bool find(const vector<Card>& cards, int target){
    for(int i=0; i<cards.size(); i++){
        if ((cards[i].get_number())==target)return true;
    }
    return false;
}

//sort cards from smallest to biggest
//using selection sort:
void sort_in_order(vector<Card>& cards){
    for(int i=0;i<cards.size();i++){
        int k=i;
        int min=cards[k].get_number();
        for(int m=i;m<cards.size();m++){
            if(cards[m].get_number()<min)
            {k=m;
            min=cards[m].get_number();}
        }
        //swap k and i
        int temp=cards[i].get_number();
        cards[i].set_number(cards[k].get_number());
        cards[k].set_number(temp);
    }
    return;
}
