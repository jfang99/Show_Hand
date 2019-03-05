#include "show_hand.h"
#include"startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Show_Hand w;
    startwindow i;
    i.show();


    return a.exec();
}
