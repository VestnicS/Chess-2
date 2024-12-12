#ifndef END_OF_GAME_CHECKS_H
#define END_OF_GAME_CHECKS_H
#include "Check_field.h"
static bool cant_move(std::vector<std::vector<Figure *>> field, Color my_color);
bool checkmate(std::vector<std::vector<Figure *>> field, Color my_color);
bool stalemate(std::vector<std::vector<Figure *>> field, Color my_color);
#endif // END_OF_GAME_CHECKS_H
