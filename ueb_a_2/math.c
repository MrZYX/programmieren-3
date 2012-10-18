#include <stdio.h>
#include <string.h>
#include "summe.h"
#include "differenz.h"

void calculate(void) {
  char mode;
  int result;
  printf("Ihre Whale:\n");
  printf("<S>umme oder <D>ifferenz? ");
  scanf("%c", &mode);

  if (strcmp(&mode, "S") == 0) {
    result = summe();
  } else if (strcmp(&mode, "D") == 0) {
    result = differenz();
  }

  printf("Ergebnis: %d\n", result);
}

int main(void) {
  calculate();
  return 0;
}
