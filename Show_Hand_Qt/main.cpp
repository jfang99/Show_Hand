#include "show_hand.h"
#include"startwindow.h"
#include"Card.h"
#include <QApplication>
#include<ctime>
#include<cstdlib>
#include<vector>

using std::vector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    startwindow i;
    i.show();


    return a.exec();
}
