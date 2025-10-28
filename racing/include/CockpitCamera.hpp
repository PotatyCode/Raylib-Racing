#include "../../core/include/Component.hpp"
#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <raymath.h>

class carCamera : component, raylib::Camera3D {
  public:
    virtual void update() {
        position = Vector3Add(getParent().getPosition(), {0.0f, 2.0f, 5.0f}); // car position + offset
        up = {0.0f, 1.0f, 0.0f};
        raylib::Vector3 forwardDir = {0.0f, 0.0f, -1.0f};
        target = Vector3Add(Vector3RotateByQuaternion(forwardDir, getParent().getRotation()), position);
        fovy = 45.0f;
        projection = CAMERA_FIRST_PERSON;
    }
};
