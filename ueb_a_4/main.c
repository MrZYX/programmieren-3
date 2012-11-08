#include <stdio.h>
void c2(void) {
  int a[]= { 1, 5, 19, -4, 3 };
  int *p;
  int i;
  /* Lasse p auf das 0-te Array-Element verweisen. */
  p = a;
  
  for (i=1; i<5; i++) {
    /* Prüfe, ob das Array-Element i größer als das von
       p referenzierte Element ist */
    if (a[i] > *p) {
      /* Lasse p auf das Array-Element i verweisen */
      p = a+i;
    }
  }
  /* Gib das von p referenzierte Element als das größte aus: */
  printf("Maximum: %d\n", *p );
}
int main(void) {
  c2();
  return 0;
}
