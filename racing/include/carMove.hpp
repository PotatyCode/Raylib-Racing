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
    virtual void update() {
        KeyboardKey keyPressed = inputSys::getKeyInput();
        if (IsKeyDown(KEY_W)) {
            speed += ACCEL * GetFrameTime();
        }
        if (IsKeyDown(KEY_S)) {
            speed -= DEACCEL * GetFrameTime();
        }
        if (IsKeyDown(KEY_A)) {
            float turnSpeed = (BASE_TURN * (speed / MAX_SPEED)) * GetFrameTime();
            Quaternion turnRotation = QuaternionFromAxisAngle(raylib::Vector3{0, 1, 0}, turnSpeed);
            getParent().setRotation(QuaternionMultiply(getParent().getRotation(), turnRotation));
        }
        if (IsKeyDown(KEY_D)) {
            float turnSpeed = -BASE_TURN * (speed / MAX_SPEED) * GetFrameTime();
            Quaternion turnRotation = QuaternionFromAxisAngle(raylib::Vector3{0, 1, 0}, turnSpeed);
            getParent().setRotation(QuaternionMultiply(getParent().getRotation(), turnRotation));
        }

        speed *= FRICTION;
        speed = Clamp(speed, -MAX_SPEED * 0.5f, MAX_SPEED);
        forward = Vector3RotateByQuaternion({0, 0, 1}, getParent().getRotation());
        Vector3 velocity = Vector3Scale(forward, speed * GetFrameTime());
        getParent().setPosition(Vector3Add(velocity, getParent().getPosition()));
    }
};
