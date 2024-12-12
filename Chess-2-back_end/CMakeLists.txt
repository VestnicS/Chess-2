cmake_minimum_required(VERSION 3.10)


project(Chess-2)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



set(SOURCES
        main.cpp
        Rock.cpp
        Queen.cpp
        Pawn.cpp
        King.cpp
        Horse.cpp
        Game.cpp
        Bishop.cpp
        Check_field.cpp
        end_of_game_checks.cpp
)

set(HEADERS
        Rock.h
        Queen.h
        Pawn.h
        King.h
        Horse.h
        Game.h
        Bishop.h
        Figure.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})