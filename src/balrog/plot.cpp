
#include "balrog/plot.hpp"

namespace balrog {

void Plot::show() {
    glClearColor(
        backgroundColor_.red,
        backgroundColor_.green,
        backgroundColor_.blue,
        backgroundColor_.alpha
    );
    glClear(GL_COLOR_BUFFER_BIT);

    for(auto &s: series_) {
        s.show();
    }
}

void Plot::add_series(Series &&series) {
    series_.push_back(std::move(series));
}

Color& Plot::background_color() {
    return backgroundColor_;
}

}
