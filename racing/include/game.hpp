#include "../../core/include/Coregame.hpp"
#include "../../core/include/entity.hpp"
#include "../../racing/include/car.hpp"
#include <iostream>
#include <raylib.h>
class game : coreGame {
  private:
    car player;

  public:
    void render() override {
        coreGame::render();
        player.render();
    }

    game() : player(0) { std::cout << "env Loaded"; }
    void run() {
        Camera camera = {0};
        camera.position = (Vector3){50.0f, 50.0f, 50.0f}; // Camera position
        camera.target = (Vector3){0.0f, 10.0f, 0.0f};     // Camera looking at point
        camera.up = (Vector3){0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
        camera.fovy = 45.0f;                              // Camera field-of-view Y
        camera.projection = CAMERA_PERSPECTIVE;           // Camera mode type
        while (!WindowShouldClose()) {
            player.update();

            BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);

            player.render();

            EndMode3D();
            EndDrawing();
        }
    }
};
