#include "../../vendor/raylib-cpp/include/raylib-cpp.hpp"
#include <raylib.h>
#include <sys/types.h>

namespace inputSys {
    KeyboardKey getKeyInput() {
        return static_cast<KeyboardKey>(raylib::Keyboard::GetKeyPressed());
    }
}
