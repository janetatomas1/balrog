
#include "balrog/pen.hpp"
#include "balrog/series.hpp"

namespace balrog {

Series::Series() {
}

Pen &Series::pen() {
    return pen_;
}

const Pen &Series::pen() const {
    return pen_;
}

const float* Series::xdata() const {
    return x_.data();
}

const float* Series::ydata() const {
    return y_.data();
}

std::vector<float> &Series::xdata_vector() {
    return x_;
}

std::vector<float> &Series::ydata_vector() {
    return y_;
}

size_t Series::size() const {
    return x_.size();
}

} // namespace balrog
