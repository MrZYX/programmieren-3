#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATAFILE_PATH "./employees.bin"

struct employee {
  char name[41];
  int personnumber;
  float  salary;
};

void binary_save(struct employee employees[], unsigned int n) {
  FILE* file = fopen(DATAFILE_PATH, "wb");
  fwrite(&n, sizeof(n), 1, file);
  fwrite(employees, sizeof(*employees), n, file);
  fclose(file);
}

void binary_load_and_print(void) {
  FILE* file = fopen(DATAFILE_PATH, "rb");
  struct employee* employees;
  int n, i;

  fread(&n, sizeof(n), 1, file);

  employees = malloc(n*sizeof(*employees));
  fread(employees, sizeof(*employees), n, file);

  fclose(file);
  
  printf("%d\n", n);
  for (i=0; i<n; i++) {
    printf("Employee %s\n", employees[i].name);
    printf("\tNumber: %d\n", employees[i].personnumber);
    printf("\tSalary: %f\n", employees[i].salary);
  }
  
  free(employees);
}

int main(void) {
  struct employee employees[5];
  strcpy(employees[0].name, "Fritz");
  employees[0].personnumber = 123;
  employees[0].salary = 1400.0;
  strcpy(employees[1].name, "Ernst");
  employees[1].personnumber = 142;
  employees[1].salary = 1300.0;
  strcpy(employees[2].name, "Hans");
  employees[2].personnumber = 105;
  employees[2].salary = 1500.0;
  strcpy(employees[3].name, "Egon");
  employees[3].personnumber = 113;
  employees[3].salary = 1600.0;
  strcpy(employees[4].name, "Birte");
  employees[4].personnumber = 100;
  employees[4].salary = 1700.0;
  
  binary_save(employees, 5);
  binary_load_and_print();
  
  return 0;
}
