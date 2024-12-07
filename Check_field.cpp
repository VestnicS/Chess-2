#pragma once
#include "Horse.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rock.h"
#include "King.h"
#include "Bishop.h"

bool Horse::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    for (int i = -2; i < 3; i++)
    {
        for (int j = -2; j < 3; j++)
        {
            if (x + i >= 0 && x + i < 8 && y + j >= 0 && y + j < 8 && abs(i) != abs(j) && i != 0 && j != 0)
            {
                if (field[x + i][y + j] != nullptr)
                {
                    if (field[x + i][y + j]->name() == "King" && field[x + i][y + j]->figure_color() == my_color)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool King::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) { return false; }

bool Queen::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) { return false; }

bool Pawn::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) { return false; }

bool Rock::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) { return false; }

bool Bishop::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) { return false; }

static bool check_field(std::vector<std::vector<Figure *>> field, Color my_color)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (field[i][j] != nullptr)
            {
                if (field[i][j]->figure_color() != my_color)
                {
                    if (field[i][j]->check(field, my_color, {i, j}))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
