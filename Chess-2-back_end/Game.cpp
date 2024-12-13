
#include "Game.h"

Game::Game()
{
    coordinates_old = {-1, -1};
    field = {
         {new Rock(Black), new Horse(Black), new Bishop(Black), new Queen(Black), new King(Black), new Bishop(Black), new Horse(Black), new Rock(Black)},
         {new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black)},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White)},
         {new Rock(White), new Horse(White), new Bishop(White), new Queen(White), new King(White), new Bishop(White), new Horse(White), new Rock(White)},
     };
}

std::vector<std::pair<int, int>> Game::future_go(std::pair<int, int> coordinates)
{
    coordinates_old = coordinates;
    if(field[coordinates.first][coordinates.second] == nullptr)
        return {{}};
    return field[coordinates.first][coordinates.second]->go(field, coordinates);
}

void Game::move(std::pair<int, int> coordinates_new)
{
    int x0 = coordinates_old.first;
    int y0 = coordinates_old.second;
    int x1 = coordinates_new.first;
    int y1 = coordinates_new.second;
    if (field[x0][y0]->name() == "King" && field[x0][y0]->start && (y1 - y0) == 2)
    {
        field[x1][y1] = field[x0][y0];
        field[x0][y0] = nullptr;
        field[x1][y1-1]=field[x0][7];
        field[x0][7]=nullptr;
    }
    else if (field[x0][y0]->name() == "King" && field[x0][y0]->start && (y1 - y0) == -2)
    {
        field[x1][y1] = field[x0][y0];
        field[x0][y0] = nullptr;
        field[x1][y1+1]=field[x0][0];
        field[x0][0]=nullptr;
    }
    else
    {
        field[x1][y1] = field[x0][y0];
        field[x0][y0] = nullptr;
    }
    field[x1][y1]->start = false;
}
void Game::pawnMove(std::pair<int, int> coordinates_new,int piece)
{
    int x0 = coordinates_old.first;
    int y0 = coordinates_old.second;
    int x1 = coordinates_new.first;
    int y1 = coordinates_new.second;
    switch(piece) {
    case 2:
        field[x1][y1]=new Horse(White);
        break;
    case -2:
        field[x1][y1]=new Horse(Black);
        break;
    case 3:
        field[x1][y1]=new Bishop(White);
        break;
    case -3:
        field[x1][y1]=new Bishop(Black);
        break;
    case 4:
        field[x1][y1]=new Rock(White);
        break;
    case -4:
        field[x1][y1]=new Rock(Black);
        break;
    case 5:
        field[x1][y1]=new Queen(White);
        break;
    case -5:
         field[x1][y1]=new Queen(Black);
        break;
    default:
        break;
    }


    field[x0][y0] = nullptr;

}
