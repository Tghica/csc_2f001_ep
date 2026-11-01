#include "location.h"

#include <cmath>
#include <numbers>
#include <math.h>

using namespace std;

location_t::location_t(const string& name, double latitude, double longitude)
    : name(name), 
    latitude(latitude), 
        longitude(longitude),
        neighbors(nullptr) {
}

location_t::~location_t() {
    delete[] neighbors;
}

void location_t::set_neighbors(location_t* list[]) {
    neighbors = list;
}

double location_t::distance_to(location_t* to) {
    constexpr double earth_radius = 6378.0;

    return earth_radius * (M_PI / 2 - asin(sin(to->latitude) * std::sin(latitude) + cos(to->longitude - longitude) * cos(to->latitude) * cos(latitude)));
}