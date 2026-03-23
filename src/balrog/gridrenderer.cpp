
#include "balrog/opengl/gridrenderer.hpp"
#include "balrog/grid.hpp"

namespace balrog {

GLGridRenderer::GLGridRenderer() {
    program = {
        R"(
            #version 330 core

            void main()
            {
                vec2 positions[4] = vec2[](
                    vec2(-5.0, 0.0),
                    vec2( 5.0, 0.0),
                    vec2( 0.0,-5.0),
                    vec2( 0.0, 5.0)
                );
                gl_Position = vec4(positions[gl_VertexID], 0.0, 1.0);
            }
        )",
        R"(
            #version 330 core
            out vec4 FragColor;
            uniform vec3 u_color;

            void main() {
                FragColor = vec4(0.0, 0.0, 0.0, 1.0);
            }
        )"
    };

    axisColorLocation = program.get_uniform("u_color");
}

void GLGridRenderer::render(Grid *grid) {
    glLineWidth(grid->axesPen.width);

    auto color = grid->axesPen.color;
    glUniform4f(axisColorLocation, color.red, color.green, color.blue, color.alpha);

    program.use();
    glDrawArrays(GL_LINES, 0, 4);
}

}
