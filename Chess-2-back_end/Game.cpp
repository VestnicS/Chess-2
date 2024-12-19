
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
    //МЕГА КОСТЫЛЬ
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if (field[i][j]){
                field[i][j]->start=true;
            }
        }
    }
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
    if (field[x0][y0]->name() == "King" && (y1 - y0) == 2)
    {
        field[x0][y0]->start=false;
        field[x0][7]->start=false;
        field[x1][y1] = field[x0][y0];
        field[x0][y0] = nullptr;
        field[x1][y1-1]=field[x0][7];
        field[x0][7]= nullptr;
    }
    else if (field[x0][y0]->name() == "King" &&  (y1 - y0) == -2)
    {
        field[x0][y0]->start=false;
        field[x0][0]->start=false;
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

bool Game::check_mate(Color color_my_figures) {
    return checkmate(field,color_my_figures);
}

bool Game::check_stalemate(Color color_my_figures) {
    return stalemate(field,color_my_figures);
}

void Game::opponent_move(std::pair<int,int> old_coordinates, std::pair<int,int> new_coordinates){
    int x0 = old_coordinates.first;
    int y0 = old_coordinates.second;
    int x1 = new_coordinates.first;
    int y1 = new_coordinates.second;
    field[x1][y1] = field[x0][y0];
    field[x0][y0] = nullptr;
}
