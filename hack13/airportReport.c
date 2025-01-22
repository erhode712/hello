#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport.h"

int main() {
    Airport airports[5];

    initAirport(&airports[0], "LAX1", "huge", "Los Angeles International", 33.94, -118.41, 128, "Los Angeles", "US");
    initAirport(&airports[1], "JFK0", "intl", "John F. Kennedy", 40.64, -73.78, 13, "New York", "US");
    initAirport(&airports[2], "FRA0", "large_airport", "Frankfurt Airport", 50.03, 8.56, 100, "Frankfurt", "DE");
    initAirport(&airports[3], "SFO3", "huge", "San Francisco International", 37.62, -122.38, 15, "San Francisco", "US");
    initAirport(&airports[4], "SYD1", "intl", "Sydney Kingsford Smith", -33.93, 151.17, 21, "Sydney", "AU");

    generateReports(airports, 5);

    for (int i = 0; i < 5; i++) {
        free(airports[i].gpsId);
        free(airports[i].type);
        free(airports[i].name);
        free(airports[i].city);
        free(airports[i].countryAbbrv);
    }

    return 0;
}
