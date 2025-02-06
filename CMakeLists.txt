cmake_minimum_required(VERSION 3.30.5)
project(flappy_sanyok)
include_directories("/opt/homebrew/include")
link_directories("/opt/homebrew/lib")
find_package(SFML 2.6.2 COMPONENTS graphics window system audio REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(flappy_sanyok main.cpp State.hpp
        StateMachine.cpp
        StateMachine.hpp
        AssetManager.cpp
        AssetManager.hpp
        InputManager.cpp
        InputManager.hpp
        Game.cpp
        Game.hpp
        DEFINITIONS.hpp
        SplashState.cpp
        SplashState.hpp
        MainMenuState.cpp
        MainMenuState.hpp
        GameState.cpp
        GameState.hpp
        GameOverState.cpp
        GameOverState.hpp
        Pipe.cpp
        Pipe.hpp
        Land.cpp
        Land.hpp
        Bird.cpp
        Bird.hpp
        Collision.cpp
        Collision.hpp
        Flash.cpp
        Flash.hpp
        HUD.cpp
        HUD.hpp)

set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/Resources")
# Копируйте ресурсы в выходной каталог
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR}/resources)

# Линкуем библиотеки SFML
target_link_libraries(flappy_sanyok sfml-graphics sfml-window sfml-system sfml-audio)
