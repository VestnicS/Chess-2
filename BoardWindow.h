#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include<QDir>
#include<QWidget>
#include<QLabel>
#include<QMouseEvent>
#include<Qstring>
class BoardWidget:public QWidget
{
    Q_OBJECT
    QPoint movePoint;
    QPoint currentPiecePosition;
    bool isSelected;
    int windowSize=800;
    int cellSize=100;
    int nCells=8;
    int color;
    QString path;
    bool CanMove=false;
public:
    QVector<QPair<int,int>> painted;
    QVector<QPair<int,int>> PaintPossibleCells(QVector<QPair<int,int>>);
    //void Move(QVector<QPair<int,int>>);
    void UnpaintPossibleCells(QVector<QPair<int,int>>);
    explicit BoardWidget(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void move(QPair<int,int>);
    int turn;
    int counter=0;
    void handlePromotionResult(int);
private:
    QString getPiecePicPath(int m);
signals:
     void sendStatus(int);
     void sendTurn(bool);
     void sendMove(const QPoint &from, const QPoint &to);
public slots:
    void setBoard(int *const *const piece = nullptr, int status = 0, int turn = 1);

public:
    QLabel **cells;
    int matrix[8][8]{
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

public:
    int CurrPiecePosition[8][8]{
        {-4, -1,  0, 0, 0, 0,  1,  4},
        {-2, -1,  0, 0, 0, 0,  1,  2},
        {-3, -1,  0, 0, 0, 0,  1,  3},
        {-5, -1,  0, 0, 0, 0,  1,  5},
        {-6, -1,  0, 0, 0, 0,  1,  6},
        {-3, -1,  0, 0, 0, 0,  1,  3},
        {-2, -1,  0, 0, 0, 0,  1,  2},
        {-4, -1,  0, 0, 0, 0,  1,  4}
    };
    bool moveByClick{false};
private:
   const int CurrPiecePositionr[8][8]{
        {-4, -1,  0, 0, 0, 0,  1,  4},
        {-2, -1,  0, 0, 0, 0,  1,  2},
        {-3, -1,  0, 0, 0, 0,  1,  3},
        {-5, -1,  0, 0, 0, 0,  1,  5},
        {-6, -1,  0, 0, 0, 0,  1,  6},
        {-3, -1,  0, 0, 0, 0,  1,  3},
        {-2, -1,  0, 0, 0, 0,  1,  2},
        {-4, -1,  0, 0, 0, 0,  1,  4}
    };
};
#endif // BOARDWINDOW_H
