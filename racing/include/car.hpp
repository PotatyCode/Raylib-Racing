
#include "../../core/include/entity.hpp"
#include "CockpitCamera.hpp"
#include "carMove.hpp"
class car : private entity {
  private:
    carCamera mainCam;
    carMovement carMovement;

  public:
    virtual void update();
    virtual void render();
    car();
};
