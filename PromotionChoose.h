#ifndef PROMOTIONCHOOSE_H
#define PROMOTIONCHOOSE_H


#include <QDialog>

namespace Ui {
class PromotionChoose;
}

class PromotionChoose : public QDialog
{
    Q_OBJECT

public:
    explicit PromotionChoose(QWidget *parent = nullptr);
    ~PromotionChoose();
    int chosenPiece;
    int getChosenPiece();

public slots:
    void on_Knight_clicked();

    void on_Bishop_clicked();

    void on_Rook_clicked();

    void on_Queen_clicked();

    void promote(bool);

signals:
    void sendResult(int);


private:
    bool turn;
    Ui::PromotionChoose *ui;
};

#endif // PROMOTIONCHOOSE_H
