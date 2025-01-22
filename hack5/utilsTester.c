/**
 * Author: Emma Rhode
 * Date: 2024/10/03
 *
 * This program performs several unit
 * tests on the utils library.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "utils.h"
#define DELTA 0.0001

/**
 * This function returns true if the two given
 * values x, y are within DELTA of each other.
 */
int isClose(double x, double y);

int main(int argc, char **argv) {

  int reportPass = 0;

  double c;
  double expectedD, actualD;
  int numPassed = 0;
  int numFailed = 0;

  c = 123.0;
  expectedD = 2.14675498;
  printf("TESTING: degreesToRadians(%f): ", c);
  actualD = degreesToRadians(c);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  c = 5.6;
  expectedD = 0.09773844;
  printf("TESTING: degreesToRadians(%f): ", c);
  actualD = degreesToRadians(c);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  c = 50.25;
  expectedD = 0.87702795;
  printf("TESTING: degreesToRadians(%f): ", c);
  actualD = degreesToRadians(c);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  double e, f, g, h;

  e = 40;
  f = 90;
  g = -60;
  h = -50;
  expectedD = 16481.382918;
  printf("TESTING: getAirDistance(%f , %f, %f, %f): ", e, f, g, h);
  actualD = getAirDistance(e, f, g, h);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  e = 10;
  f = 50.75;
  g = 70;
  h = 45.5;
  expectedD = 6682.085594;
  printf("TESTING: getAirDistance(%f , %f, %f, %f): ", e, f, g, h);
  actualD = getAirDistance(e, f, g, h);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  e = -5;
  f = 18;
  g = -40.8;
  h = 170;
  expectedD = 14178.419348;
  printf("TESTING: getAirDistance(%f , %f, %f, %f): ", e, f, g, h);
  actualD = getAirDistance(e, f, g, h);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  double a;
  double b;

  a = 10;
  b = 0.25;
  expectedD = 10.328;
  printf("TESTING: lorentzTimeDilation(%f , %f): ", a, b);
  actualD = lorentzTimeDilation(a ,b);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  a = 80;
  b = 0.50;
  expectedD = 92.376;
  printf("TESTING: lorentzTimeDilation(%f , %f): ", a, b);
  actualD = lorentzTimeDilation(a ,b);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  a = 19;
  b = 0.90;
  expectedD = 43.589;
  printf("TESTING: lorentzTimeDilation(%f , %f): ", a, b);
  actualD = lorentzTimeDilation(a ,b);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("Number Test Cases Passed: %6d\n", numPassed);
  printf("Number Test Cases Failed: %6d\n", numFailed);
  printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));

  if(reportPass) {
    return numPassed;
  } else {
    return numFailed;
  }

}

int isClose(double x, double y) {
  return (fabs(x-y) < DELTA);
}
