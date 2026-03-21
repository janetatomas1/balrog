
#include "balrog/opengl/seriesrenderer.hpp"

namespace balrog {

void GLSeriesRenderer::render(Series *series) {
    buffer_.uploadx(
        series->xvector()
    );
    buffer_.uploady(
        series->yvector()
    );
    program_.use();
    buffer_.bind();

    glDrawArrays(GL_LINE_STRIP, 0, series->size());
}

GLSeriesRenderer::GLSeriesRenderer(): SeriesRenderer() {
    program_ = {
        R"(
        #version 330 core
        layout(location=0) in float x;
        layout(location=1) in float y;
        void main() {
            gl_Position = vec4(x, y, 0.0, 10.0);
        }
        )",
        R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Red
        }
        )"
    };
};

} // namespace balrog
