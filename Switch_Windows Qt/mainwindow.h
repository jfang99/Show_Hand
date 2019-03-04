#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"secondwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showsecond(){
        this->hide();
        secwindow->show();
    }


private:
    Ui::MainWindow *ui;
    secondwindow* secwindow;

};

#endif // MAINWINDOW_H
