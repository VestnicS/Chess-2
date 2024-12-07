/*#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gw.setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newgame_clicked()
{
    this->hide();
    gw.exec();
    this->show();
}*/
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

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainMenu::onImageDownloaded);

    QUrl imageUrl("https://sun6-23.userapi.com/s/v1/if1/xG395u9_7kvwR_aMMVUSTmkvugaqBzYLr0X8EB8p5Qj_5Gf-TO9cwSduji5O7aqhx_njeatq.jpg?size=449x449&quality=96&crop=154,0,449,449&ava=1");
    networkManager->get(QNetworkRequest(imageUrl));

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
        this->hide();
        gameWindow.exec();
        this->show();
    }


void MainMenu::onImageDownloaded(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QImage image;
        image.loadFromData(reply->readAll());
        backgroundLabel->setPixmap(QPixmap::fromImage(image));
    } else {
        qDebug() << "Ошибка загрузки изображения:" << reply->errorString();
    }
    reply->deleteLater();
}

void MainMenu::onExitButtonClicked() {
    this->close(); // Закрываем главное меню
}

