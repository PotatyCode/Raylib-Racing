#include "../include/carMove.hpp"
#include <raylib.h>

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
        float turnAmount = (BASE_TURN * (speed / MAX_SPEED)) * dt;
    }
    if (IsKeyDown(KEY_D)) {
        float turnAmount = -BASE_TURN * (speed / MAX_SPEED) * dt;
    }
    if (turnAmount != 0) {
        Quaternion turnRotation = QuaternionFromAxisAngle({0, 1, 0}, turnAmount);
        getParent()->setRotation(QuaternionMultiply(getParent()->getRotation(), turnRotation));
    }
    forward = Vector3RotateByQuaternion({0, 0, 1}, getParent()->getRotation());
    Vector3 velocity = Vector3Scale(forward, speed * GetFrameTime());
    getParent()->setPosition(Vector3Add(velocity, getParent()->getPosition()));
}
