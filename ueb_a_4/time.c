#include <stdio.h>
#include <time.h>

int main(void) {
  time_t timestamps[] = { 645703200, 49888800};
  printf("%s\n", ctime(&timestamps[0]));
  printf("%s\n", ctime(&timestamps[1]));
  return 0;
}
