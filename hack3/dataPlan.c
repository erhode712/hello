/**
 * Author: Emma Rhode
 * Date: 2024/09/12
 * email: erhode3@huskers.unl.edu
 *
 * This program helps customers track their mobile
 * data usage.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("ERROR: incorrect number of command line arguments\n");
        exit(1);
    }

    double GBtotal = atof(argv[1]);
    int day = atoi(argv[2]);
    double GBused = atof(argv[3]);

    if (day < 1 || day > 30) {
        printf("ERROR: invalid number of days.\n");
        exit(2);
    }
    if (GBtotal == 0) {
        printf("ERROR: invalid number of gigabytes\n");
        exit(3);
    }

    double GBleft = GBtotal - GBused;
    double averageDailyUse = GBused / day;
    double rate = GBtotal / 30.0;
    int daysLeft = 30 - day;
    double averageOver = averageDailyUse - rate;

    if (GBtotal < GBused) {
        printf("%d days used, %d days remaining\n", day, daysLeft);
        printf("Average daily use: %0.3lf GB/day\n", averageDailyUse);
        printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");

    } else if (averageDailyUse > rate) {
        double GBover = fabs((rate * 30.0) - (averageDailyUse * 30.0));
        double GBbelow = GBleft / daysLeft;
        printf("%d days used, %d days remaining\n", day, daysLeft);
        printf("Average daily use: %0.3lf GB/day\n\n", averageDailyUse);
        printf("You are EXCEEDING your average daily use by (%0.3lf GB/day)\n", averageOver);
        printf("Continuing this high usage, you'll exceed your data plan by %0.3lf GB\n\n", GBover);
        printf("To stay below your data plan, use no more than %0.3lf GB/day\n", GBbelow);

    } else if (averageDailyUse < rate) {
        double averageUnder = GBleft / daysLeft;
        printf("%d days used, %d days remaining\n", day, daysLeft);
        printf("Average daily use: %0.3lf GB/day\n\n", averageDailyUse);
        printf("You are at or below your average daily use: (%0.3lf GB/day)\n", rate);
        printf("You can use up to %0.3lf GB/day and stay below your data plan limit\n", averageUnder);
    }

    return 0;
}
