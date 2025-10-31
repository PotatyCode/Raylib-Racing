#include "../include/car.hpp"
#include <cstdint>
#include <raylib.h>
#include <raymath.h>

car::car(uint32_t id) : movement(this), mainCam(this), entity(id) {
    model.Load("assets/chevy/ChevroletCamero.glb");
    texture.Load("assets/chevy/Render.png");
}
void car::update() {
    movement.update();
    mainCam.update();
    for (auto& component : getRunTimeComponents()) {
        component->update();
    }
}
void car::render() {
    Vector3 axis;
    float angle;
    QuaternionToAxisAngle(getRotation(), &axis, &angle);
    DrawModelEx(model, getPosition(), axis, angle, getScale(), WHITE);
}
car::~car() {
    model.Unload();
    texture.Unload();
}
