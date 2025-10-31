#include "../include/carMove.hpp"
#include <raylib.h>
#include <raymath.h>

void carMovement::update() {
    auto dt = GetFrameTime();
    if (IsKeyDown(KEY_W)) {
        speed += ACCEL * dt;
    }
    if (IsKeyDown(KEY_S)) {
        speed -= DEACCEL * dt;
    }
    speed *= pow(FRICTION, dt * 60.0f);
    speed = Clamp(speed, -MAX_SPEED * 0.5f, MAX_SPEED);

    float turnAmount = 0.0f;
    if (IsKeyDown(KEY_A)) {
        turnAmount = BASE_TURN * dt;
    }
    if (IsKeyDown(KEY_D)) {
        turnAmount = -BASE_TURN * dt;
    }
    Quaternion turnRotation = QuaternionFromAxisAngle({0, 1, 0}, turnAmount);
    getParent()->setRotation(QuaternionMultiply(turnRotation, getParent()->getRotation()));
    Vector3 forward;
    forward = Vector3RotateByQuaternion({0, 0, 1}, getParent()->getRotation());
    Vector3 velocity = Vector3Scale(forward, speed * dt);
    getParent()->setPosition(Vector3Add(velocity, getParent()->getPosition()));
}
