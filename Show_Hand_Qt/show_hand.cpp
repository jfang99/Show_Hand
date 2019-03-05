#include "show_hand.h"
#include "ui_show_hand.h"
#include"startwindow.h"
#include"Card.h"
#include"Person.h"

#include<QString>
#include<QLabel>

Show_Hand::Show_Hand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Show_Hand)
{
    ui->setupUi(this);
    vector<Card> deck;
    create_deck(deck);
    Person person1;
    Person person2;
    ui->money1->setText(QString::number(1000));
    ui->money1->setStyleSheet("QLabel{backgroundcolor:purple;color:yellow;}");
    ui->money2->setText(QString::number(1000));
    ui->money2->setStyleSheet("QLabel{backgroundcolor:purple;color:yellow;}");

}

void Show_Hand::player1_name(QString str){
   ui->player1->setText(str);
   ui->player1->setStyleSheet("QLabel{backgroundcolor:purple;color:yellow;}");
   return;
}

void Show_Hand::player2_name(QString str){
    ui->player2->setText(str);
    ui->player2->setStyleSheet("QLabel{backgroundcolor:purple;color:yellow;}");
    return;
}

Show_Hand::~Show_Hand()
{
    delete ui;
}
