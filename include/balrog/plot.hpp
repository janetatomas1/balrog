
#pragma once

#include <vector>

#include "balrog/opengl/backend.hpp"
#include "balrog/series.hpp"
#include "balrog/types.hpp"
#include <memory>

namespace balrog {

class Plot {
    std::vector<std::unique_ptr<Series>> series_;
    Color backgroundColor_ = {
        1.0f, 1.0f, 1.0f, 1.0f
    };

public:
    Plot() = default;
    void show();
    void add_series(std::unique_ptr<Series> series);
    Color& background_color();
};

}
