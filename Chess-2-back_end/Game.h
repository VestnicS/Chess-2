#ifndef GAME_H
#define GAME_H

#include "Figure.h"
#include <iostream>
#include "Pawn.h"
#include "Horse.h"
#include "King.h"
#include "Queen.h"
#include "Rock.h"
#include "Bishop.h"
#include "End_of_game_checks.h"
class Game
{
    std::pair<int, int> coordinates_old;
    std::vector<std::vector<Figure *>> field;

public:
    Game();
    std::vector<std::pair<int, int>> future_go(std::pair<int, int> coordinates);
    void move(std::pair<int, int> coordinates_new);
    void pawnMove(std::pair<int, int> coordinates_new,int piece);
};
#endif
