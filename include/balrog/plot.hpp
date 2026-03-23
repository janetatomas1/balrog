
#pragma once

#include <vector>
#include <memory>

#include "balrog/series.hpp"
#include "balrog/types.hpp"
#include "balrog/grid.hpp"

namespace balrog {

class Plot {
    std::vector<std::unique_ptr<Series>> series_;
    std::unique_ptr<Grid> grid_;

    Color backgroundColor_ = {
        1.0f, 1.0f, 1.0f, 1.0f
    };

public:
    Plot() = default;
    void show();
    void add_series(std::unique_ptr<Series> series);
    Color& background_color();
    void init();
};

}
