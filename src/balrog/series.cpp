
#include <iostream>

#include "balrog/series.hpp"
#include "balrog/opengl/seriesrenderer.hpp"

namespace balrog {

Series::Series(const std::string &label) : label_(label) {
    renderer_ = std::make_unique<GLSeriesRenderer>();
}

Series::Series(
    const std::string &label,
    const std::vector<float> &x,
    const std::vector<float> &y
) : label_(label), x_(x), y_(y) {
    renderer_ = std::make_unique<GLSeriesRenderer>();
}

const float* Series::xdata() const {
    return x_.data();
}

const float* Series::ydata() const {
    return y_.data();
}

std::vector<float>& Series::xvector() {
    return x_;
}

std::vector<float>& Series::yvector() {
    return y_;
}

size_t Series::size() const {
    return x_.size();
}

void Series::show() {
    renderer_->render(this);
}

Pen& Series::pen() {
    return pen_;
}

} // namespace balrog
