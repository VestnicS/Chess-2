#include "Check_field.cpp"

Horse::Horse(Color new_color)
{
    Horse::color = new_color;
    Horse::start = true;
}
std::string Horse::name() { return "Horse"; }
Color Horse::figure_color() { return Horse::color; }

std::vector<std::pair<int, int>> Horse::go(std::vector<std::vector<Figure *>> field, std::pair<int, int> coordinates)
{
    int x = coordinates.first;
    int y = coordinates.second;
    std::vector<std::pair<int, int>> future_go_arr;

    for (int i = -2; i < 3; i++)
    {
        for (int j = -2; j < 3; j++)
        {
            if (x + i >= 0 && x + i < 8 && y + j >= 0 && y + j < 8 && abs(i) != abs(j) && i != 0 && j != 0)
            {
                if (field[x + i][y + j] == nullptr)
                {
                    std::vector<std::vector<Figure *>> field_new = field;
                    field_new[x + i][y + j] = field_new[x][y];
                    field_new[x][y] = nullptr;
                    if (!check_field(field_new, field[x][y]->figure_color()))
                    {
                        future_go_arr.push_back({x + i, y + j});
                    }
                }
                else
                {
                    if (field[x + i][y + j]->figure_color() != Horse::color)
                    {
                        std::vector<std::vector<Figure *>> field_new = field;
                        field_new[x + i][y + j] = field_new[x][y];
                        field_new[x][y] = nullptr;
                        if (!check_field(field_new, field[x][y]->figure_color()))
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
