#include "PromotionChoose.h"
#include "ui_promotiondialog.h"

PromotionChoose::PromotionChoose(QWidget *parent):
    QDialog(parent),
    ui(new Ui::PromotionChoose)
{
    ui->setupUi(this);
    ui->Rook->resize(100, 100);
    ui->Knight->resize(100, 100);
    ui->Bishop->resize(100, 100);
    ui->Queen->resize(100, 100);
}

PromotionChoose::~PromotionChoose()
{
    delete ui;
}

void PromotionChoose::promote(bool isWhite)
{
    if (isWhite==true){
        ui->Rook->setStyleSheet("border-image:url(img/rook-white.png);");
        ui->Bishop->setStyleSheet("border-image:url(img/bishop-white.png);");
        ui->Knight->setStyleSheet("border-image:url(img/knight-white.png);");
        ui->Queen->setStyleSheet("border-image:url(img/queen-white.png);");
    }else{
        ui->Rook->setStyleSheet("border-image:url(img/rook-black.png);");
        ui->Bishop->setStyleSheet("border-image:url(img/bishop-black.png);");
        ui->Knight->setStyleSheet("border-image:url(img/knight-black.png);");
        ui->Queen->setStyleSheet("border-image:url(img/queen-black.png);");
    }
    exec();
}

int PromotionChoose::getChosenPiece() {
    return chosenPiece;
}

void PromotionChoose::on_Knight_clicked()
{
    chosenPiece = 2;
    close();
}

void PromotionChoose::on_Bishop_clicked()
{
    chosenPiece = 3;
    close();
}

void PromotionChoose::on_Rook_clicked()
{
    chosenPiece = 4;
    close();
}

void PromotionChoose::on_Queen_clicked()
{
    chosenPiece = 5;
    close();
}
