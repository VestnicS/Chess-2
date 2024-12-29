#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QUrl>
#include <QImage>
#include <QDebug>
#include "gamewindow.h" // Включаем заголовок ChessBoard
#include<QInputDialog>
#include<QResizeEvent>
class MainMenu : public QWidget {
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    void showMenu(); // Метод для отображения главного меню
    QString name;
    QString Ip;
    GameWindow gameWindow;
private slots:
    void onPlayButtonClicked(); // Слот для обработки нажатия кнопки "Играть"
    void onExitButtonClicked();

private:
    QPushButton *playButton;
    QPushButton *exitButton;
    QLabel *backgroundLabel;
     // Указатель на шахматную доску

};

#endif // MAINWINDOW
