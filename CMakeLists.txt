cmake_minimum_required(VERSION 3.30)
project(chesslast)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.2/mingw_64")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network) # Обновлено
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(chesslast
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
        add_library(chesslast SHARED
                ${PROJECT_SOURCES}
        )
    else()
        add_executable(chesslast
                ${PROJECT_SOURCES}
        )
    endif()
endif()

# Обновлено: добавлено связывание с Qt Network
target_link_libraries(chesslast PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.chesslast)
endif()


include(GNUInstallDirs)
install(TARGETS chesslast
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
