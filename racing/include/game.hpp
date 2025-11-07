#include "../../core/include/Coregame.hpp"
#include "../../core/include/entity.hpp"
#include "../../racing/include/car.hpp"
#include <raylib.h>
class game : coreGame {
  private:
    car player;

  public:
    void render() override {
        coreGame::render();
        player.render();
    }
    game() {
        init();
        enviroment.Load("assets/track/Taas+circuit.obj");
    }
    void run() {
        while (!WindowShouldClose()) {
            update();

            BeginDrawing();
            BeginMode3D(player.getCamera());

            render();

            EndMode3D();
            EndDrawing();
        }
    }
};
