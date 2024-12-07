

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Figure.h"

class Bishop : public Figure
{
    Color color;

public:
    bool start;
    explicit Bishop(Color new_color);
    std::string name() override;
    Color figure_color() override;
    bool check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) override;
    std::vector<std::pair<int, int>> go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates) override;
};

#endif // CHESS_BISHOP_H