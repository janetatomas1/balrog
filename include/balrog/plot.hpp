
#pragma once

#include <vector>

#include "balrog/opengl/backend.hpp"
#include "balrog/series.hpp"

namespace balrog {

class Plot {
    std::vector<Series> series_;

public:
    Plot() = default;
    void show();
    void add_series(Series &&series);
};

}
