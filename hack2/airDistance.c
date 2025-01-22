/**
 * Author: Emma Rhode
 * Date: 2024/09/05
 *
 * This program interactivley prompts the user to
 * enter the latitude and longitude of two locations
 * then outputs the distance between them using the
 * Spherical Law of Cosines.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double distance, difference, latitudeA, longitudeA, latitudeB, longitudeB;

        printf("Please enter latitude of location A: \n");
    scanf("%lf", &latitudeA);
        printf("Please enter longitude of location A: \n");
    scanf("%lf", &longitudeA);
        printf("Please enter latitude of location B: \n");
    scanf("%lf", &latitudeB);
        printf("Please enter longitude of location B: \n");
    scanf("%lf", &longitudeB);

    latitudeA = (latitudeA/180.0) * M_PI;
    longitudeA = (longitudeA/180.0) * M_PI;
    latitudeB = (latitudeB/180.0) * M_PI;
    longitudeB = (longitudeB/180.0) * M_PI;

    difference = longitudeB - longitudeA;
    double radius = 6371.0;
    distance = acos(sin(latitudeA) * sin(latitudeB) + cos(latitudeA) * cos(latitudeB) * cos(difference))* radius;

    printf("Location Distance:\n================\n");
    printf("Origin: (%.6lf, %.6lf)\n", latitudeA, longitudeA);
    printf("Destination: (%.6lf, %.6lf)\n", latitudeB, longitudeB);
    printf("Air distance is %.6lf kms\n", distance);

  return 0;
}
