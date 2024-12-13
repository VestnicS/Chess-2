#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
#include "BoardWindow.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT
public:
    BoardWidget *board;
    QString ip;
    Ui::GameWindow *ui;
    void setPname(const QString name);
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
private slots:
    void on_exit_clicked();
};
#endif // GAMEWINDOW_H
