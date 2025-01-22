#include <stdlib.h>
#include <stdio.h>
#include "binomial.h"

long choose(int n, int k){
  if(k < 0|| n < 0 || k > n){
     return 0;
  }
  else if(n == k || k == 0){
     return 1;
    }
  else{
     return (choose(n-1, k - 1) + choose(n-1, k));
  }
}

long chooseTable(int n, int k, long **table){
  if(k < 0|| n < 0 || k > n || table == NULL){
     return 0;
  }
  else if(n == k || k == 0){
     return 1;
  }
  else if(table[n][k] != -1){
     return table[n][k];
  } else {
     table[n][k] = chooseTable((n-1), k, table) + chooseTable((n-1), (k-1), table);
     return (chooseTable((n-1), k, table) + chooseTable((n-1), (k-1), table));
  }
}

