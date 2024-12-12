cmake_minimum_required(VERSION 3.16)

project(CHESSSS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Обновлено: добавлен компонент Network
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network) # Обновлено

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CHESSSS
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        BoardWindow.h
        BoardWindow.cpp

        mainwindow.ui
        gamewindow.h gamewindow.cpp gamewindow.ui
        img/bishop-black.png img/bishop-white.png img/king-black.png img/king-white.png img/knight-black.png img/knight-white.png img/pawn-black.png img/pawn-white.png img/queen-black.png img/queen-white.png img/rook-black.png img/rook-white.png
        Status.h
        PromotionChoose.cpp
        PromotionChoose.h
        promotiondialog.ui

        Piece.h
        Chess-2-back_end/Bishop.cpp Chess-2-back_end/Bishop.h Chess-2-back_end/Check_field.cpp Chess-2-back_end/CMakeLists.txt Chess-2-back_end/End_of_game_checks.cpp Chess-2-back_end/Figure.h Chess-2-back_end/Game.cpp Chess-2-back_end/Game.h Chess-2-back_end/Horse.cpp Chess-2-back_end/Horse.h Chess-2-back_end/King.cpp Chess-2-back_end/King.h  Chess-2-back_end/Pawn.cpp Chess-2-back_end/Pawn.h Chess-2-back_end/Queen.cpp Chess-2-back_end/Queen.h Chess-2-back_end/Rock.cpp Chess-2-back_end/Rock.h
        Chess-2-back_end/Check_field.h
        Chess-2-back_end/End_of_game_checks.h
    )
else()
    if(ANDROID)
        add_library(CHESSSS SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(CHESSSS
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Обновлено: добавлено связывание с Qt Network
target_link_libraries(CHESSSS PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CHESSSS)
endif()
set_target_properties(CHESSSS PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CHESSSS
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CHESSSS)
endif()
