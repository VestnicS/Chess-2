#include "Figure.h"
#include "Check_field.cpp"
static bool cant_move(std::vector<std::vector<Figure *>> field, Color my_color)
{
    int moves_count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (field[i][j] != nullptr)
            {
                if (field[i][j]->figure_color() != my_color)
                {
                    moves_count += (field[i][j]->go(field, {i, j})).size();
                }
            }
        }
    }
    if (moves_count == 0)
    {
        return true;
    }
    return false;
}

bool checkmate(std::vector<std::vector<Figure *>> field, Color my_color)
{
    if (cant_move(field, my_color) && check_field(field, my_color))
    {
        return true;
    }
    return false;
}

bool stalemate(std::vector<std::vector<Figure *>> field, Color my_color)
{
    if (cant_move(field, my_color) && (!check_field(field, my_color)))
    {
        return true;
    }
    return false;
}