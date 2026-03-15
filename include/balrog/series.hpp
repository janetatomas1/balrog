
#pragma once

#include <vector>
#include <string>

#include "balrog/opengl/program.hpp"
#include "balrog/opengl/buffer.hpp"

namespace balrog {

class Series {
    Program program_;
    Buffer buffer_;

    std::string label_;
    std::vector<float> x_;
    std::vector<float> y_;

public:
    Series(const std::string &label = "");
    Series(
        const std::string &label,
        const std::vector<float> &x,
        const std::vector<float> &y
    );
    const float* xdata() const;
    const float* ydata() const;
    size_t size() const;
    std::string &label();
    const std::string &label() const;
    void show();
};

} // namespace balrog
