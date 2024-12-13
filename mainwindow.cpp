#include"gamewindow.h"
#include "mainwindow.h"
MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    playButton = new QPushButton("Играть", this);
    playButton->setStyleSheet("font-size: 40px;"
                              "QPushButton {background: gray;}");

    // Устанавливаем политику размера для кнопки
    playButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    exitButton = new QPushButton("Выйти", this);
    exitButton->setStyleSheet("font-size: 40px;"
                              "QPushButton {background: gray;}");

    // Устанавливаем политику размера для кнопки
    exitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    backgroundLabel = new QLabel(this);
    backgroundLabel->setScaledContents(true); // Масштабируем содержимое
    backgroundLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Позволяем фону занимать все пространство
    backgroundLabel->setPixmap(QString("img/FALT"));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(backgroundLabel); // Сначала добавляем фон

    // Создаем горизонтальный компоновщик для кнопок
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(playButton); // Добавляем кнопку "Играть"
    buttonLayout->addWidget(exitButton); // Добавляем кнопку "Выйти"
    buttonLayout->setAlignment(Qt::AlignCenter); // Выравниваем по центру

    layout->addLayout(buttonLayout); // Добавляем горизонтальный компоновщик в вертикальный
    setLayout(layout);

    connect(playButton, &QPushButton::clicked, this, &MainMenu::onPlayButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainMenu::onExitButtonClicked);

    gameWindow.setModal(true); // Изначально шахматная доска не создана
}

void MainMenu::onPlayButtonClicked() {

    bool ok;
    bool ok1=false;
    while(!ok1)
    Ip = QString(QInputDialog::getText(this, tr("Ip"),
                                       tr("Ip"), QLineEdit::Normal,
                                       QString(),&ok1));

    gameWindow.ip = Ip;


    while (name.isEmpty()||name.length()>12){
    name = QInputDialog::getText(this, tr("Введите имя,<12 символов"),
                                         tr("Имя:"), QLineEdit::Normal,
                                         QString(),&ok);
        if(!ok)
        break;
    }
    if (ok){

    const QString pname=name;
    gameWindow.setPname(pname);

    this->hide();
    gameWindow.exec();
    this->show();
    name="";
    }

}

void MainMenu::onExitButtonClicked() {
    this->close(); // Закрываем главное меню
}

