#pragma once
#include "../../core/include/Coregame.hpp"
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

    game() : player(0) {
        coreGame::enviroment.Load("assets/track/Taas+circuit.glb");
        std::cout << "env Loaded";
    }
    void run() {
        SetTargetFPS(100);
        Camera camera = {0};
        camera.position = (Vector3){50.0f, 500.0f, 50.0f}; // Camera position
        camera.target = (Vector3){0.0f, 10.0f, 0.0f};      // Camera looking at point
        camera.up = (Vector3){0.0f, 1.0f, 0.0f};           // Camera up vector (rotation towards target)
        camera.fovy = 45.0f;                               // Camera field-of-view Y
        camera.projection = CAMERA_PERSPECTIVE;            // Camera mode type
        while (!WindowShouldClose()) {
            player.update();
            auto envBox = enviroment.GetBoundingBox();

            BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(player.getCamera());

            player.render();
            DrawModel(enviroment, {0, 15, 0}, 1, GRAY);
            DrawBoundingBox(envBox, BLUE);

            EndMode3D();
            DrawFPS(10, 10);
            DrawText(TextFormat("Speed:%0.2f", player.getMovement().getSpeed()), 10, 40, 20, GREEN);
            EndDrawing();
        }
    }
    ~game() { enviroment.Unload(); }
};
