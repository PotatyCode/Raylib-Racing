#include <raylib.h>
int main() {
    InitWindow(1920, 1080, "Racing Game");
    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawText("Hello", 1920 / 2, 1080 / 2, 50, WHITE);
        EndDrawing();
    }
}
