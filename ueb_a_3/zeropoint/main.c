#include <stdio.h>
#include "bisection.h"

int main(void) {
  printf("Nullstelle [2, 4], eps=10^-8: %f\n", bisection(2, 4, 10e-8));
  printf("Nullstelle [4, 6], eps=10^-2: %f\n", bisection(4, 6, 10e-2));
  printf("Nullstelle [6, 8], eps=10^-8: %f\n", bisection(6, 8, 10e-8));
  
  return 0;
}
