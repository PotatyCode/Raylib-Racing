#include "../include/car.hpp"
#include <cstdint>
#include <raylib.h>

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
    DrawModelEx(model, getPosition(), {getRotation().x, getRotation().y, getRotation().z}, getRotation().w, getScale(), WHITE);
}
car::~car() {
    model.Unload();
    texture.Unload();
}
