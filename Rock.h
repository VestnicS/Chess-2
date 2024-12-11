#ifndef ROCK_H
#define ROCK_H

#include "Figure.h"

class Rock : public Figure
{
    Color color;

public:
    bool start;
    explicit Rock(Color new_color);
    std::string name() override;
    Color figure_color() override;
    bool check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) override;
    std::vector<std::pair<int, int>> go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates) override;
};

#endif
