#pragma once

#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <cstdint>
#include <memory>
#include <raylib.h>
#include <vector>
class component;
class entity {
  private:
    uint32_t id;
    std::vector<std::unique_ptr<component>> runtimeComponents;
    Transform transform;

  public:
    int getId() { return id; }
    raylib::Quaternion getRotation() { return transform.rotation; }
    raylib::Vector3 getPosition() { return transform.translation; }
    raylib::Vector3 getScale() { return transform.scale; }
    virtual void update() = 0;
    virtual void render() = 0;
};
