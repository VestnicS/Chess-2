#ifndef GAME_H
#define GAME_H

#include "Figure.h"
class Game
{
    std::pair<int, int> coordinates_old;
    std::vector<std::vector<Figure *>> field;

public:
    Game();
    std::vector<std::pair<int, int>> future_go(std::pair<int, int> coordinates);
    void move(std::pair<int, int> coordinates_new);
    void print();
};
#endif
