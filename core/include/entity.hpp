#pragma once

#include <cstdint>
#include <memory>
#include <raylib.h>
#include <vector>
class component;
class entity {
  private:
    uint32_t id;
    std::vector<std::unique_ptr<component>> runtimeComponents;

  public:
    int getId() { return id; }
    virtual void update() = 0;
    virtual void render() = 0;
};
