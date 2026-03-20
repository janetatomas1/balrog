
#pragma once

#include <vector>

#include "balrog/opengl/backend.hpp"
#include "balrog/series.hpp"
#include "balrog/types.hpp"

namespace balrog {

class Plot {
    std::vector<Series> series_;
    Color backgroundColor_ = {
        1.0f, 1.0f, 1.0f, 1.0f
    };


public:
    Plot() = default;
    void show();
    void add_series(Series &&series);
    Color& background_color();
};

}
