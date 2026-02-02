
#pragma once

#include <vector>
#include <string>

#include "balrog/pen.hpp"

namespace balrog {

class Series {
    std::string label_;
    std::vector<float> x_;
    std::vector<float> y_;
    Pen pen_;

public:
    Series(const std::string &label = "");
    Series(
        const std::string &label,
        const std::vector<float> &x,
        const std::vector<float> &y
    );
    Series(
        const std::string &label,
        const std::vector<float> &x,
        const std::vector<float> &y,
        const Pen &pen
    );
    const float* xdata() const;
    const float* ydata() const;
    std::vector<float> &xdata_vector();
    std::vector<float> &ydata_vector();
    size_t size() const;
    Pen &pen();
    const Pen &pen() const;
    std::string &label();
    const std::string &label() const;
};

} // namespace balrog
