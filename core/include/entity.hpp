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
    const Quaternion& getRotation() const { return transform.rotation; }
    const Vector3& getPosition() const { return transform.translation; }
    const Vector3& getScale() const { return transform.scale; }
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

    entity(uint32_t id) : id(id), transform{} {
        transform.rotation = {0, 0, 0, 1};
        transform.scale = {1.5, 1, 1};
    }
    virtual ~entity() {
        model.Unload();
        texture.Unload();
    };
};
