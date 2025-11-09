#pragma once
#include "../../core/include/Component.hpp"
#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <raylib.h>
#include <raymath.h>
class carMovement : component {
    const float pi = 3.14159;
    const float MAX_SPEED = 180.0f;
    const float ACCEL = 100.0f;
    const float DEACCEL = -15.0f;
    const float BASE_TURN = pi / 2;
    const float FRICTION = 0.95f;
    Vector3 gameForward = {0, 0, 1};
    float speed = 0.0f;

  public:
    const float getSpeed() const { return speed; }
    void update() override;
    explicit carMovement(entity* Parent) : component(Parent) {}
    ~carMovement() override = default;
};
