
#pragma once

#include <array>

namespace balrog {

struct Pen {
    std::array<float, 4> color_ = {1.0f, 0.0f, 0.0f, 1.0f};
    float thickness_ = 1.0f;
};

} // namespace balrog
