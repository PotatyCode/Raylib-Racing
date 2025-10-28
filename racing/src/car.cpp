#include "../include/car.hpp"

car::car() : carMovement(this), mainCam(this) {}
void car::update() {
    carMovement.update();
    mainCam.update();
    for (auto& component : getRunTimeComponents()) {
        component->update();
    }
}
