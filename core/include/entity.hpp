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
    // const uint32_t id;
    std::vector<std::unique_ptr<component>> runtimeComponents;
    raylib::Vector3 position;
    raylib::Vector3 scale;
    raylib::Model model;
    raylib::Texture2D texture;
    float direction;
    raylib::BoundingBox boundingBox;

  public:
    // auto getId() const { return id; }
    const float& getDirection() const { return direction; }
    const raylib::Vector3& getPosition() const { return position; }
    const raylib::Vector3& getScale() const { return scale; }
    const std::vector<std::unique_ptr<component>>& getRunTimeComponents() { return runtimeComponents; }
    const raylib::Model& getModel() { return model; }
    const raylib::Texture& getTexture() { return texture; }
    const raylib::BoundingBox& getBoundingBox() { return boundingBox; }

    void setDirection(const float& newDirection) { direction = newDirection; }
    void setPosition(const raylib::Vector3& newPosition) { position = newPosition; }
    void setScale(const raylib::Vector3& newScale) { scale = newScale; }
    template <typename T, typename... Args>
    void addComponent(Args&&... args) {
        runtimeComponents.emplace_back(std::make_unique<T>);
    }


    virtual void update() = 0;
    virtual void render() = 0;

    explicit entity() : direction(0.0f), position(0.0f), scale(1.0f) {}
    virtual ~entity() {
        model.Unload();
        texture.Unload();
    };
};
