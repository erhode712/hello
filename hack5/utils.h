/**
 * Author: Emma Rhode
 * Date: 2024/10/03
 *
 * A collection of utility functions.
*/

/**
 * Converts and returns from radians to degrees.
 */
double degreesToRadians(double degree);

/**
 * Computes and returns the air distance between two locations
 * identified by their latitude/longitude.
 *
 * Latitude and longitude are expected to be in radians
 * and then are converted to degrees. Latitude should be in
 * the range [-90,90]. Longitude should be in the range
 * [-180,180].
 */
double getAirDistance(double originLatitude,
                      double originLongitude,
                      double destinationLatitude,
                      double destinationLongitude);

/**
 * Computes and returns the dilated time given
 * the normal time and the percentage speed of light.
 *
 * The percent is expected to be between [0,1].
 */
double lorentzTimeDilation(double t, double percentC);

