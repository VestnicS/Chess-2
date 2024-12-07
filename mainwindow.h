/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    GameWindow gw;
private slots:

    void on_newgame_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H*/
#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QImage>
#include <QDebug>
#include <QPropertyAnimation>
#include "gamewindow.h" // Включаем заголовок ChessBoard

class MainMenu : public QWidget {
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    void showMenu(); // Метод для отображения главного меню

private slots:
    void onPlayButtonClicked(); // Слот для обработки нажатия кнопки "Играть"
    void onImageDownloaded(QNetworkReply *reply);    // Слот для обработки загрузки изображения
    void onExitButtonClicked();

private:
    QPushButton *playButton;
    QPushButton *exitButton;
    QLabel *backgroundLabel;
    QNetworkAccessManager *networkManager;
    GameWindow gameWindow; // Указатель на шахматную доску
};

#endif // MAINMENU_H
