/**
 * Author: Emma Rhode
 * Date: 2024/10/10
 * email: erhode3@huskers.unl.edu
 *
 * A collection of utility functions to convert color values;.
*/

/**
 * Returns the max value of 3 integers.
 */
double max(double a, double b, double c);

/**
 * Converts values from a RGB color model to CMYK.
 * Returns an error code.
 *
 * values r, g, and b are on the scale [0,255].
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/**
 * Converts values from a CMYK color model to RGB;
 * Returns an error code.
 *
 * values c, m, y, and k are on the scale [0,1].
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);
