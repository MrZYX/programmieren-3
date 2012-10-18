#include <math.h>
#include "bisection.h"
#include "function.h"

double bisection(double a, double b, double eps) {
  double x;
  
  if (function(a)*function(b) > 0) {
    return a-eps;
  }
  
  x = (a+b)/2;
  
  if (fabs(b-a) < eps) {
    return x;
  } else {
    if (function(a)*function(x) < 0) {
      return bisection(a, x, eps);
    } else {
      return bisection(x, b, eps);
    }
  }
  
}
