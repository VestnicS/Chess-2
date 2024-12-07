#pragma once

#include <iostream>
#include <vector>

enum Color
{
    Black,
    White
};

class Figure
{
public:
    bool start;
    virtual std::string name() = 0;
    virtual Color figure_color() = 0;
    virtual bool check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) = 0;          // Checking that the figure cuts down the king
    virtual std::vector<std::pair<int, int>> go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates) = 0; // where the figure can go
};
