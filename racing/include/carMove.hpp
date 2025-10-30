#pragma once
#include "../../core/include/Component.hpp"
#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <raylib.h>
#include <raymath.h>
class carMovement : component {
    const float MAX_SPEED = 30.0f;
    const float ACCEL = 10.0f;
    const float DEACCEL = 15.0f;
    const float BASE_TURN = 70;
    const float FRICTION = 0.95f;
    Vector3 forward = {0, 0, 1};
    float speed = 0.0f;

  public:
    void update() override;
    explicit carMovement(entity* Parent) : component(Parent) {}
    ~carMovement() override = default;
};
