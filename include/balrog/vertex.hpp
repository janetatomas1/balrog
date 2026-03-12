
#pragma once

namespace balrog {

struct Vertex {
    float x, y;

    static constexpr size_t stride() { return 4 * sizeof(float); }
};

}
