#ifndef HORSE_H
#define HORSE_H

#include "Check_field.h"

class Horse : public Figure
{
    Color color;

public:
    bool start;
    explicit Horse(Color new_color);
    std::string name() override;
    Color figure_color() override;
    bool check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) override;
    std::vector<std::pair<int, int>> go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates) override;
};

#endif