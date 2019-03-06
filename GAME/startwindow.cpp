#include "startwindow.h"
#include "ui_startwindow.h"

#include<QObject>

startwindow::startwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startwindow)
{
    ui->setupUi(this);
    QObject::connect(ui->start,SIGNAL(clicked()),this,SLOT(displaygame()));

}

void startwindow::displaygame(){
  showhand=new Show_Hand();
  showhand->player1_name(ui->player1->toPlainText());
  showhand->player2_name(ui->player2->toPlainText());


    this->hide();


    showhand->show();
    return;
}


startwindow::~startwindow()
{
    delete ui;
}
