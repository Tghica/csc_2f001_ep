#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

struct location_t {
    string name;
    double latitude;
    double longitude;

    location_t(const string& name, double latitude, double longitude);
};

#endif