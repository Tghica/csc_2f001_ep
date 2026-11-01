#include "location.h"

using namespace std;

location_t::location_t(const string& name, double latitude, double longitude)
    : name(name), 
    latitude(latitude), 
    longitude(longitude) {
}