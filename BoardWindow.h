#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H
#include<QDir>
#include<QWidget>
#include<QLabel>
#include<QMouseEvent>
#include<Qstring>
#include"Chess-2-back_end/Game.h"
#include "myclient.h"
#include "myserver.h"

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
    QString ip;
    QString path;
    bool CanMove=false;
public:
    std::vector<std::pair<int,int>> painted;
    std::vector<std::pair<int,int>> PaintPossibleCells(std::vector<std::pair<int,int>>);
    QString name;
    void setIp(QString _ip,QString _name);
    void UnpaintPossibleCells(std::vector<std::pair<int,int>>);
    explicit BoardWidget(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void move(std::pair<int,int>);
    int turn;
    int counter=0;
    void handlePromotionResult(int);
private:
    QString getPiecePicPath(int m);
    QTcpSocket *_sok;
    quint16 _blockSize;
    MyClient* me;
    Game game;
signals:
     void sendStatus(int);
     void sendTurn(bool);
     void sendMove(const QPoint &from, const QPoint &to);
public slots:
    void setBoard(int *const *const piece = nullptr, int status = 0, int turn = 1);

private slots:
    void onSokConnected();
    void onSokDisconnected();
    void onSokReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);
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
        {-4, -2,  -3, -5, -6, -3,  -2,  -4},
        {-1, -1,  -1, -1, -1, -1,  -1,  -1},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {1, 1,  1, 1, 1, 1,  1, 1},
        {4, 2,  3, 5, 6, 3,  2, 4}
    };
    bool moveByClick{false};
private:
    const int CurrPiecePositionr[8][8]{
        {-4, -3,  -2, -5, -6, -3,  -2,  -4},
        {-1, -1,  -1, -1, -1, -1,  -1,  -1},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {0, 0,  0, 0, 0, 0,  0,  0},
        {1, 1,  1, 1, 1, 1,  1, 1},
        {4, 2,  3, 5, 6, 3,  2, 4}
    };
};
#endif // BOARDWINDOW_H
