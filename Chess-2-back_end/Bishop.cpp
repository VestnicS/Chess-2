#include "Bishop.h"

Bishop::Bishop(Color new_color)
{
    color = new_color;
    start = true;
}

std::string Bishop::name() { return "Bishop"; }

Color Bishop::figure_color() { return color; }

std::vector<std::pair<int, int>> Bishop::go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::pair<int, int>> possible_moves;

    for (int i = 1; i < 8; i++)
    {
        if (x - i >= 0 && x - i <= 7 && y - i >= 0 && y - i <= 7)
        {
            if (field[x - i][y - i])
            {
                if (field[x - i][y - i]->figure_color() != field[x][y]->figure_color())
                {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x - i;
                    possible_pair.second = y - i;
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x - i][y - i] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color())) {
                        possible_moves.push_back(possible_pair);
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x - i][y - i] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x - i;
                    possible_pair.second = y - i;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x - i >= 0 && x - i <= 7 && y + i >= 0 && y + i <= 7)
        {
            if (field[x - i][y + i])
            {
                if (field[x - i][y + i]->figure_color() != field[x][y]->figure_color())
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x - i][y + i] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color())) {
                        std::pair<int, int> possible_pair;
                        possible_pair.first = x - i;
                        possible_pair.second = y + i;
                        possible_moves.push_back(possible_pair);
                    }
                        break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x - i][y + i] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x - i;
                    possible_pair.second = y + i;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x + i >= 0 && x + i <= 7 && y + i >= 0 && y + i <= 7)
        {
            if (field[x + i][y + i])
            {
                if (field[x + i][y + i]->figure_color() != field[x][y]->figure_color())
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x + i][y + i] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color())) {
                        std::pair<int, int> possible_pair;
                        possible_pair.first = x + i;
                        possible_pair.second = y + i;
                        possible_moves.push_back(possible_pair);
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x + i][y + i] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x + i;
                    possible_pair.second = y + i;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x + i >= 0 && x + i <= 7 && y - i >= 0 && y - i <= 7)
        {
            if (field[x + i][y - i])
            {
                if (field[x + i][y - i]->figure_color() != field[x][y]->figure_color())
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x + i][y - i] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color()))
                    {
                        std::pair<int, int> possible_pair;
                        possible_pair.first = x + i;
                        possible_pair.second = y - i;
                        possible_moves.push_back(possible_pair);
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x + i][y - i] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x + i;
                    possible_pair.second = y - i;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
    }

    return possible_moves;
}

bool Bishop::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::pair<int, int>> possible_moves;

    for (int i = 1; i < 8; i++)
    {
        if (x - i >= 0 && x - i <= 7 && y - i >= 0 && y - i <= 7)
        {
            if (field[x - i][y - i])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - i;
                possible_pair.second = y - i;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - i;
                possible_pair.second = y - i;
                possible_moves.push_back(possible_pair);
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x - i >= 0 && x - i <= 7 && y + i >= 0 && y + i <= 7)
        {
            if (field[x - i][y + i])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - i;
                possible_pair.second = y + i;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - i;
                possible_pair.second = y + i;
                possible_moves.push_back(possible_pair);
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x + i >= 0 && x + i <= 7 && y + i >= 0 && y + i <= 7)
        {
            if (field[x + i][y + i])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + i;
                possible_pair.second = y + i;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + i;
                possible_pair.second = y + i;
                possible_moves.push_back(possible_pair);
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x + i >= 0 && x + i <= 7 && y - i >= 0 && y - i <= 7)
        {
            if (field[x + i][y - i])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + i;
                possible_pair.second = y - i;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + i;
                possible_pair.second = y - i;
                possible_moves.push_back(possible_pair);
            }
        }
    }
    for (auto i : possible_moves)
    {
        x = i.first;
        y = i.second;
        if (field[x][y]) {
            if (field[x][y]->name() == "King" && field[x][y]->figure_color() == my_color)
            {
                return true;
            }
        }
    }
    return false;
}
