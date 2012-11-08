#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
  char cmd[32] = "ls -la ";
  char pattern[32];
  char* buf;
  
  printf("Bitte Dateimuster angeben\n");
  printf(" * bedeutet Joker\n");
  printf(" ? ist ein Joker für ein einzelnes Zeichen\n");
  printf("Ihre Eingabe: ");
  
  /* read all including spaces and tabs to the end of the line */
  scanf("%31[^\n]", pattern);
  buf= malloc(strlen(cmd)+strlen(pattern)+1);
  buf[0]= '\0';
  strcat(buf, cmd);
  strcat(buf, pattern);
  
  system(buf);
  
  free(buf);

  return 0;
}
