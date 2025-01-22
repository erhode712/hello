
#include "utils.h"
#include <math.h>

double degreesToRadians(double degree){
    return (degree * M_PI)/180;
}

double getAirDistance(double originLatitude,
                      double originLongitude,
                      double destinationLatitude,
                      double destinationLongitude){
    originLatitude = degreesToRadians(originLatitude);
    originLongitude = degreesToRadians(originLongitude);
    destinationLatitude = degreesToRadians(destinationLatitude);
    destinationLongitude = degreesToRadians(destinationLongitude);

    double difference = destinationLongitude - originLongitude;
    int averageRadius = 6371;
    return acos((sin(originLatitude))*sin(destinationLatitude)+cos(originLatitude)*cos(destinationLatitude)*cos(difference))*averageRadius;
                      }

double lorentzTimeDilation(double t, double percentC){
    return t/(sqrt(1 - (percentC * percentC)));
}

