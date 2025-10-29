#pragma once

#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <cstdint>
#include <memory>
#include <raylib.h>
#include <string_view>
#include <vector>
class component;
class entity {
  protected:
    const uint32_t id;
    std::vector<std::unique_ptr<component>> runtimeComponents;
    Transform transform;
    raylib::Model model;
    raylib::Texture2D texture;

  public:
    auto getId() const { return id; }
    const raylib::Quaternion& getRotation() { return transform.rotation; }
    const raylib::Vector3& getPosition() { return transform.translation; }
    const raylib::Vector3& getScale() { return transform.scale; }
    const std::vector<std::unique_ptr<component>>& getRunTimeComponents() { return runtimeComponents; }
    const raylib::Model& getModel() { return model; }
    const raylib::Texture& getTexture() { return texture; }

    void setRotation(const raylib::Quaternion& newRotation) { transform.rotation = newRotation; }
    void setPosition(const raylib::Vector3& newPosition) { transform.translation = newPosition; }
    void setScale(const raylib::Vector3& newScale) { transform.scale = newScale; }
    template <typename T, typename... Args>
    void addComponent(Args&&... args) {
        runtimeComponents.emplace_back(std::make_unique<T>);
    }


    virtual void update() = 0;
    virtual void render() = 0;

    entity(uint32_t id) : id(id), transform{} {}
    virtual ~entity() = default;
};
