

#ifndef SHOW_HAND_H
#define SHOW_HAND_H

#include <QMainWindow>
#include<string>
#include"Person.h"

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


    void distribute_person1();
    void distribute_person2();
    void distribute_first();
    void startover();
public slots:
    void person1_add_bid();
    void person2_add_bid();
    void person1win();
    void person2win();
    void a_round();


private:
    Ui::Show_Hand *ui;
    vector<Card>deck;
    Person person1;
    Person person2;
    int bid_pot;
    bool gameend;
    bool roundend;
    bool end;
};

#endif // SHOW_HAND_H
