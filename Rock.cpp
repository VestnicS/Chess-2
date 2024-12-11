

#include "Check_field.cpp"

Rock::Rock(Color new_color)
{
    color = new_color;
    start = true;
}
std::string Rock::name() { return "Rock"; }
Color Rock::figure_color() { return color; }
std::vector<std::pair<int, int>> Rock::go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::pair<int, int>> possible_moves;
    for (int i = 1; i < 8; i++)
    {
        if (x + i >= 0 && x + i <= 7 && y >= 0 && y <= 7)
        {
            if (field[x + i][y])
            {
                if (field[x + i][y]->figure_color() != field[x][y]->figure_color())
                {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x + i;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                    break;
                }
                else
                {
                    break;
                }
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
        if (x - i >= 0 && x - i <= 7 && y >= 0 && y <= 7)
        {
            if (field[x - i][y])
            {
                if (field[x - i][y]->figure_color() != field[x][y]->figure_color())
                {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x - i;
                    possible_pair.second = y;
                    possible_moves.push_back(possible_pair);
                    break;
                }
                else
                {
                    break;
                }
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
        if (x >= 0 && x <= 7 && y + i >= 0 && y + i <= 7)
        {
            if (field[x][y + i])
            {
                if (field[x][y + i]->figure_color() != field[x][y]->figure_color())
                {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x;
                    possible_pair.second = y + i;
                    possible_moves.push_back(possible_pair);
                    break;
                }
                else
                {
                    break;
                }
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
        if (x >= 0 && x <= 7 && y - i >= 0 && y - i <= 7)
        {
            if (field[x][y - i])
            {
                if (field[x][y - i]->figure_color() != field[x][y]->figure_color())
                {
                    std::pair<int, int> possible_pair;
                    possible_pair.first = x;
                    possible_pair.second = y - i;
                    possible_moves.push_back(possible_pair);
                    break;
                }
                else
                {
                    break;
                }
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
    return possible_moves;
}