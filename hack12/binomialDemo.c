#include <stdlib.h>
#include <stdio.h>
#include "binomial.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    return 1;
  }

  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

  long **table =(long **) malloc((n+1) * sizeof(long *));
  for (int i = 0; i < (n+1); i++){
    table[i] = (long *)malloc((k+1) * sizeof(long));
  }

  for (int i = 0; i < (n+1); i++){
   for(int j = 0; j < (k+1); j++){
    table[i][j] = -1;
   }
  }

  long result2 = chooseTable(n, k, table);

  printf("chooseTable(%d, %d) = %ld\n", n, k, result2);

  for(int i = 0; i < (n+1); i++){
    free(table[i]);
  }
  free(table);

  return 0;
}
