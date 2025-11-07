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
    game() : player(0) { enviroment.Load("assets/track/Taas+circuit.obj"); }
    void run() {
        while (!WindowShouldClose()) {
            update();

            BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(player.getCamera());

            player.render();

            EndMode3D();
            EndDrawing();
        }
    }
};
