
#pragma once

#include <memory>

#include "balrog/types.hpp"
#include "balrog/opengl/gridrenderer.hpp"


namespace balrog {

struct Grid {
    Pen axesPen = {
        {0.0f, 0.0f, 0.0f, 1.0f},
        2.0f
    };

    std::unique_ptr<GLGridRenderer> renderer;
    Grid();
    void show();
};

}
