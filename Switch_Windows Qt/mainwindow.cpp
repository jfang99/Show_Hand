#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    secwindow=new secondwindow();
    QObject::connect(ui->start,SIGNAL(clicked()),this,SLOT(showsecond()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

