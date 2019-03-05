#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include"show_hand.h"
namespace Ui {
class startwindow;
}

class startwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit startwindow(QWidget *parent = nullptr);
    ~startwindow();
public slots:
    void displaygame(){
        this->hide();
        showhand=new Show_Hand();
        showhand->show();
        return;
    }
private:
    Ui::startwindow *ui;
    Show_Hand* showhand;
};

#endif // STARTWINDOW_H
