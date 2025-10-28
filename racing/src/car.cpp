#include "../include/car.hpp"
#include <raylib.h>

car::car() : carMovement(this), mainCam(this) {
    model = LoadModel("../../assets/chevy/Chevrolet Camaro.fbx");
    texture = LoadTexture("../../assets/chevy/Render.png")
}
void car::update() {
    carMovement.update();
    mainCam.update();
    for (auto& component : getRunTimeComponents()) {
        component->update();
    }
}
void car::render() {}
