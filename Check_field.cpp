#pragma once


bool check_field(std::vector<std::vector<Figure *>> field, Color my_color)
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
