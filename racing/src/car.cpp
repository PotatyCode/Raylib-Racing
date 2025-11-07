#include "../include/car.hpp"
#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
car::car() : movement(this), mainCam(this) {
    model.Load("assets/chevy/chevroletCamero.obj");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    boundingBox = GetModelBoundingBox(model);
}
void car::update() {
    movement.update();
    mainCam.update();
    for (auto& component : getRunTimeComponents()) {
        component->update();
    }
}
void car::render() {
    model.Draw(getPosition(), {0, 1, 0}, getDirection() * 180 / 3.14159, {1, 1, 1}, WHITE);
    getBoundingBox().Draw();
}
car::~car() {
    model.Unload();
    texture.Unload();
}
