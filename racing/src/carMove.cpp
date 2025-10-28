#include "../include/carMove.hpp"

void carMovement::update() {
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
        getParent()->setRotation(QuaternionMultiply(getParent()->getRotation(), turnRotation));
    }
    if (IsKeyDown(KEY_D)) {
        float turnSpeed = -BASE_TURN * (speed / MAX_SPEED) * GetFrameTime();
        Quaternion turnRotation = QuaternionFromAxisAngle(raylib::Vector3{0, 1, 0}, turnSpeed);
        getParent()->setRotation(QuaternionMultiply(getParent()->getRotation(), turnRotation));
    }

    speed *= FRICTION;
    speed = Clamp(speed, -MAX_SPEED * 0.5f, MAX_SPEED);
    forward = Vector3RotateByQuaternion({0, 0, 1}, getParent()->getRotation());
    Vector3 velocity = Vector3Scale(forward, speed * GetFrameTime());
    getParent()->setPosition(Vector3Add(velocity, getParent()->getPosition()));
}
