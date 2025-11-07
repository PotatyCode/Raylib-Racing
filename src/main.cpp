#include "../racing/include/game.hpp"
#include <iostream>
#include <raylib.h>
int main() {
    InitWindow(1920 / 2, 1080 / 2, "Racing Game");
    std::cout << "Windows Initialised";
    game Game;
    std::cout << "Game constructed";
    Game.run();
    return 0;
}
