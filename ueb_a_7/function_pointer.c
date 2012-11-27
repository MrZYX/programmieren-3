#include <stdio.h>


void print(void) {
  printf("Hallo Welt!\n");
}

void print2(int i) {
  printf("%d\n", i);
}

void times(int n, void (*func) (void)) {
  int i;
  for (i=0; i<n; i++) {
    func();
  }
}

void times2(int n, void (*func) (int)) {
  int i;
  for (i=0; i<n; i++) {
    func(i);
  }
}

int main(void) {
  times(3, print);
  times2(3, print2);
  return 0;
}
