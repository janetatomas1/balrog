
#pragma once

#include <vector>

#include "balrog/opengl/backend.hpp"
#include "balrog/series.hpp"

namespace balrog {

class Plot {
    Backend backend;

    std::vector<Series> series;
public:
    Plot() = default;
    void show();
    void init() {
        backend.init();
    }
};

}
