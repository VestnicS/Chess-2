

#include "Check_field.cpp"

Queen::Queen(Color new_color) { color = new_color; }
std::string Queen::name() { return "Queen"; }
Color Queen::figure_color() { return color; }
std::vector<std::pair<int, int>> Queen::go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::pair<int, int>> possible_moves;

    for (int i = 1; i < 8; i++)
    {
        if (x + i >= 0 and x + i <= 7 and y >= 0 and y <= 7)
        {
            if (field[x + i][y])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + i;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x + i;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x - i >= 0 and x - i <= 7 and y >= 0 and y <= 7)
        {
            if (field[x - i][y])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - i;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x - i;
                possible_pair.second = y;
                possible_moves.push_back(possible_pair);
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x >= 0 and x <= 7 and y + i >= 0 and y + i <= 7)
        {
            if (field[x][y + i])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x;
                possible_pair.second = y + i;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x;
                possible_pair.second = y + i;
                possible_moves.push_back(possible_pair);
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x >= 0 and x <= 7 and y - i >= 0 and y - i <= 7)
        {
            if (field[x][y - i])
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x;
                possible_pair.second = y - i;
                possible_moves.push_back(possible_pair);
                break;
            }
            else
            {
                std::pair<int, int> possible_pair;
                possible_pair.first = x;
                possible_pair.second = y - i;
                possible_moves.push_back(possible_pair);
            }
        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (x - i >= 0 and x - i <= 7 and y - i >= 0 and y - i <= 7)
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
        if (x - i >= 0 and x - i <= 7 and y + i >= 0 and y + i <= 7)
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
        if (x + i >= 0 and x + i <= 7 and y + i >= 0 and y + i <= 7)
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
        if (x + i >= 0 and x + i <= 7 and y - i >= 0 and y - i <= 7)
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

    return possible_moves;
}