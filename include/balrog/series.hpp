
#pragma once

#include <vector>

#include "balrog/pen.hpp"

namespace balrog {

class Series {
    std::vector<float> x_;
    std::vector<float> y_;

    Pen pen_;
public:
    Series();
    const float* xdata() const;
    const float* ydata() const;
    std::vector<float> &xdata_vector();
    std::vector<float> &ydata_vector();
    size_t size() const;
    Pen &pen();
    const Pen &pen() const;
};

} // namespace balrog
