#include <stdio.h>

int main(void) {
  int a[] = { 1, 2, 3, 4, 5 };
  int b[5];
  int *ap, *bp;
  int i;
  
  ap = &a[0];
  bp = &b[0];
  
  for (i=0; i<5; i++) {
    *(bp+(4-i)) = *(ap+i);
  }
  
  bp = &b[0];
  
  for (i=0; i<5; i++) {
    printf("%d ", *(bp+i));
  }
  printf("\n");
  
  return 0;
}
