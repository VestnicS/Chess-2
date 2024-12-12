
#include "King.h"

King::King(Color new_color)
{
    King::color = new_color;
    King::start = true;
}
std::string King::name()
{
    return "King";
}
Color King::figure_color() { return King::color; }
std::vector<std::pair<int, int>> King::go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::vector<Figure *>> new_field = field;

    std::vector<std::pair<int, int>> future_go_arr;
    if (King::start && !check_field(field, King::color)) // Rockirovka
    {
        for (int i = y + 1; i < 8; i++)
        {
            if (field[x][i] == nullptr)
            {
            }
            else
            {
                if (field[x][i]->name() == "Rock")
                {
                    if (field[x][i]->start && field[x][i]->figure_color() == King::color)
                    {

                        if (y == 4)
                        {
                            new_field[x][6] = new_field[x][y];
                            new_field[x][y] = nullptr;
                            new_field[x][5] = new_field[x][7];
                            new_field[x][7] = nullptr;
                            if (!check_field(new_field, King::color))
                            {
                                future_go_arr.push_back({x, 6});
                            }
                        }
                        if (y == 3)
                        {
                            new_field = field;
                            new_field[x][5] = new_field[x][y];
                            new_field[x][y] = nullptr;
                            new_field[x][4] = new_field[x][7];
                            new_field[x][7] = nullptr;
                            if (!check_field(new_field, King::color))
                            {
                                future_go_arr.push_back({x, 5});
                            }
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        for (int i = y - 1; i >= 0; i--)
        {
            if (field[x][i] == nullptr)
            {
            }
            else
            {
                if (field[x][i]->name() == "Rock")
                {
                    if (field[x][i]->start && field[x][i]->figure_color() == King::color)
                    {
                        if (y == 4)
                        {
                            new_field[x][2] = new_field[x][y];
                            new_field[x][y] = nullptr;
                            new_field[x][3] = new_field[x][0];
                            new_field[x][0] = nullptr;
                            if (!check_field(new_field, King::color))
                            {
                                future_go_arr.push_back({x, 2});
                            }
                        }
                        if (y == 3)
                        {
                            new_field[x][1] = new_field[x][y];
                            new_field[x][y] = nullptr;
                            new_field[x][2] = new_field[x][0];
                            new_field[x][0] = nullptr;
                            if (!check_field(new_field, King::color))
                            {
                                future_go_arr.push_back({x, 1});
                            }
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (x + i < 8 && x + i >= 0 && y + j < 8 && y + j >= 0 && !(i == 0 && j == 0))
            {
                new_field = field;
                new_field[x + i][y + j] = new_field[x][y];
                new_field[x][y] = nullptr;
                if (field[x + i][y + j] == nullptr)
                {
                    if (!check_field(new_field, King::color))
                    {
                        future_go_arr.push_back({x + i, y + j});
                    }
                }
                else
                {
                    if (field[x + i][y + j]->figure_color() != King::color)
                    {
                        if (!check_field(new_field, King::color))
                        {
                            future_go_arr.push_back({x + i, y + j});
                        }
                    }
                }
            }
        }
    }
    return future_go_arr;
}

bool King::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates) { return false; }
