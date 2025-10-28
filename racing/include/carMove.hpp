#include "../../core/include/Component.hpp"
#include "../../core/src/inputSys.cpp"
#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <raylib.h>
class carMovement : component {
    const float MAX_SPEED = 30.0f;
    const float ACCEL = 5.0f;
    const float BASE_TURN = 2.5f;
    float speed = 0.0f;

  public:
    virtual void update() {
        KeyboardKey keyPressed = inputSys::getKeyInput();
        switch (keyPressed) {
            default:
                break;
            case KEY_W: {
            }
        }
    }
};
