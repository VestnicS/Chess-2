#include "Horse.cpp"
#include "King.cpp"
#include "Queen.cpp"
#include "Rock.cpp"
#include "Bishop.cpp"
#include "End_of_game_checks.cpp"
Game::Game()
{
    coordinates_old = {-1, -1};
    field = {
        {new Rock(Black), new Horse(Black), new Bishop(Black), new Queen(Black), new King(Black), new Bishop(Black), new Horse(Black), new Rock(Black)},
        {new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black)},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, new King(Black), nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White)},
        {new Rock(White), new Horse(White), new Bishop(White), new King(White), new Queen(White), new Bishop(White), new Horse(White), new Rock(White)},
    }; /*{
         {new Rock(Black), new Horse(Black), new Bishop(Black), new Queen(Black), new King(Black), new Bishop(Black), new Horse(Black), new Rock(Black)},
         {new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black), new Pawn(Black)},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
         {new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White), new Pawn(White)},
         {new Rock(White), new Horse(White), new Bishop(White), new King(White), new Queen(White), new Bishop(White), new Horse(White), new Rock(White)},
     };*/
}

void Game::test()
{
<<<<<<< HEAD
    std::cout << checkmate(field, Black) << std::endl;
    for (auto i : future_go({6, 0}))
=======
    for (auto i : future_go({0, 0}))
>>>>>>> 734c7a900b80a5b91faf344939feb7b38a592bd2
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
    int x0 = coordinates_old.first;
    int y0 = coordinates_old.second;
    int x1 = coordinates_new.first;
    int y1 = coordinates_new.second;
    if (field[x0][y0]->name() == "King" && field[x0][y0]->start && (y1 - y0) == 2)
    {
        field[x1][y1] = field[x0][y0];
        field[x0][y0] = nullptr;
        // не до конца
    }
    else if (field[x0][y0]->name() == "Pawn" && (x1 == 7 || y1 == 0))
    {
        field[x0][y0] = nullptr;
        field[x1][y1] = nullptr; // call func
    }
    else
    {
        field[x1][y1] = field[x0][y0];
        field[x0][y0] = nullptr;
    }
    field[x1][y1]->start = false;
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