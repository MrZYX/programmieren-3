#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10


struct employee {
  char name[41];
  int employeeNumber;
  float salary;
};


void deleteEmployee(struct employee **employee) {
  free(*employee);
  *employee = NULL;
}

void freeEmployees(struct employee  *employees[]) {
  int i;
  
  for (i=0; i < ARRAY_LENGTH; i++) {
    deleteEmployee(&(employees[i]));
  }
}

void dumpEmployee(struct employee *employee) {
  printf("Name: %s, Employee number: %d, Salary: %f",
         employee->name, employee->employeeNumber, employee->salary);
}

void dumpEmployees(struct employee *employees[]) {
  int i;
  
  printf("Current data:");
  for (i=0; i < ARRAY_LENGTH; i++) {
    printf("\n  %d: ", i);
    if (employees[i] == NULL) {
      printf("Free slot");
    } else {
      dumpEmployee(employees[i]);
    }
  }
  printf("\n");
}

void clearInputBuffer(void) { while(getchar() != '\n') {} }

void createEmployee(struct employee **employee) {
  *employee = malloc(sizeof(**employee));
  printf("Create new employee:\n");
  printf("  Name: ");
  scanf("%41[^\n]", (*employee)->name);
  printf("  Employee number: ");
  scanf("%d", &((*employee)->employeeNumber));
  printf("  Salary: ");
  scanf("%f", &((*employee)->salary));
  clearInputBuffer();
}

int determineIndex(struct employee *employees[]) {
  int index;
  
  do {
    printf("Please select a valid data slot (0-%d): ", ARRAY_LENGTH-1);
    scanf("%d", &index);
    clearInputBuffer();
  } while (index < 0 || index > ARRAY_LENGTH-1);
  
  return index;
}

void updateEmployees(struct employee *employees[]) {
  int index = determineIndex(employees);
  
  if (employees[index] == NULL) {
    createEmployee(&(employees[index]));
  } else {
    deleteEmployee(&(employees[index]));
    printf("Deleted entry %d.", index);
  }
}

int determineAction(void) {
  int action;
  
  printf("Please choose what you want to do:\n");
  printf("  <1> Modify employees\n");
  printf("  <0> Dump collected data and exit\n");
  printf("Please enter a number: ");
  scanf("%d", &action);
  clearInputBuffer();
  
  return action;
}

void initializeEmployees(struct employee *employees[]) {
  int i;
  
  for (i=0; i < ARRAY_LENGTH; i++) {
    employees[i] = NULL;
  }
}

int main(void) {
  struct employee *employees[ARRAY_LENGTH];
  int action;
  
  initializeEmployees(employees);
  
  do {
    action = determineAction();
    if (action == 1) {
      printf("\n\n");
      
      updateEmployees(employees);
      printf("\n\n");
      
      dumpEmployees(employees);
      printf("\n\n");
    } else if (action != 0) {
      printf("Please choose <0> or <1>!\n");
    }
    
  } while (action != 0);
  
  dumpEmployees(employees);
  freeEmployees(employees);
  
  return 0;
}
