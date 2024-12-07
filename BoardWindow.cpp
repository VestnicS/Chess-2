#include "BoardWindow.h"
#include"PromotionChoose.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent) // turn == true - white
{
    color=-1;
    turn=-1;
    counter=0;
    this->setFixedSize(windowSize, windowSize);
    cells = new QLabel*[nCells];
    for (auto i = 0; i < nCells; ++i)
        cells[i] = new QLabel[nCells];

    for (int i = 0; i < nCells; ++i) {
        for (int j = (1 + i) % 2; j < nCells; j += 2)
            cells[i][j].setStyleSheet("QLabel { background-color : gray;}");
        for (int j = (i) % 2; j < nCells; j += 2)
            cells[i][j].setStyleSheet("QLabel { background-color : white;}");
    }

    for (int i = 0; i < nCells; ++i) {
        for (int j = 0; j < nCells; ++j) {
            cells[i][j].setParent(this);
            cells[i][j].setGeometry(i * cellSize, j * cellSize, cellSize, cellSize);
        }
    }
    currentPiecePosition=QPoint(-1,-1);
    isSelected=false;
    setBoard();
}

void BoardWidget::mousePressEvent(QMouseEvent *event){

    QPoint to{event->x()/cellSize, event->y()/cellSize};

    if (isSelected)
    {
        if (currentPiecePosition == to)
        {
            cells[currentPiecePosition.x()][currentPiecePosition.y()].setPixmap(
                QPixmap(getPiecePicPath(matrix[currentPiecePosition.x()][currentPiecePosition.y()]))
                    .scaled(cellSize, cellSize, Qt::KeepAspectRatio));
            UnpaintPossibleCells(painted);
            isSelected = false;
            currentPiecePosition = QPoint(-1, -1);
            this->setCursor(QCursor());
        }
        else
        {
            cells[currentPiecePosition.x()][currentPiecePosition.y()].setPixmap(
                QPixmap(getPiecePicPath(matrix[currentPiecePosition.x()][currentPiecePosition.y()]))
                    .scaled(cellSize, cellSize, Qt::KeepAspectRatio));
            UnpaintPossibleCells(painted);
            isSelected = false;
            this->setCursor(QCursor());
            move(std::make_pair(to.x(),to.y()));
        }

    }
    else
    {
        if(to.x() < 8 && to.y() < 8 && matrix[to.x()][to.y()] != 0)
        {
            if (matrix[to.x()][to.y()]>0 && (turn==1 && color==1)){
            movePoint.setX(to.x());
            movePoint.setY(to.y());

            // Получаем путь к изображению
            QString picPath = getPiecePicPath(matrix[to.x()][to.y()]);
            QPixmap pixmap(picPath);
            QPixmap scaledPixmap = pixmap.scaled(cellSize, cellSize, Qt::KeepAspectRatio);
            QCursor cursor(scaledPixmap);
            this->setCursor(cursor);
            currentPiecePosition = to;

            // Получаем возможные клетки для перемещения
            painted = PaintPossibleCells({std::make_pair(4,0)});
            isSelected = true; // Устанавливаем флаг выбора
            cells[to.x()][to.y()].clear(); // Убираем изображение фигуры с доски
            }

        }
        {
            if (matrix[to.x()][to.y()]<0 && turn==-1 && color==-1){
                movePoint.setX(to.x());
                movePoint.setY(to.y());

                // Получаем путь к изображению
                QString picPath = getPiecePicPath(matrix[to.x()][to.y()]);
                QPixmap pixmap(picPath);
                QPixmap scaledPixmap = pixmap.scaled(cellSize, cellSize, Qt::KeepAspectRatio);
                QCursor cursor(scaledPixmap);
                this->setCursor(cursor);
                currentPiecePosition = to;

                // Получаем возможные клетки для перемещения
                painted = PaintPossibleCells({std::make_pair(4,0),std::make_pair(4,7)});
                isSelected = true; // Устанавливаем флаг выбора
                cells[to.x()][to.y()].clear(); // Убираем изображение фигуры с доски
            }
    }
    }}

// Добавим новую функцию для обработки нажатий на пустые клетки
void BoardWidget::mouseReleaseEvent(QMouseEvent *event){
    if (moveByClick){
        this->setCursor(QCursor());
        moveByClick = false;
        return;
    }
    QPoint to{event->x()/cellSize, event->y()/cellSize};
    if (movePoint == to)
    {
        if(to.x() < 8 && to.y() < 8 && matrix[to.x()][to.y()] != 0)
        {
            moveByClick = true;
            QString picPath = getPiecePicPath(matrix[to.x()][to.y()]);
            QPixmap pixmap(picPath);
            QPixmap scaledPixmap = pixmap.scaled(cellSize, cellSize, Qt::KeepAspectRatio);
            QCursor cursor(scaledPixmap);
            this->setCursor(cursor);

        }
    }
    else
    {
        // Если нажали на пустую клетку, возвращаем начальные цвета
        UnpaintPossibleCells(painted);
        emit sendMove(movePoint, to);
        this->setCursor(QCursor());
    }
}





void BoardWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    mousePressEvent(event);
}

void BoardWidget::setBoard(int *const *const piece, int status, int turn)
{

    if(color==-1 && counter==0){
        for(int i=0;i<nCells;i++)
            for(int j=0;j<nCells;j++)
                CurrPiecePosition[nCells-i-1][nCells-j-1]=CurrPiecePositionr[i][j];
        counter=1;
    }
    if (piece)
    {
        for (int x = 0; x < nCells; ++x){
            for (int y = 0; y < nCells; ++y){
                if (CurrPiecePosition[x][y] != matrix[x][y])
                {
                    matrix[x][y] = CurrPiecePosition[x][y];
                    cells[x][y].setPixmap(QPixmap(getPiecePicPath(matrix[x][y])).scaled(cellSize,
                                                                                        cellSize,
                                                                                        Qt::KeepAspectRatio));
                }
            }
        }
    } else {
        for (int x = 0; x < nCells; ++x) {
            for (int y = 0; y < nCells; ++y){
                if (CurrPiecePosition[x][y] != matrix[x][y]) {
                    matrix[x][y] = CurrPiecePosition[x][y];
                    cells[x][y].setPixmap(QPixmap(getPiecePicPath(matrix[x][y])).scaled(cellSize,
                                                                                        cellSize,
                                                                                        Qt::KeepAspectRatio));
                }
        }
        }
    }
}

QString BoardWidget::getPiecePicPath(int m) {


        switch (m) {
        case 1: return QString("img/pawn-white.png");
        case 2: return QString("img/knight-white.png");
        case 3: return QString("img/bishop-white.png");
        case 4: return QString("img/rook-white.png");
        case 5: return QString("img/queen-white.png");
        case 6: return QString("img/king-white.png");

        case -1: return QString("img/pawn-black.png");
        case -2: return QString("img/knight-black.png");
        case -3: return QString("img/bishop-black.png");
        case -4: return QString("img/rook-black.png");
        case -5: return QString("img/queen-black.png");
        case -6: return QString("img/king-black.png");

        case 0:
        default: return QString(); // Возвращаем пустую строку вместо nullptr

    }
}
QVector<QPair<int,int>> BoardWidget::PaintPossibleCells(QVector<QPair<int,int>> vector)
{
    for (auto pcell:vector)
    {
        cells[pcell.first][pcell.second].setStyleSheet("QLabel { background-color : green;}");

    }
    return vector;
}
void BoardWidget::UnpaintPossibleCells(QVector<QPair<int,int>> vector)
{
    for (auto pcell:vector)
    {
        if((pcell.first+pcell.second)%2==0){
            cells[pcell.first][pcell.second].setStyleSheet("QLabel { background-color : white;}");
        }
        else
        {
            cells[pcell.first][pcell.second].setStyleSheet("QLabel { background-color : gray;}");
        }
    }
}
void BoardWidget::move(QPair<int,int> ToCell)
{
    for(auto pair:painted)
    {
        if (ToCell.first==pair.first && ToCell.second==pair.second)
        {
            CanMove=true;
            break;
        }
    }
    if (CanMove)
    {
        if (ToCell.second == 0 && CurrPiecePosition[currentPiecePosition.x()][currentPiecePosition.y()] == 1 && (turn==color))
        {
            PromotionChoose promotionDialogW;
            promotionDialogW.promote(true);
            CurrPiecePosition[ToCell.first][ToCell.second]=promotionDialogW.getChosenPiece();
            CurrPiecePosition[currentPiecePosition.x()][currentPiecePosition.y()]=0;

            turn=!turn;
            setBoard();
        }
        if (ToCell.second == 0 && CurrPiecePosition[currentPiecePosition.x()][currentPiecePosition.y()] == -1 && (turn==color))
        {
            PromotionChoose promotionDialogW;
            promotionDialogW.promote(false);
            CurrPiecePosition[ToCell.first][ToCell.second]=-promotionDialogW.getChosenPiece();
            CurrPiecePosition[currentPiecePosition.x()][currentPiecePosition.y()]=0;
            turn=!turn;
            setBoard();
        }
            else{
                if(CurrPiecePosition[currentPiecePosition.x()][currentPiecePosition.y()]!= 0 && (turn==color)){
        CurrPiecePosition[ToCell.first][ToCell.second]=CurrPiecePosition[currentPiecePosition.x()][currentPiecePosition.y()];
        CurrPiecePosition[currentPiecePosition.x()][currentPiecePosition.y()]=0;
        turn=!turn;
        setBoard();
                }
    }
    CanMove=false;


    }}
