#ifndef GEOLOCATION_H
#define GEOLOCATION_H
class GeoLocation {
public:
    double lat, lon;
    GeoLocation(double l = 0, double ln = 0);
    double distanceTo(const GeoLocation& other) const;
};
#endif