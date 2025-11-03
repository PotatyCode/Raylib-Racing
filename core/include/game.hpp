#include "Component.hpp"
#include "entity.hpp"
#include <memory>
#include <raylib.h>
enum class gameState { mainMenu, racing, endMenu };
class coreGame {
  protected:
    float screenWidth, screenHeight, fpsTarget;
    char* title;
    std::vector<std::unique_ptr<entity>> gameEntities;
    raylib::Model enviroment;

  public:
    virtual void init() { InitWindow(screenWidth, screenHeight, title); }
    virtual void update() {
        for (auto& entity : gameEntities) {
            entity->update();
        }
    };
    virtual void render() {
        for (auto& entity : gameEntities) {
            entity->render();
        }
        enviroment.Draw({0, 0, 0}, {0, 1, 0}, 0, {1, 1, 1}, WHITE);
    };
    virtual void cleanup();
};
