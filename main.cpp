#include "mainwindow.h"
#include"gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.setFixedSize(800,800);
    w.show();
    return a.exec();
}
