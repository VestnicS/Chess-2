

#include "Game.h"
#include "Pawn.cpp"
#include "Horse.cpp"
#include "King.cpp"
#include "Queen.cpp"
#include "Rock.cpp"
#include "Bishop.cpp"

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
        {new Rock(White), new Horse(White), new Bishop(White), new King(White), new Queen(White), new Bishop(White), new Horse(White), new Rock(White)},
    };
}

void Game::test()
{
    for (auto i : future_go({4, 3}))
    {
        std::cout << i.first << ' ' << i.second << std::endl;
    }
}

std::vector<std::pair<int, int>> Game::future_go(std::pair<int, int> coordinates)
{
    coordinates_old = coordinates;
    return field[coordinates.first][coordinates.second]->go(field, coordinates);
}

void Game::move(std::pair<int, int> coordinates_new)
{
    field[coordinates_new.first][coordinates_new.second] = field[coordinates_old.first][coordinates_old.second];
    field[coordinates_old.first][coordinates_old.second] = nullptr;
}
void Game::print()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (field[i][j] == nullptr)
            {
                std::cout << "0000" << ' ';
            }
            else
            {
                std::cout << field[i][j]->name() << ' ';
            }
        }
        std::cout << std::endl;
    }
}