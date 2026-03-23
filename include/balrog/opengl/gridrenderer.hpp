
#pragma once

#include "balrog/opengl/buffer.hpp"
#include "balrog/opengl/program.hpp"

namespace balrog {

class Grid;

struct GLGridRenderer {
    Program program;
    GLint axisColorLocation = 0;

    void render(Grid *grid);
    GLGridRenderer();
};

}
