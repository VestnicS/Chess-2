#include "gamewindow.h"
#include "ui_gamewindow.h"
#include"BoardWindow.h"
#include"mainwindow.h"
GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{

    ui->setupUi(this);


}
void GameWindow::setPname(const QString name)
{
    board = new BoardWidget(ui->chessboard_frame);
    board->setIp(ip,name);
    auto geom = board->geometry();
    geom.setX(0); geom.setY(0);
    board->setGeometry(geom);
}

GameWindow::~GameWindow()
{
    delete ui;
    delete board;
}


void GameWindow::on_exit_clicked()
{
    this->close();
    board=new BoardWidget(ui->chessboard_frame);

}

