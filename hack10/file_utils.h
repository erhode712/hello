/**
 * A collection of utility functions using files.
 */

/**
 * Given a file path/name as a string, opens the file and returns its entire
 * contents as a single string. Endline characters are preserved.
 */
char *getFileContents(const char *filePath);

/**
 * Given a file path/name as a string, opens the file and returns the
 * contents of the file as an array of strings. Each elements corresponds
 * to a line in the file.
 */
char **getFileLines(const char *filePath, int *numLines);

/**
 * Removes whitespace from the given string.
 */
void rtrim(char *str);

/**
 * Takes a string and creates and returns a new copy of it but with
 * instances of a given character replaced with a different character.
 */
char * replaceCharCopy(const char *s, char oldChar, char newChar);

/**
 * Takes a string and splits it up into an array of strings.
 * The split up will be lenegth based on the given integer.
 * Returns the new array of strings.
 */
char **lengthSplit(const char *s, int n);

/**
 * Takes a string and removes all instances of a certain
 * character from it.
 */
void removeChar(char *s, char c);
