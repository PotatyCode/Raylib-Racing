#pragma once
#include "../../core/include/entity.hpp"
#include "CockpitCamera.hpp"
#include "carMove.hpp"
#include <cstdint>
#include <raylib.h>
#include <sys/types.h>
class car : public entity {
  private:
    carCamera mainCam;
    carMovement movement;

  public:
    void update() override;
    void render() override;
    const carCamera& getCamera() { return mainCam; }
    car(uint32_t id);
    ~car() override = default;
};
