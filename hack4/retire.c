/**
 * Author: Emma Rhode
 * Date: 2024/09/19
 * email: erhode3@huskers.unl.edu
 *
 * This program produces an amortization table for
 * a 401(k) account.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    if (argc != 6) {
        printf("ERROR: incorrect number of command line arguments\n");
        exit(1);
    }

    double balance = atof(argv[1]);
    double monthlyContributionAmount = atof(argv[2]);
    double returnRate = atof(argv[3]);
    double inflationRate = atof(argv[4]);
    int yearsUntilRetirement = atoi(argv[5]);

    double roundToCents(double amount);
    double annualContributionAmount = monthlyContributionAmount * 12;

    if (yearsUntilRetirement < 0) {
        printf("ERROR: invalid number of years.\n");
        exit(2);
    }
     if (returnRate > 1 || returnRate < 0) {
        printf("ERROR: invalid returnRate.\n");
        exit(3);
    }
     if (inflationRate > 1 || inflationRate < 0) {
        printf("ERROR: invalid inflationRate.\n");
        exit(4);
    }
     if (annualContributionAmount >= 18500) {
        printf("ERROR: monthly contributions exceed $18,500 annual limit.\n");
        exit(5);
    }

    int monthsUntilRetirement = yearsUntilRetirement * 12;
    double monthlyInflationAdjustedRate = (((1 + returnRate )/(1 + inflationRate)) - 1) / 12;
    double totalInterest = 0;

    printf("Month    Interest    Balance\n");

    for(int i = 1; i <= monthsUntilRetirement; i++){
        double monthlyInterest = roundToCents(monthlyInflationAdjustedRate * balance);
        balance += roundToCents(monthlyInterest + monthlyContributionAmount);
        totalInterest += monthlyInterest;
        printf("%d $    %0.2lf $    %0.2lf\n ", i, monthlyInterest, balance);
    }

    printf("Total Interest Earned: $ %0.2lf\n" , totalInterest);
    printf("Total Nest Egg: $ %0.2lf\n" , balance);


    return 0;


}
    double roundToCents(double amount){
        return round(amount * 100.0) / 100.0;
    }
