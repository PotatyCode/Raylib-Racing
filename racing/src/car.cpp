#include "../include/car.hpp"
#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
car::car(uint32_t id) : entity(id), movement(this), mainCam(this) {
    std::cout << "Loading Model\n";
    model = LoadModel("assets/chevy/chevroletCamero.obj");
    std::cout << "Model Loaded\n";
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
    DrawModelEx(model, getPosition(), {0, 1, 0}, getDirection() * 180 / 3.14159, {1, 1, 1}, WHITE);
}
