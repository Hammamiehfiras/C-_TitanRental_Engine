#include "GeoLocation.h"
#include <cmath>
GeoLocation::GeoLocation(double l, double ln) : lat(l), lon(ln) {}
double GeoLocation::distanceTo(const GeoLocation& o) const {
    return std::sqrt(std::pow(lat - o.lat, 2) + std::pow(lon - o.lon, 2)) * 111.0;
}