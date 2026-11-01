#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

struct location_t {
  string name;
  double latitude;
  double longitude;
  location_t** neighbors;

  location_t(const string& name, double latitude, double longitude);
  ~location_t();
  void set_neighbors(location_t* list[]);
  double distance_to(location_t* to);
};

#endif