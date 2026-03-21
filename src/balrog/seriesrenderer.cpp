
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

    auto &color = series->pen().color;
    glUniform4f(colorLocation_, color.red, color.green, color.blue, color.alpha);
    glLineWidth(series->pen().width);

    buffer_.bind();

    glDrawArrays(GL_LINE_STRIP, 0, series->size());
}

GLSeriesRenderer::GLSeriesRenderer(): SeriesRenderer() {
    glEnable(GL_LINE_SMOOTH);
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

        uniform vec4 u_color;
        out vec4 FragColor;
        void main() {
            FragColor = u_color;
        }
        )"
    };

     colorLocation_ = glGetUniformLocation(program_.id, "u_color");
};

} // namespace balrog
