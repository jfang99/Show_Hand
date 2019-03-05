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

startwindow::~startwindow()
{
    delete ui;
}
