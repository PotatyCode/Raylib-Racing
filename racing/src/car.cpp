#include "../include/car.hpp"
#include <cstdint>
#include <raylib.h>

car::car(uint32_t id) : movement(this), mainCam(this), entity(id) {
    model = LoadModel("~/RacingGame/assets/chevy/ChevroletCamero.glb");
    model = LoadModel("~/RacingGame/assets/chevy/Render.png");
    texture = LoadTexture("../../assets/chevy/Render.png");
}
void car::update() {
    movement.update();
    mainCam.update();
    for (auto& component : getRunTimeComponents()) {
        component->update();
    }
}
void car::render() {
    DrawModel(getModel(), getPosition(), 1, WHITE);
}
