#include "../../core/include/Component.hpp"
#include "../../core/src/inputSys.cpp"
#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <raylib.h>
#include <raymath.h>
class carMovement : component {
    const float MAX_SPEED = 30.0f;
    const float ACCEL = 5.0f;
    const float DEACCEL = 10.0f;
    const float BASE_TURN = 2.5f;
    const float FRICTION = 0.98f;
    Vector3 forward = {0, 0, 1};
    float speed = 0.0f;

  public:
    virtual void update();
    carMovement(entity* _Parent) : component(_Parent) {}
};
