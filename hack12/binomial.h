/**
 * Author: Emma Rhode
 * Date: 2024-11-21
 *
 * Functions using recursion
 */

/**
 * Using Pascal's rule, computes "n choose k" and returns the value.
 */
long choose(int n, int k);

/**
 * Using Pascal's rule, computes "n choose k" with the given table and
 * returns the value. Assumes table values are -1 to begin.
 */
long chooseTable(int n, int k, long **table);

