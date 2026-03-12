
#include <GL/glew.h>

#include <iostream>

#include "balrog/series.hpp"
#include "balrog/opengl/program.hpp"
#include "balrog/opengl/buffer.hpp"

namespace balrog {

class Backend {
    Program seriesProgram_;
    Buffer buffer;

public:
    void init() {
        seriesProgram_.init();
        buffer.init();
        buffer.upload({{1.0f, 1.0f }, { 5.0f, 5.0f }});
    }

    Backend() {
        std::string vs_source = R"(
        #version 330 core
        layout (location = 0) in vec2 aPos;

        void main() {
            gl_Position = vec4(aPos, 0.0, 1.0);
        }
        )";

        std::string fs_source = R"(
        #version 330 core
        out vec4 FragColor;

        void main() {
            FragColor = vec4(1.0, 0.0, 0.0, 1.0);
        }
        )";
        seriesProgram_ = {
            vs_source, fs_source
        };
    }

    void render(const Series &series) {
        buffer.bind();
        seriesProgram_.use();
    }
};

}
