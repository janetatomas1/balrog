
#include "balrog/grid.hpp"

namespace balrog {

Grid::Grid(): renderer(std::make_unique<GLGridRenderer>()) {}

void Grid::show() {
    renderer->render(this);
}

}
