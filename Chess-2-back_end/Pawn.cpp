

#include "Pawn.h"


Pawn::Pawn(Color new_color)
{
    color = new_color;
    start = true;
}
std::string Pawn::name() { return "Pawn"; }
Color Pawn::figure_color() { return color; }
std::vector<std::pair<int, int>> Pawn::go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::pair<int, int>> possible_moves;
    if (color == Black)
    {
        if (x == 1)
        {
            if (!field[x + 1][y])
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x + 1][y] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x + 1;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                }
            }
            if (!field[x + 2][y] && !field[x+1][y])
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x + 2][y] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x + 2;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
        else
        {
            if (!field[x + 1][y])
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x + 1][y] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x + 1;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
        if (x + 1 >= 0 && x + 1 <= 7 && y + 1 >= 0 && y + 1 <= 7)
        {
            if (field[x + 1][y + 1])
            {
                if (field[x + 1][y + 1]->figure_color() != field[x][y]->figure_color())
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x + 1][y + 1] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color())) {
                        std::pair<int, int> possible_pair;
                        possible_pair.first = x + 1;
                        possible_pair.second = y + 1;
                        possible_moves.push_back(possible_pair);
                    }
                }
            }
        }
        if (x + 1 >= 0 && x + 1 <= 7 && y - 1 >= 0 && y - 1 <= 7)
        {
            if (field[x + 1][y - 1])
            {
                if (field[x + 1][y - 1]->figure_color() != field[x][y]->figure_color())
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x + 1][y - 1] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color())) {
                        std::pair<int, int> possible_pair;
                        possible_pair.first = x + 1;
                        possible_pair.second = y - 1;
                        possible_moves.push_back(possible_pair);
                    }
                }
            }
        }
    }

    else if (color == White)
    {
        if (x == 6)
        {
            if (!field[x - 1][y])
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x - 1][y] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x - 1;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                }
            }
            if (!field[x - 2][y] && !field[x-1][y])
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x - 2][y] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x - 2;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
        else
        {
            if (!field[x - 1][y])
            {
                std::vector<std::vector<Figure *>> field_new = field;
                field_new[x + 1][y] = field_new[x][y];
                field_new[x][y] = nullptr;
                if (!check_field(field_new, field[x][y]->figure_color())) {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x - 1;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                }
            }
        }
        if (x - 1 >= 0 && x - 1 <= 7 && y + 1 >= 0 && y + 1 <= 7)
        {
            if (field[x - 1][y + 1])
            {
                if (field[x - 1][y + 1]->figure_color() != field[x][y]->figure_color())
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x - 1][y + 1] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color())) {
                        std::pair<int, int> possible_pair;
                        possible_pair.first = x - 1;
                        possible_pair.second = y + 1;
                        possible_moves.push_back(possible_pair);
                    }
                }
            }
        }
        if (x - 1 >= 0 && x - 1 <= 7 && y - 1 >= 0 && y - 1 <= 7)
        {
            if (field[x - 1][y - 1])
            {
                if (field[x - 1][y - 1]->figure_color() != field[x][y]->figure_color())
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x - 1][y - 1] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color())) {
                        std::pair<int, int> possible_pair;
                        possible_pair.first = x - 1;
                        possible_pair.second = y - 1;
                        possible_moves.push_back(possible_pair);
                    }
                }
            }
        }
    }
    return possible_moves;
}


bool Pawn::check(std::vector<std::vector<Figure *>> field, Color my_color, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::pair<int, int>> possible_moves;

    if (color == Black)
    {
        if (x+1 >= 0 && x+1 <= 7 && y+1 >=0 && y+1 <= 7) {
            if (field[x + 1][y + 1])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + 1;
                possible_pair.second = y + 1;
                possible_moves.push_back(possible_pair);
            }
        }
        if (x+1 >= 0 && x+1 <= 7 && y-1 >=0 && y-1 <= 7) {
            if (!field[x + 1][y - 1])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + 1;
                possible_pair.second = y - 1;
                possible_moves.push_back(possible_pair);
            }
        }
    }

    else if (color == White)
    {
        if (x-1 >= 0 && x-1 <= 7 && y+1 >=0 && y+1 <= 7) {
            if (field[x - 1][y + 1])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - 1;
                possible_pair.second = y + 1;
                possible_moves.push_back(possible_pair);
            }
        }
        if (x-1 >= 0 && x-1 <= 7 && y-1 >=0 && y-1 <= 7) {
            if (!field[x - 1][y - 1])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - 1;
                possible_pair.second = y - 1;
                possible_moves.push_back(possible_pair);
            }
        }
    }
    for (auto i : possible_moves)
    {
        x = i.first;
        y = i.second;
        if (field[x][y])
        {
            if (field[x][y]->name() == "King" && field[x][y]->figure_color() == my_color)
            {
                return true;
            }
        }
    }
    return false;
}
