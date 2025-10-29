#include "../racing/include/car.hpp"
#include <raylib.h>
int main() {
    InitWindow(1920, 1080, "Racing Game");
    SetTargetFPS(60);
    car player(1);

    while (!WindowShouldClose()) {
        player.update();
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(player.getCamera());
        player.render();
        DrawGrid(10, 1);
        EndMode3D();
        DrawFPS(10, 10);
        DrawText(TextFormat("Player Position x: %d", player.getPosition().GetX()), 30, 10, 20, WHITE);
        EndDrawing();
    }
}
