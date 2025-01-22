#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "airport.h"

void generateReports(Airport *airports, int n) {

  printf("Airports (original): \n");
  printf("==============================\n");
  printAirports(airports, n);

  printf("\nAirports By GPS ID: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByGPSId);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nAirports By Type: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nAirports By Name: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByName);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nAirports By Name - Reversed: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByNameDesc);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nAirports By Country/City: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nAirports By Latitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLatitude);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nAirports By Longitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nAirports By Distance from Lincoln: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  for(int i = 0; i < n; i++){
    printf("%s\n", airportToString(&airports[i]));
  }

  printf("\nClosest Airport to Lincoln: \n");
  printf("==============================\n");
  printf("%s\n", airportToString(&airports[0]));

  printf("\nFurthest Airport from Lincoln: \n");
  printf("==============================\n");
  printf("%s\n", airportToString(&airports[n - 1]));

  printf("\nEast-West Geographic Center: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printf("%s\n", airportToString(&airports[n / 2]));

  printf("\nNew York, NY airport: \n");
  printf("==============================\n");
  int foundNY = 0;
  for(int i = 0; i < n; i++){
    if(strcmp(airports[i].city, "New York") == 0){
        printf("%s\n", airportToString(&airports[i]));
        foundNY = 1;
    }
  }
      if(foundNY == 0){
        printf("No New York airport found!\n");
    }

  printf("\nLarge airport: \n");
  printf("==============================\n");
  int found = 0;
  for(int i = 0; i < n; i++){
    if(strcmp(airports[i].type, "large_airport") == 0){
        printf("%s\n", airportToString(&airports[i]));
        found = 1;
    }
  }
    if(found == 0){
        printf("No large airport found!\n");
    }

  return;
}

char* airportToString(const Airport* a) {
  char temp[1000];
  sprintf(temp, "%-8s %-15s %-20s %.2f %.2f %d %-10s %-2s", a->gpsId, a->type, a->name,
          a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);
  char* result = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
  strcpy(result, temp);
  return result;
}

void printAirports(Airport *airports, int n) {
  for(int i=0; i<n; i++) {
    char *s = airportToString(&airports[i]);
    printf("%s\n", s);
    free(s);
  }

  return;
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
    double difference = longitudeB - longitudeA;
    distance = acos((sin(latitudeA) * sin(latitudeB)) + (cos(latitudeA) *
               cos(latitudeB) * cos(difference))) * r;

    totalDistance += distance;
    j++;
    i++;
  }

  return ((totalDistance / aveKmsPerHour) + (aveLayoverTimeHrs * (size - 2)));
 }

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

int cmpByGPSId(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  return strcmp(a1->gpsId, a2->gpsId);

}

int cmpByType(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  return strcmp(a1->type, a2->type);
}

int cmpByName(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  return strcmp(a1->name, a2->name);
}

int cmpByNameDesc(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  return -(strcmp(a1->name, a2->name));

}

int cmpByCountryCity(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  int result = strcmp(a1->countryAbbrv, a2->countryAbbrv);
  if (result == 0) {
    result = strcmp(a1->city, a2->city);
  }
  return result;
}

int cmpByLatitude(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;

  if(a1->latitude < a2->latitude){
    return 1;
  }
  else if(a1->latitude > a2->latitude){
    return -1;
  }
    return 0;
}

int cmpByLongitude(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;

  if(a1->longitude < a2->longitude) {
      return -1;
  }
  else if(a1->longitude > a2->longitude) {
      return 1;
  }
  else {
      return 0;
  }
}

int cmpByLincolnDistance(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  Airport *lincoln = createAirport("", "", "Lincoln Municipal Airport", 40.846176, -96.75471, 0.0, "Lincoln", "USA");
  double result1 = getAirDistance(a1, lincoln);
  double result2 = getAirDistance(a2, lincoln);

  if(result1 > result2){
    return 1;
  }
  else if(result1 < result2){
    return -1;
  }
    return 0;
}
