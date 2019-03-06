#include "show_hand.h"
#include "ui_show_hand.h"
#include"startwindow.h"
#include"Card.h"
#include"Person.h"
#include"Compare.h"
#include"check_combinations.h"

#include<QString>
#include<QLabel>
#include<cstdlib>
#include<ctime>
#include<QObject>

using namespace std;

Show_Hand::Show_Hand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Show_Hand)
{
    srand(time(0));
    ui->setupUi(this);
    create_deck(deck);
    //random shuffle needed.
    random_shuffle(deck.begin(),(deck.end()));

    round=2;
    bid_pot=0;
    person1=Person();
    person2=Person();
    ui->money1->setText(QString::number(1000));
    ui->money1->setStyleSheet("QLabel{color:yellow;}");
    ui->money2->setText(QString::number(1000));
    ui->money2->setStyleSheet("QLabel{color:yellow;}");

    //Pick the one who bid first:
    int random=rand()%10;
    if(random>=5) {ui->bid1->setText(QString::number(10)); person1.set_bid(10);person1.set_money(990);ui->money1->setText(QString::number(990));}
    else {ui->bid2->setText(QString::number(10)); person2.set_bid(10);person2.set_money(990);ui->money2->setText(QString::number(990));}
    ui->bid1->setStyleSheet("QLabel{color:yellow;}");
    ui->bid2->setStyleSheet("QLabel{color:yellow;}");

    //connections of buttons:
    QObject::connect(ui->fold1,SIGNAL(clicked()),this,SLOT(person2win()));
    QObject::connect(ui->fold2,SIGNAL(clicked()),this,SLOT(person1win()));
    QObject::connect(ui->raise1,SIGNAL(clicked()),this,SLOT(person1_add_bid()));
    QObject::connect(ui->raise2,SIGNAL(clicked()),this,SLOT(person2_add_bid()));
    QObject::connect(ui->check1,SIGNAL(clicked()),this,SLOT(a_round()));
    QObject::connect(ui->check2,SIGNAL(clicked()),this,SLOT(a_round()));
    QObject::connect(ui->again,SIGNAL(clicked()),this,SLOT(startover()));
    QObject::connect(ui->visible1,SIGNAL(clicked()),this,SLOT(visible1()));
    QObject::connect(ui->visible2,SIGNAL(clicked()),this,SLOT(visible2()));
    //first round:
    //one face down card:
    distribute_first();
    //one face up card:
   distribute_person1();
   distribute_person2();







}

void Show_Hand::player1_name(QString str){
   ui->player1->setText(str);
   ui->player1->setStyleSheet("QLabel{color:yellow;}");
   return;
}

void Show_Hand::player2_name(QString str){
    ui->player2->setText(str);
    ui->player2->setStyleSheet("QLabel{color:yellow;}");
    return;
}

void Show_Hand::person1_add_bid(){
    if(person1.get_money()>=50){
    person1.add_bid();
    int a=(ui->bid1->text()).toInt();
    ui->bid1->setText(QString::number(a+50));
    bid_pot=person1.get_bid()+person2.get_bid();
    //money influenced as well:
    person1.decrease_money();
    int b=(ui->money1->text()).toInt();
    ui->money1->setText(QString::number(b-50));
    }
    else{
        int a=(ui->bid1->text()).toInt();
        person1.set_bid(a+person1.get_money());
        ui->bid1->setText(QString::number(person1.get_bid()));
        bid_pot=person1.get_bid()+person2.get_bid();
        //money
        person1.set_money(0);
        ui->money1->setText(QString::number(0));
    }
    return;
}


void Show_Hand::person2_add_bid(){
    if(person2.get_money()>=50){
    person2.add_bid();
    int a=(ui->bid2->text()).toInt();
    ui->bid2->setText(QString::number(a+50));
    bid_pot=person1.get_bid()+person2.get_bid();
    //money influenced as well:
    person2.decrease_money();
    int b=(ui->money2->text()).toInt();
    ui->money2->setText(QString::number(b-50));
    }
    else{
        int a=(ui->bid2->text()).toInt();
        person2.set_bid(a+person2.get_money());
        ui->bid2->setText(QString::number(person2.get_bid()));
        bid_pot=person1.get_bid()+person2.get_bid();
        //money
        person2.set_money(0);
        ui->money2->setText(QString::number(0));
    }
    return;
}



void Show_Hand::distribute_person1(){
    person1.add_card(deck[deck.size()-1]);
    if(person1.handsize()==2){
    ui->suit7->setText(QString::fromStdString(person1.get_suit()));
    ui->rank7->setText(QString::fromStdString(person1.get_rank()));
    }
    else if(person1.handsize()==3){
        ui->suit8->setText(QString::fromStdString(person1.get_suit()));
        ui->rank8->setText(QString::fromStdString(person1.get_rank()));
        }
    else if(person1.handsize()==4){
        ui->suit9->setText(QString::fromStdString(person1.get_suit()));
        ui->rank9->setText(QString::fromStdString(person1.get_rank()));
        }
    else if(person1.handsize()==5){
        ui->suit10->setText(QString::fromStdString(person1.get_suit()));
        ui->rank10->setText(QString::fromStdString(person1.get_rank()));
        }
    deck.pop_back();
    return;
}

