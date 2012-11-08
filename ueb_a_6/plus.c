#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h> 

int main(int argc, char* argv[]) {
  long a, b;
  char* endptr = NULL;
  
  if (argc != 3) {
    printf("Usage %s: <number> <number>\n", argv[0]);
    return 1;
  }
  
  errno = 0;
  a = strtol(argv[1], &endptr, 10);
  
  if (endptr != NULL && (*endptr != 0 || endptr == (void*) argv[1])) {
    printf("Can't convert '%s' to number: Wrong format\n", argv[1]);
    return 2;
  }
  
  if ((errno == ERANGE && (a == LONG_MAX || a == LONG_MIN)) || (errno != 0 && a == 0)) {
    printf("Can't convert '%s' to number: %s\n", argv[1], strerror(errno));
    return 3;
  }
  
  errno = 0;
  endptr = NULL;
  b = strtol(argv[2], &endptr, 10);
  
  if (endptr != NULL && (*endptr != 0 || endptr == (void*) argv[2])) {
    printf("Can't convert '%s' to number: Wrong format", argv[2]);
    return 2;
  }
  
  if ((errno == ERANGE && (b == LONG_MAX || b == LONG_MIN)) || (errno != 0 && b == 0)) {
    printf("Can't convert '%s' to number: %s\n", argv[2], strerror(errno));
    return 3;
  }
  
  printf("%ld + %ld = %ld\n", a, b, a+b);
  
  return 0;
}
