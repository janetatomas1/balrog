
#include <iostream>

#include "balrog/series.hpp"

namespace balrog {

Series::Series(const std::string &label) : label_(label) {
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
}

Series::Series(
    const std::string &label,
    const std::vector<float> &x,
    const std::vector<float> &y
) : label_(label), x_(x), y_(y) {
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
}

const float* Series::xdata() const {
    return x_.data();
}

const float* Series::ydata() const {
    return y_.data();
}

size_t Series::size() const {
    return x_.size();
}

void Series::show() {
    buffer_.uploadx(
        x_
    );
    buffer_.uploady(
        y_
    );
    program_.use();
    buffer_.bind();
    glDrawArrays(GL_LINE_STRIP, 0, x_.size());
}

} // namespace balrog
