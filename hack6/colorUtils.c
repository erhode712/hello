#include "colorUtils.h"
#include <math.h>
#include <stddef.h>

double max(double a, double b, double c) {
    return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k){
    if(c == NULL || m == NULL || y == NULL || k == NULL){
        return 1;
    }
    if(r < 0 || r > 255){
        return 2;
    }
     if(g < 0 || g > 255){
        return 3;
    }
     if(b < 0 || b > 255){
        return 4;
    }

   if(r == 0 && b == 0 && g == 0){
    *c = 0;
    *m = 0;
    *y = 0;
    *k = 1;
    return 0;
   }

   double red = r/255.0;
   double blue = b/255.0;
   double green = g/255.0;

   *k = 1 - max(red, green, blue);
   *c = (1 - red - (*k)) / (1 - (*k));
   *m = (1 - green - (*k)) / (1 - (*k));
   *y = (1 - blue - (*k)) / (1 - (*k));

    return 0;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b){
    if(r == NULL || g == NULL || b == NULL){
        return 1;
    }
    if(c < 0 || c > 1){
        return 2;
    }
     if(m < 0 || m > 1){
        return 3;
    }
     if(y < 0 || y > 1){
        return 4;
    }
     if(k < 0 || k > 1){
        return 5;
    }

    *r = round(255 * (1 - c) * (1 - k));
    *g = round(255 * (1 - m) * ( 1 - k));
    *b = round(255 * (1 - y) * ( 1 - k));
    
    return 0;
}
