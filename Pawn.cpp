

#include "Check_field.cpp"

Pawn::Pawn(Color new_color) { color = new_color; }
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
                std::pair<int, int> possible_pair;
                possible_pair.first = x + 1;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
            if (!field[x + 2][y])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + 2;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
        }
        else
        {
            if (!field[x + 1][y])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + 1;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
        }
        if (field[x + 1][y + 1])
        {
            std::pair<int, int> possible_pair;
            possible_pair.first = x + 1;
            possible_pair.second = y + 1;
            possible_moves.push_back(possible_pair);
        }
        if (!field[x + 1][y - 1])
        {
            std::pair<int, int> possible_pair;
            possible_pair.first = x + 1;
            possible_pair.second = y - 1;
            possible_moves.push_back(possible_pair);
        }
    }

    else if (color == White)
    {
        if (x == 6)
        {
            if (!field[x - 1][y])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - 1;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
            if (!field[x - 2][y])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - 2;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
        }
        else
        {
            if (!field[x - 1][y])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - 1;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
        }
        if (field[x - 1][y + 1])
        {
            std::pair<int, int> possible_pair;
            possible_pair.first = x - 1;
            possible_pair.second = y + 1;
            possible_moves.push_back(possible_pair);
        }
        if (!field[x - 1][y - 1])
        {
            std::pair<int, int> possible_pair;
            possible_pair.first = x - 1;
            possible_pair.second = y - 1;
            possible_moves.push_back(possible_pair);
        }
    }

    return possible_moves;
}