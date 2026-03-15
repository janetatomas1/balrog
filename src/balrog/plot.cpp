
#include "balrog/plot.hpp"

namespace balrog {

void Plot::show() {
    for(auto &s: series_) {
        s.show();
    }
}

void Plot::add_series(Series &&series) {
    series_.push_back(std::move(series));
}

}
