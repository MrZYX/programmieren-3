#include <stdio.h>
#include <string.h>

struct int20 {
  char number[20];
};

struct int20 create20(char* number) {
  struct int20 newNumber = { "00000000000000000000" };
  int i;
  int size = strlen(number)+1;
  
  for(i = 0; i <= 20 && i <= size-1; i++) {
    newNumber.number[20-i] = number[size-i-1];
  }
  
  return newNumber;
}

struct int20 add20(struct int20 a, struct int20 b) {
  struct int20 sum;
  int i;
  int carry = 0;
  
  for(i = 19; i >= 0; i--) {
      sum.number[i] = a.number[i]+b.number[i]+carry-'0';
      if (sum.number[i] > '9') {
        carry = 1;
        sum.number[i] -= 10;
      } else {
        carry = 0;
      }
  }
  
  return sum;
}

void print20(struct int20 number) {
  int i;
  int leadingZeros = 1;
  
  for(i = 0; i < 20; i++) {
    if (leadingZeros != 1 || number.number[i] != '0') {
      leadingZeros = 0;
      printf("%c", number.number[i]);
    }
  }
}

void example(char *aNumber, char *bNumber) {
  struct int20 a = create20(aNumber);
  struct int20 b = create20(bNumber);
  struct int20 sum = add20(a, b);
  print20(a);
  printf("\n");
  
  print20(b);
  printf("\n");
  
  print20(sum);
  printf("\n");
}

int main(void){
  example("12345678901234567890", "100");
  printf("\n");
  example("9700", "422");
  return 0;
}
