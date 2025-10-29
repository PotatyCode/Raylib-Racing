#include "../include/car.hpp"
#include <raylib.h>

car::car() : carMovement(this), mainCam(this) {
    setModel("../../assets/chevy/Chevrolet Camaro.fbx");
    setTexture("../../assets/chevy/Render.png");
}
void car::update() {
    carMovement.update();
    mainCam.update();
    for (auto& component : getRunTimeComponents()) {
        component->update();
    }
}
void car::render() {
    DrawModel(getModel(), getPosition(), 1, WHITE);
}
