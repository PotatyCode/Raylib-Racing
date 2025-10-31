#pragma once
#include "../../core/include/Component.hpp"
#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <raylib.h>
#include <raymath.h>

class carCamera : component, public raylib::Camera3D {

  public:
    void update() override {
        position = Vector3Add(getParent()->getPosition(), {0.0f, 100.0f, 5.0f}); // car position + offset
        up = {0.0f, 1.0f, 0.0f};
        target.x = position.x + sin(getParent()->getDirection()) * 10.0f;
        target.y = position.y + 2.0f;
        target.z + position.z + cos(getParent()->getDirection()) * 10.0f;
        fovy = 45.0f;
        projection = CAMERA_PERSPECTIVE;
    }
    carCamera(entity* _Parent) : component(_Parent) {};
    ~carCamera() override = default;
};
