//Definition of the "Compare" function"s"
#include"Compare.h"

using std::vector;

bool operator >(const vector<Card>& card1, const vector<Card>& card2){
    //psudocode for it:
    int a=transf_cards_to_int(card1);
    int b=transf_cards_to_int(card2);
    if(a>b)return true;
    else if(a<b)return false;
    else if(a==b){
        //if royal flush:
        if(a==10){
            return false;
        }
        //if straight flush:
        else if(a==9){
            vector<Card> carda=get_largest_sequence(card1);
            vector<Card> cardb=get_largest_sequence(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
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
                carda=get_largest_two(card1);
                cardb=get_largest_two(card2);
                if(carda[0].get_number()>cardb[0].get_number())return true;
                else return false;
            }
        }
        //if flush:
        else if(a==6){
            //note for get_suit: when writing get_suit, the size can be over five.
            vector<Card> carda=get_suit(card1);
            vector<Card> cardb=get_suit(card2);
            if(carda[carda.size()-1].get_number()>cardb[cardb.size()-1].get_number())return true;
            else return false;
        }
        //if straight:
        else if(a==5){
            vector<Card> carda=get_largest_sequence(card1);
            vector<Card> cardb=get_largest_sequence(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
            else return false;
        }
        //if three of a kind:
        else if(a==4){
            //note: this is reusing get_three:
            vector<Card> carda=get_three(card1);
            vector<Card> cardb=get_three(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
            else return false;
        }
        //if two pair:
        else if(a==3){
            vector<Card> carda=get_largest_pair(card1);
            vector<Card> cardb=get_largest_pair(card2);
            if(carda[0].get_number()>cardb[0].get_number())return true;
            else{
                
            }
                
        }
        
    }
    }
        
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
    
    return 0;
}


//HELPER FUNCTION FOR "TRANSFER":

//"check_sequnce" can be used for checking Royal Flush, Straight Flush, and Straight:
bool check_sequence(vector<Card> cards){
    sort_in_order(cards);
    bool flag=true;
    bool flagg=true;
    unsigned long loop_time=cards.size()-4;
    //use size()-4 because the maximum size in Texas poker is 7
    
    for(int i=0;i<loop_time&&flag;i++){
        for(int k=i;(k<i+4)&&flagg;k++){
            //handle repetition
            while(cards[k+1].get_number()==cards[k].get_number()){
                k++;
                loop_time--;
            }
            //handle "2345677" situation:
            if(k+1>=(cards.size()-1)){
                return false;
            }
            else if(cards[k+1].get_number()==cards[k].get_number()+1)
            {flagg=true;
                flag=false;
            }
            else{flagg=false;
                flag=true;
            }
            }
        }
    return flagg;
}


vector<Card> get_smallest_sequence(vector<Card> cards){
    vector<Card> result;
    if(check_sequence(cards)){
        sort_in_order(cards);
        bool flag=true;
        bool flagg=true;
        int loop_time=cards.size()-4;
        int i=100;
        for(i=0;i<loop_time&&flag;i++){
            for(int k=i;(k<i+4)&&flagg;k++){
                while(cards[k+1].get_number()==cards[k].get_number()){
                    k++;
                    loop_time--;
                }
                if(k>=(cards.size()-1))return vector<Card>();
                else if((cards[k+1].get_number()==(cards[k].get_number()+1)))
                {flagg=true;
                    flag=false;
                }
                else{flagg=false;
                    flag=true;
                }
            }
        }
        
        i--;
        vector<Card> cards2;
        
        for(int j=i;j<i+5;j++){
            while(cards[j+1].get_number()==cards[j].get_number()+1){
                j++;
            }
            cards2.push_back(cards[j]);
        }
        result=cards2;
    }
        //can't find sequence?
        else{
            result=vector<Card>();
        }
        
        return result;
}
    

vector<Card> get_2ndlarge_sequence(vector<Card>cards){
    vector<Card> result;
    if(check_sequence(cards)){
        sort_in_order(cards);
        bool flag=true;
        bool flagg=true;
        int loop_time=cards.size()-4;
        int i=100;
        for(i=0;i<loop_time&&flag;i++){
            for(int k=i;(k<i+4)&&flagg;k++){
                while(cards[k+1].get_number()==cards[k].get_number()){
                    k++;
                    loop_time--;
                }
                 if(k>=(cards.size()-1))return vector<Card>();
               else if((cards[k+1].get_number()==(cards[k].get_number()+1)))
                {flagg=true;
                    flag=false;
                }
                else{flagg=false;
                    flag=true;
                }
            }
        }
        
        i--;
        vector<Card> cards2;
        
        for(int j=i;j<i+5;j++){
            while(cards[j+1].get_number()==cards[j].get_number()+1){
                j++;
            }
            cards2.push_back(cards[j]);
        }
        result=cards2;
        
        //However, there may be more than one sequence, and we want to take the second largest one:
        while(i<(loop_time-1)){
            i++;
            //take in ith to last element of cards:
            vector<Card> cards3;
            for(int n=i;n<cards.size();n++){
                cards3.push_back(cards[n]);
            }
            //recursion here!!
            if(check_sequence(cards3)){
                result=get_smallest_sequence(cards3);
            }
        }
        
    }
    
    //can't find sequence?
    else{
        result=vector<Card>();
    }
    
    return result;
}
    
//This function of getting the largest sequence is very complicated because it takes in recursion.
vector<Card> get_largest_sequence(vector<Card> cards){
    vector<Card> result;
    if(check_sequence(cards)){
        sort_in_order(cards);
        bool flag=true;
        bool flagg=true;
        int loop_time=cards.size()-4;
        int i=100;
        for(i=0;i<loop_time&&flag;i++){
            for(int k=i;(k<i+4)&&flagg;k++){
                while(cards[k+1].get_number()==cards[k].get_number()){
                    k++;
                    loop_time--;
                }
                 if(k>=(cards.size()-1))return vector<Card>();
                else if((cards[k+1].get_number()==(cards[k].get_number()+1)))
                {flagg=true;
                    flag=false;
                }
                else{flagg=false;
                    flag=true;
                }
            }
        }
        
        i--;
        vector<Card> cards2;
        
        for(int j=i;j<i+5;j++){
            while(cards[j+1].get_number()==cards[j].get_number()+1){
                j++;
            }
            cards2.push_back(cards[j]);
        }
        result=cards2;
        
        //However, there may be more than one sequence, and we want to take the bigger one:
        while(i<(loop_time-1)){
            i++;
            //take in ith to last element of cards:
            vector<Card> cards3;
            for(int n=i;n<cards.size();n++){
                cards3.push_back(cards[n]);
            }
            //recursion here!!
            if(check_sequence(cards3)){
            result=get_largest_sequence(cards3);
            }
        }
            
    }
    
    //can't find sequence?
    else{
        result=vector<Card>();
    }
    
    return result;
}

//the vector taken in should have size of 5
bool same_colors(const vector<Card>& cards){
    for(int i=0;i<4;i++){
        if(cards[i].get_color()!=cards[i+1].get_color()){
            return false;
        }
    }
    return true;
}

//vector has size of 5
bool same_suits(const vector<Card>& cards){
    for(int i=0;i<4;i++){
        if(cards[i].get_suit()!=cards[i+1].get_suit()){
            return false;
        }
    }
    return true;
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
        std::swap(cards[k],cards[i]);
    }
    return;
}
