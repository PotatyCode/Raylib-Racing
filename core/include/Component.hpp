#pragma once
#include "entity.hpp"
#include <memory>
class component {
  private:
    entity* Parent;

  public:
    explicit component(entity* Parent) : Parent(Parent) {};
    virtual void update() = 0;
    entity* getParent() const { return Parent; }
    virtual ~component() = default;
};
