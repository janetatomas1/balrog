
#pragma once

#include "balrog/series.hpp"
#include "balrog/seriesrenderer.hpp"
#include "balrog/opengl/program.hpp"
#include "balrog/opengl/buffer.hpp"

namespace balrog {

class GLSeriesRenderer: public SeriesRenderer {
    Program program_;
    Buffer buffer_;

public:
    void render(Series *series) override;
    GLSeriesRenderer();
};

};
