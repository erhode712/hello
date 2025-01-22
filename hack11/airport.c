#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv){
  Airport *airport = (Airport *)malloc(sizeof(Airport) * 1);

  airport->gpsId = (char *)malloc(sizeof(char) * (strlen(gpsId) + 1));
  strcpy(airport->gpsId, gpsId);

  airport->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(airport->type, type);

  airport->name = (char *)malloc(sizeof(char) * (strlen(name) + 1)); // Add the name field
  strcpy(airport->name, name);

  airport->latitude = latitude;
  airport->longitude = longitude;
  airport->elevationFeet = elevationFeet;

  airport->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
  strcpy(airport->city, city);

  airport->countryAbbrv = (char *)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
  strcpy(airport->countryAbbrv, countryAbbrv);

  return airport;
}

void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv){

  airport->gpsId = (char *)malloc(sizeof(char) * (strlen(gpsId) + 1));
  strcpy(airport->gpsId, gpsId);

  airport->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(airport->type, type);

  airport->name = (char *)malloc(sizeof(char) * (strlen(name) + 1)); // Add the name field
  strcpy(airport->name, name);

  airport->latitude = latitude;
  airport->longitude = longitude;
  airport->elevationFeet = elevationFeet;

  airport->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
  strcpy(airport->city, city);

  airport->countryAbbrv = (char *)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
  strcpy(airport->countryAbbrv, countryAbbrv);

  return;
}

char* airportToString(const Airport* a){
    if (a == NULL) {
    char *result = (char *)malloc(sizeof(char) * 7);
    strcpy(result, "(null)");
    return result;
  }

  int n = strlen(a->gpsId) + strlen(a->type) + strlen(a->name) +
          strlen(a->city) + strlen(a->countryAbbrv) + sizeof(double) +
          sizeof(double) + sizeof(int) + 8;

  char* str = (char*)malloc(sizeof(char) * (n + 1));

  sprintf(str, "%s %s %s %.2f %.2f %d %s %s",
           a->gpsId, a->type, a->name,
           a->latitude, a->longitude, a->elevationFeet,
           a->city, a->countryAbbrv);

  return str;
}

double getAirDistance(const Airport* origin, const Airport* destination){
    if(origin == NULL || destination == NULL){
        return -1;
    }

    double latitudeOrigin = (origin->latitude/180.0) * M_PI;
    double longitudeOrigin = (origin->longitude/180.0) * M_PI;
    double latitudeDestination = (destination->latitude/180.0) * M_PI;
    double longitudeDestination = (destination->longitude/180.0) * M_PI;

    double difference = longitudeDestination - longitudeOrigin;
    double radius = 6371.0;
    double distance = acos(sin(latitudeOrigin) * sin(latitudeDestination) + cos(latitudeOrigin)
                      * cos(latitudeDestination) * cos(difference))* radius;

    return distance;
}

double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs){
  if(stops == NULL || size < 2 || aveKmsPerHour <= 0 || aveLayoverTimeHrs < 0){
    return -1;
  }

  double totalDistance = 0;
  double distance = 0;
  int r = 6371;

  int i = 0;
  int j = 1;
  while (j < size) {
    double latitudeA = (stops[i].latitude / 180) * M_PI;
    double latitudeB = (stops[j].latitude / 180) * M_PI;
    double longitudeA = (stops[i].longitude / 180) * M_PI;
    double longitudeB = (stops[j].longitude / 180) * M_PI;
    double differnce = longitudeB - longitudeA;
    distance = acos((sin(latitudeA) * sin(latitudeB)) + (cos(latitudeA) *
               cos(latitudeB) * cos(differnce))) * r;

    totalDistance += distance;
    j++;
    i++;
  }

  return ((totalDistance / aveKmsPerHour) + (aveLayoverTimeHrs * (size - 2)));
 }
