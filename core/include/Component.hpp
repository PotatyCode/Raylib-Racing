#pragma once
#include "entity.hpp"
#include <memory>
class component {
  private:
    entity* Parent;

  public:
    component(entity* _Parent) : Parent(_Parent) {};
    virtual void update() = 0;
    entity* getParent() { return Parent; }
};
