#include "../racing/include/car.hpp"
#include <raylib.h>
int main() {
    int screenWidth = 1440;
    int screenHeight = screenWidth * 1.6;
    InitWindow(screenHeight / 2, screenWidth / 2, "Racing Game");
    SetTargetFPS(0);
    car player(1);
    Camera3D testCam = {0};
    testCam.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
    testCam.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
    testCam.up = (Vector3){0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
    testCam.fovy = 45.0f;                              // Camera field-of-view Y
    testCam.projection = CAMERA_PERSPECTIVE;

    rlDisableBackfaceCulling();
    while (!WindowShouldClose()) {
        player.update();
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(testCam);
        player.render();
        DrawPlane({0, 0, 0}, {100, 100}, WHITE);
        DrawCube({0, 0, 10}, 5, 5, 4, RED);
        EndMode3D();

        DrawFPS(10, 10);
        DrawText(TextFormat("Target x:%.2f ", player.getCamera().GetTarget().x), 10, 90, 20, GREEN);
        DrawText(TextFormat("Target y:%.2f ", player.getCamera().GetTarget().y), 10, 120, 20, GREEN);
        DrawText(TextFormat("Target z:%.2f ", player.getCamera().GetTarget().z), 10, 150, 20, GREEN);
        EndDrawing();
    }
    rlEnableBackfaceCulling();
}
