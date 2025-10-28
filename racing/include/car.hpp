#pragma once
#include "../../core/include/entity.hpp"
#include "CockpitCamera.hpp"
#include "carMove.hpp"
class car : private entity {
  private:
    carCamera mainCam;
    carMovement carMovement;

  public:
    void update() override;
    void render() override;
    car();
    ~car() override = default;
};
