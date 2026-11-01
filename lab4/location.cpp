#include "location.h"

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