
#include "balrog/pen.hpp"
#include "balrog/series.hpp"

namespace balrog {

Series::Series(const std::string &label) : label_(label) {}

Series::Series(
    const std::string &label,
    const std::vector<float> &x,
    const std::vector<float> &y
) : label_(label), x_(x), y_(y) {}

Series::Series(
    const std::string &label,
    const std::vector<float> &x,
    const std::vector<float> &y,
    const Pen &pen
) : label_(label), x_(x), y_(y), pen_(pen) {}

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

size_t Series::size() const {
    return x_.size();
}

} // namespace balrog
