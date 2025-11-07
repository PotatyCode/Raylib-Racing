#include "entity.hpp"
#include <memory>
#include <raylib.h>
#include <utility>
enum class gameState { mainMenu, racing, endMenu };
class coreGame {
  protected:
    static const constexpr float screenWidth = 1440, screenHeight = screenWidth * 1.6, fpsTarget = 60;
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
    template <typename T, typename... Args>
    void addEntity(Args&&... args) {
        gameEntities.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
    virtual void cleanup() { enviroment.Unload(); };
};
