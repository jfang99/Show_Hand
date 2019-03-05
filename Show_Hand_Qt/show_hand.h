

#ifndef SHOW_HAND_H
#define SHOW_HAND_H

#include <QMainWindow>
#include<string>
using namespace std;
class startwindow;

namespace Ui {
class Show_Hand;
}

class Show_Hand : public QMainWindow
{
    Q_OBJECT


public:
    explicit Show_Hand(QWidget *parent = nullptr);
    ~Show_Hand();

    void player1_name(QString str);
    void player2_name(QString str);
private:
    Ui::Show_Hand *ui;
};

#endif // SHOW_HAND_H
