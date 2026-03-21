
#pragma once

#include <vector>
#include <string>
#include <memory>

#include "balrog/opengl/program.hpp"
#include "balrog/opengl/buffer.hpp"
#include "balrog/seriesrenderer.hpp"
#include "balrog/types.hpp"

namespace balrog {

class Series {
    std::string label_;
    std::vector<float> x_;
    std::vector<float> y_;
    std::unique_ptr<SeriesRenderer> renderer_;
    Pen pen_;

public:
    Series(const std::string &label = "");
    Series(
        const std::string &label,
        const std::vector<float> &x,
        const std::vector<float> &y
    );
    const float* xdata() const;
    const float* ydata() const;
    std::vector<float>& xvector();
    std::vector<float>& yvector();
    size_t size() const;
    std::string &label();
    const std::string &label() const;
    void show();
    Pen &pen();
};

} // namespace balrog
