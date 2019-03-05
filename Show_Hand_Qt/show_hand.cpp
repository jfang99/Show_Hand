#include "show_hand.h"
#include "ui_show_hand.h"

Show_Hand::Show_Hand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Show_Hand)
{
    ui->setupUi(this);
}

Show_Hand::~Show_Hand()
{
    delete ui;
}
