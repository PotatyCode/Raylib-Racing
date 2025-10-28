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
    auto getId() const { return id; }
    raylib::Quaternion getRotation() { return transform.rotation; }
    raylib::Vector3 getPosition() { return transform.translation; }
    raylib::Vector3 getScale() { return transform.scale; }
    std::vector<std::unique_ptr<component>> getRunTimeComponents() { return runtimeComponents; }

    void setRotation(raylib::Quaternion newRotation) { transform.rotation = newRotation; }
    void setPosition(raylib::Vector3 newPosition) { transform.translation = newPosition; }
    void setScale(raylib::Vector3 newScale) { transform.scale = newScale; }
    template <typename T, typename... Args>
    void addComponent(Args&&... args) {
        runtimeComponents.emplace_back(std::make_unique<T>);
    }


    virtual void update() = 0;
    virtual void render() = 0;

    entity() {}
    virtual ~entity() = default;
};
