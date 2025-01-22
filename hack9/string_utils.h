/**
 * Author: Emma Rhode
 * Date: 2024/10/03
 *
 * A collection of utility functions.
*/

/**
 * Replaces instances of a given character with a different
 * character in a string.
 */
void replaceChar(char *s, char oldChar, char newChar);

/**
 * Takes a string and creates and returns a new copy of it but with
 * instances of a given character replaced with a different character.
 */
char * replaceCharCopy(const char *s, char oldChar, char newChar);

/**
 * Takes a string and removes all instances of a certain
 * character from it.
 */
void removeChar(char *s, char c);

/**
 * Takes a string and creates and returns and new copy of it
 * but with all instances of the given character removed from it.
 */
char * removeCharCopy(const char *s, char c);

/**
 * Takes a string and splits it up into an array of strings.
 * The split up will be lenegth based on the given integer.
 * Returns the new array of strings.
 */
char **lengthSplit(const char *s, int n);

