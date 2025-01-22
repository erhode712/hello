/**
 * Author: Emma Rhode
 * Date: 2024/11/12
 *
 * This program performs several unit
 * tests on the airport utiliy fucntions.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "airport.h"

int main(){
int numTestsPassed = 0;
int numTestsFailed = 0;

Airport* airport1 = createAirport("HSND", "small_airport", "Shendi Airport", 16.7, 33.43, 1181, "Shendi", "SD-04");
    if (airport1 == NULL) {
        numTestsFailed++;
        printf("Test1: createAirport FAILED returned NULL\n");

    } else if (strcmp(airport1->gpsId, "HSND") == 0 && strcmp(airport1->type, "small_airport") == 0 &&
               strcmp(airport1->name, "Shendi Airport") == 0 && airport1->latitude == 16.7 &&
               airport1->longitude == 33.43 && airport1->elevationFeet == 1181 &&
               strcmp(airport1->city, "Shendi") == 0 && strcmp(airport1->countryAbbrv, "SD-04") == 0) {
        numTestsPassed++;
        printf("Test1: createAirport PASSED\n");
    } else {
        numTestsFailed++;
        printf("Test1: createAirport FAILED\n");
    }

    char* result = airportToString(airport1);
    if (strcmp(result, "HSND small_airport Shendi Airport 16.70 33.43 1181 Shendi SD-04") == 0) {
        numTestsPassed++;
        printf("Test2: airportToString PASSED\n");

    } else {
        numTestsFailed++;
        printf("Test2: airportToString Failed\n");
    }
    free(airport1->gpsId);
    free(airport1->type);
    free(airport1->name);
    free(airport1->city);
    free(airport1->countryAbbrv);
    free(airport1);

Airport* airport2 = createAirport("VYPP", "small_airport", "Hpapun Airport", 18.07, 97.45, 300, "Pa Pun", "MM-13");
    if (airport2 == NULL) {
       numTestsFailed++;
       printf("Test3: createAirport FAILED return NULL\n");

    } else if (strcmp(airport2->gpsId, "VYPP") == 0 && strcmp(airport2->type, "small_airport") == 0 &&
               strcmp(airport2->name, "Hpapun Airport") == 0 && airport2->latitude == 18.07 &&
               airport2->longitude == 97.45 && airport2->elevationFeet == 300 &&
               strcmp(airport2->city, "Pa Pun") == 0 && strcmp(airport2->countryAbbrv, "MM-13") == 0) {
        numTestsPassed++;
        printf("Test3: createAirport PASSED\n");
    } else {
        numTestsFailed++;
        printf("Test3: createAirport FAILED\n");
    }

        char* result2 = airportToString(airport2);
    if (strcmp(result2, "VYPP small_airport Hpapun Airport 18.07 97.45 300 Pa Pun MM-13") == 0) {
        numTestsPassed++;
        printf("Test4: airportToString PASSED\n");
    } else {
        numTestsFailed++;
        printf("Test4: airportToString FAILED\n");
    }
    free(airport2->gpsId);
    free(airport2->type);
    free(airport2->name);
    free(airport2->city);
    free(airport2->countryAbbrv);
    free(airport2);

 Airport* airport3 = createAirport("NK55", "heliport", "Onondaga Heliport", 43.09, -76.29, 400, "Camillus", "US-NY");
    if (airport3 == NULL) {
        numTestsFailed++;
        printf("Test5: createAirport FAILED return NULL\n");
    } else if (strcmp(airport3->gpsId, "NK55") == 0 && strcmp(airport3->type, "heliport") == 0 &&
               strcmp(airport3->name, "Onondaga Heliport") == 0 && airport3->latitude == 43.09 &&
               airport3->longitude == -76.29 && airport3->elevationFeet == 400 &&
               strcmp(airport3->city, "Camillus") == 0 && strcmp(airport3->countryAbbrv, "US-NY") == 0) {
        numTestsPassed++;
        printf("Test5: createAirport PASSED\n");
    } else {
        numTestsFailed++;
        printf("Test5: createAirport FAILED\n");
    }

    char* result3 = airportToString(airport3);
    if (strcmp(result3, "NK55 heliport Onondaga Heliport 43.09 -76.29 400 Camillus US-NY") == 0) {
        numTestsPassed++;
        printf("Test6: airportToString PASSED\n");
    } else {
        numTestsFailed++;
        printf("Test6: airportToString FAILED\n");
    }
    free(airport3->gpsId);
    free(airport3->type);
    free(airport3->name);
    free(airport3->city);
    free(airport3->countryAbbrv);
    free(airport3);

    Airport airport4 = {"KIXA", "small_airport", "Halifax-Northampton Regional Airport", 36.33, -77.64, 145, "Roanoke Rapids", "US-NC"};
    Airport airport5 = {"EDDH", "large_airport", "Hamburg Airport", 53.63, 9.99, 53, "Hamburg", "DE-HH"};
    Airport airports[] = {airport4, airport5};

    double averageSpeed1 = 317.116360;
    double averageLayoverTime1 = 0.877378;
    double estimatedTime1 = getEstimatedTravelTime(airports, 2, averageSpeed1, averageLayoverTime1);
    double expectedTime1 = 21.11;

    if (fabs(estimatedTime1 - expectedTime1) < 0.01) {
    numTestsPassed++;
    printf("Test7: getEstimatedTravelTime PASSED\n");
    } else {
        numTestsFailed++;
    printf("Test7: getEstimatedTravelTime FAILED\n");
    }

    Airport airport6 = {"JFK", "large_airport", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "New York", "US-NY"};
    Airport airport7 = {"LHR", "large_airport", "London Heathrow Airport", 51.4700, -0.4543, 83, "London", "GB-ENG"};
    Airport airports2[] = {airport6, airport7};

    double averageSpeed2 = 550.0;
    double averageLayoverTime2 = 1.5;
    double estimatedTime2 = getEstimatedTravelTime(airports2, 2, averageSpeed2, averageLayoverTime2);
    double expectedTime2 = 10.07;

    if (fabs(estimatedTime2 - expectedTime2) < 0.01) {
        numTestsPassed++;
        printf("Test8: getEstimatedTravelTime PASSED\n");
    } else {
        numTestsFailed++;
        printf("Test8: getEstimatedTravelTime FAILED\n");

    }

    Airport airport8 = {"SFO", "large_airport", "San Francisco International Airport", 37.6213, -122.3790, 13, "San Francisco", "US-CA"};
    Airport airport9 = {"SYD", "large_airport", "Sydney Kingsford Smith Airport", -33.9399, 151.1753, 21, "Sydney", "AU-NSW"};
    Airport airports3[] = {airport8, airport9};

    double averageSpeed3 = 800.0;
    double averageLayoverTime3 = 2.0;
    double estimatedTime3 = getEstimatedTravelTime(airports3, 2, averageSpeed3, averageLayoverTime3);
    double expectedTime3 = 14.94;

    if (fabs(estimatedTime3 - expectedTime3) < 0.01) {
        numTestsPassed++;
        printf("Test9: getEstimatedTravelTime PASSED\n");
    } else {
        numTestsFailed++;
        printf("Test9: getEstimatedTravelTime FAILED\n");
    }

 Airport* airport10 = (Airport*)malloc(sizeof(Airport));
    if (airport10 == NULL) {
        printf("Test10: initAirport FAILED\n");
        numTestsFailed++;
    } else {
        initAirport(airport10, "HSND", "small_airport", "Shendi Airport", 16.7, 33.43, 1181, "Shendi", "SD-04");

        if (airport10 == NULL ||
            strcmp(airport10->gpsId, "HSND") != 0 ||
            strcmp(airport10->type, "small_airport") != 0 ||
            strcmp(airport10->name, "Shendi Airport") != 0 ||
            airport10->latitude != 16.7 ||
            airport10->longitude != 33.43 ||
            airport10->elevationFeet != 1181 ||
            strcmp(airport10->city, "Shendi") != 0 ||
            strcmp(airport10->countryAbbrv, "SD-04") != 0) {

            numTestsFailed++;
            printf("Test10: initAirport FAILED\n");
        } else {
            numTestsPassed++;
            printf("Test1: initAirport PASSED\n");
        }

        free(airport10->gpsId);
        free(airport10->type);
        free(airport10->name);
        free(airport10->city);
        free(airport10->countryAbbrv);
        free(airport10);
    }

    Airport* airport11 = (Airport*)malloc(sizeof(Airport));
    if (airport11 == NULL) {
        printf("Test11: initAirport FAILED\n");
        numTestsFailed++;
    } else {
        initAirport(airport11, "JFK", "large_airport", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "New York", "US");

        if (airport11 == NULL ||
            strcmp(airport11->gpsId, "JFK") != 0 ||
            strcmp(airport11->type, "large_airport") != 0 ||
            strcmp(airport11->name, "John F. Kennedy International Airport") != 0 ||
            airport11->latitude != 40.6413 ||
            airport11->longitude != -73.7781 ||
            airport11->elevationFeet != 13 ||
            strcmp(airport11->city, "New York") != 0 ||
            strcmp(airport11->countryAbbrv, "US") != 0) {

            numTestsFailed++;
            printf("Test11: initAirport FAILED\n");
        } else {
            numTestsPassed++;
            printf("Test11: initAirport PASSED\n");
        }

        free(airport11->gpsId);
        free(airport11->type);
        free(airport11->name);
        free(airport11->city);
        free(airport11->countryAbbrv);
        free(airport11);
    }

    Airport* airport12 = (Airport*)malloc(sizeof(Airport));
    if (airport12 == NULL) {
        printf("Test12: initAirport FAILED\n");
        numTestsFailed++;
    } else {
        initAirport(airport12, "XYZ12", "medium_airport", "Airport12", 52.3500, 4.9167, 10, "City12", "CT12");

        if (airport12 == NULL ||
            strcmp(airport12->gpsId, "XYZ12") != 0 ||
            strcmp(airport12->type, "medium_airport") != 0 ||
            strcmp(airport12->name, "Airport12") != 0 ||
            airport12->latitude != 52.3500 ||
            airport12->longitude != 4.9167 ||
            airport12->elevationFeet != 10 ||
            strcmp(airport12->city, "City12") != 0 ||
            strcmp(airport12->countryAbbrv, "CT12") != 0) {

            numTestsFailed++;
            printf("Test12: initAirport FAILED\n");
        } else {
            numTestsPassed++;
            printf("Test12: initAirport PASSED\n");
        }

        free(airport12->gpsId);
        free(airport12->type);
        free(airport12->name);
        free(airport12->city);
        free(airport12->countryAbbrv);
        free(airport12);
    }

    Airport* airport13 = (Airport*)malloc(sizeof(Airport));
    Airport* airport14 = (Airport*)malloc(sizeof(Airport));
    if (airport13 == NULL || airport14 == NULL) {
        printf("Test13: getAirDistance FAILED\n");
        numTestsFailed++;
    } else {
        initAirport(airport13, "JFK", "large_airport", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "New York", "US");
        initAirport(airport14, "LHR", "large_airport", "London Heathrow Airport", 51.5074, -0.1278, 83, "London", "GB");

        double distance = getAirDistance(airport13, airport14);
        double expectedDistance = 5570.0;
        double marginOfError = 10;

        if (distance == -1 || fabs(distance - expectedDistance) > marginOfError) {
            numTestsFailed++;
            printf("Test13: getAirDistance FAILED\n");
        } else {
            numTestsPassed++;
            printf("Test13: getAirDistance PASSED\n");
        }

        free(airport13->gpsId);
        free(airport13->type);
        free(airport13->name);
        free(airport13->city);
        free(airport13->countryAbbrv);
        free(airport13);

        free(airport14->gpsId);
        free(airport14->type);
        free(airport14->name);
        free(airport14->city);
        free(airport14->countryAbbrv);
        free(airport14);
    }

    Airport* airport15 = (Airport*)malloc(sizeof(Airport));
    Airport* airport16 = (Airport*)malloc(sizeof(Airport));
    if (airport15 == NULL || airport16 == NULL) {
        printf("Test14: getAirDistance FAILED\n");
        numTestsFailed++;
    } else {
        initAirport(airport15, "A15", "medium_airport", "Airport15", 34.0522, -118.2437, 305, "Los Angeles", "US");
        initAirport(airport16, "A16", "medium_airport", "Airport16", 48.8566, 2.3522, 35, "Paris", "FR");

        double distance2 = getAirDistance(airport15, airport16);
        double expectedDistance2 = 9085.51;
        double marginOfError2 = 10.0;

        if (distance2 == -1 || fabs(distance2 - expectedDistance2) > marginOfError2) {
            numTestsFailed++;
            printf("Test14: getAirDistance FAILED\n");
        } else {
            numTestsPassed++;
            printf("Test14: getAirDistance PASSED\n");
        }

        free(airport15->gpsId);
        free(airport15->type);
        free(airport15->name);
        free(airport15->city);
        free(airport15->countryAbbrv);
        free(airport15);

        free(airport16->gpsId);
        free(airport16->type);
        free(airport16->name);
        free(airport16->city);
        free(airport16->countryAbbrv);
        free(airport16);
    }

    Airport* airport17 = (Airport*)malloc(sizeof(Airport));
    Airport* airport18 = (Airport*)malloc(sizeof(Airport));
    if (airport17 == NULL || airport18 == NULL) {
        printf("Test15: getAirDistance FAILED\n");
        numTestsFailed++;
    } else {
        initAirport(airport17, "A17", "medium_airport", "Airport17", 55.7558, 37.6173, 156, "Moscow", "RU");
        initAirport(airport18, "A18", "medium_airport", "Airport18", 40.7306, -73.9352, 10, "New York", "US");

        double distance3 = getAirDistance(airport17, airport18);
        double expectedDistance3 = 7500.0;
        double marginOfError3 = 10.0;

        if (distance3 == -1 || fabs(distance3 - expectedDistance3) > marginOfError3) {
            numTestsFailed++;
            printf("Test15: getAirDistance FAILED\n");
        } else {
            numTestsPassed++;
            printf("Test15: getAirDistance PASSED\n");
        }

        free(airport17->gpsId);
        free(airport17->type);
        free(airport17->name);
        free(airport17->city);
        free(airport17->countryAbbrv);
        free(airport17);

        free(airport18->gpsId);
        free(airport18->type);
        free(airport18->name);
        free(airport18->city);
        free(airport18->countryAbbrv);
        free(airport18);
    }

    printf("Number of Tests passed: %d\n", numTestsPassed);
    printf("Number of Tests failed: %d\n", numTestsFailed);

 return 0;
}