void Show_Hand::distribute_person2(){
    person2.add_card(deck[deck.size()-1]);
    if(person2.handsize()==2){
    ui->suit2->setText(QString::fromStdString(person2.get_suit()));
    ui->rank2->setText(QString::fromStdString(person2.get_rank()));
    }
    else if(person2.handsize()==3){
        ui->suit3->setText(QString::fromStdString(person2.get_suit()));
        ui->rank3->setText(QString::fromStdString(person2.get_rank()));
        }
    else if(person2.handsize()==4){
        ui->suit4->setText(QString::fromStdString(person2.get_suit()));
        ui->rank4->setText(QString::fromStdString(person2.get_rank()));
        }
    else if(person2.handsize()==5){
        ui->suit5->setText(QString::fromStdString(person2.get_suit()));
        ui->rank5->setText(QString::fromStdString(person2.get_rank()));
        }
    deck.pop_back();
    return;
}

void Show_Hand::distribute_first(){
    person1.add_card(deck[deck.size()-1]);
    deck.pop_back();
    ui->suit6->setText(QString::fromStdString("N/A"));
    ui->rank6->setText(QString::fromStdString("N/A"));
    person1.face_down();
    person2.add_card(deck[deck.size()-1]);
    deck.pop_back();
    ui->suit1->setText(QString::fromStdString("N/A"));
    ui->rank1->setText(QString::fromStdString("N/A"));
    person2.face_down();
    return;
}

void Show_Hand::person1win(){
    person1.set_money(person1.get_money()+bid_pot);
    ui->money1->setText(QString::number(person1.get_money()));
    startover();
    return;
}

void Show_Hand::person2win(){
    person2.set_money(person2.get_money()+bid_pot);
    ui->money2->setText(QString::number(person2.get_money()));
    startover();
    return;
}

void Show_Hand::startover(){
    ui->bid1->setText(QString::number(0));
    ui->bid2->setText(QString::number(0));
    person1.set_bid(0);
    person2.set_bid(0);
    bid_pot=0;

    ui->suit1->clear();ui->suit2->clear();ui->suit3->clear();ui->suit4->clear();
    ui->suit5->clear();ui->suit6->clear();ui->suit7->clear();ui->suit8->clear();
    ui->suit9->clear();ui->suit10->clear();

    ui->rank1->clear();ui->rank2->clear();ui->rank3->clear();ui->rank4->clear();
    ui->rank5->clear();ui->rank6->clear();ui->rank7->clear();ui->rank8->clear();
    ui->rank9->clear();ui->rank10->clear();

    ui->winner->clear();
    person1.resize();
    person2.resize();

    if(person1.get_money()!=0||person2.get_money()!=0){
        create_deck(deck);
        random_shuffle(deck.begin(),(deck.end()));
        distribute_first();

       distribute_person1();
       distribute_person2();
    }
    round=2;
    return;
}

void Show_Hand::a_round(){
    round++;
    if(person1.get_bid()>person2.get_bid()){
        person2.set_bid(person1.get_bid());
        ui->bid2->setText(QString::number(person2.get_bid()));
    }
    else{person1.set_bid(person2.get_bid());ui->bid1->setText(QString::number(person1.get_bid()));}
    bid_pot=person1.get_bid()+person2.get_bid();

    distribute_person1();
    distribute_person2();

    if(round==5){

        if(person1.get_hand()>person2.get_hand()){
            person1.set_money(person1.get_money()+bid_pot);
            ui->money1->setText(QString::number(person1.get_money()));
            ui->winner->setText("winner is player1!!!!");
            ui->winner->setStyleSheet("QLabel{color:red;}");
        }
        if(person2.get_hand()>person1.get_hand()){
            person2.set_money(person2.get_money()+bid_pot);
            ui->money2->setText(QString::number(person2.get_money()));
            ui->winner->setText("winner is player2!!!!");
            ui->winner->setStyleSheet("QLabel{color:red;}");
        }
        if(person1.get_hand()==person2.get_hand()){
            person1.set_money(person1.get_money()+person1.get_bid());
            person2.set_money(person2.get_money()+person2.get_bid());
            ui->money1->setText(QString::number(person1.get_money()));
            ui->money2->setText(QString::number(person2.get_money()));
            ui->winner->setText("It's a tie!!!!");
            ui->winner->setStyleSheet("QLabel{color:red;}");
        }


    }

return;
}

void Show_Hand::visible1(){
    if(ui->suit6->text()=="N/A"){
        ui->suit6->setText(QString::fromStdString((person1.get_hand())[0].get_suit()));
        ui->rank6->setText(QString::fromStdString((person1.get_hand())[0].get_rank()));
    }
    else{
         ui->suit6->setText("N/A");
         ui->rank6->setText("N/A");
    }
    return;
}

void Show_Hand::visible2(){
    if(ui->suit1->text()=="N/A"){
        ui->suit1->setText(QString::fromStdString((person2.get_hand())[0].get_suit()));
        ui->rank1->setText(QString::fromStdString((person2.get_hand())[0].get_rank()));
    }
    else{
         ui->suit1->setText("N/A");
         ui->rank1->setText("N/A");
    }
    return;
}

Show_Hand::~Show_Hand()
{
    delete ui;
}
