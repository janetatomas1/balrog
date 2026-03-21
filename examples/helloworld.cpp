
#include <balrog/opengl/context.hpp>
#include <balrog/series.hpp>
#include <cmath>

#include <iostream>

using namespace balrog;

int main() {
    size_t n = 1000;
    float begin = -10;
    float end = 10;
    float current = begin;
    std::vector<float> x_data(n);
    std::vector<float> y_data(n);
    std::vector<float> z_data(n);

    for(size_t i=0;i < x_data.size();i++) {
        x_data[i] = current;
        y_data[i] = std::sin(2 * x_data[i]) - 5;
        z_data[i] = 2 * std::sin(2 * x_data[i] + 2) + 2;
        current += (end - begin) / n;
    }

    GLContext ctx("Hello World from Balrog !!!");
    auto series = std::make_unique<Series>("abc", x_data, z_data);
    series->pen().color = {
        0.0f, 1.0f, 0.0f, 1.0f
    };
    series->pen().width = 5.0f;

    ctx.plot().add_series(std::make_unique<Series>("abc", x_data, y_data));
    ctx.plot().add_series(std::move(series));
    ctx.show();
    return 0;
}
