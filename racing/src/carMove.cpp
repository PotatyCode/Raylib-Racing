#include "../include/carMove.hpp"
#include <raylib.h>
#include <raymath.h>

void carMovement::update() {
    auto dt = GetFrameTime();
    if (IsKeyDown(KEY_W)) {
        speed -= ACCEL * dt;
    }
    if (IsKeyDown(KEY_S)) {
        speed += DEACCEL * dt;
    }
    speed *= pow(FRICTION, dt * 60.0f);
    speed = Clamp(speed, -MAX_SPEED * 0.5f, MAX_SPEED);

    if (IsKeyDown(KEY_A)) {
        getParent()->setDirection(getParent()->getDirection() + BASE_TURN * dt);
    }
    if (IsKeyDown(KEY_D)) {
        getParent()->setDirection(getParent()->getDirection() - BASE_TURN * dt);
    }
    auto rotationMatrix = raylib::Matrix::RotateY(getParent()->getDirection());
    raylib::Vector3 velocity = Vector3Transform({0, 0, 1}, rotationMatrix);
    velocity = velocity.Scale(speed * dt);
    raylib::Vector3 newPos = getParent()->getPosition() + velocity;
    getParent()->setPosition(newPos);
}
