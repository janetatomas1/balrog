
#pragma once

namespace balrog {

class Series;

class SeriesRenderer {
public:
    virtual void render(Series *series) = 0;
    ~SeriesRenderer() = default;
    SeriesRenderer() = default;
};

} // namespace balrog
