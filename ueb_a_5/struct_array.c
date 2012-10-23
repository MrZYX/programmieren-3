#include <stdio.h>
#include <stdlib.h>

struct employee {
  char name[41];
  int employeeNumber;
  float salary;
};

void clearInputBuffer(void) { while(getchar() != '\n') {} }

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

int determineIndex(void) {
  int index;
  
  do {
    printf("Please select a valid data slot (0-9): ");
    scanf("%d", &index);
    clearInputBuffer();
  } while (index < 0 || index > 9);
  
  return index;
}

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

void deleteEmployee(struct employee **employee) {
  free(*employee);
  *employee = NULL;
}


void updateEmployees(struct employee *employees[]) {
  int index = determineIndex();
  
  if (employees[index] == NULL) {
   createEmployee(&(employees[index]));
  } else {
    deleteEmployee(&(employees[index]));
    printf("Deleted entry %d.", index);
  }
}

void dumpEmployee(struct employee *employee) {
  printf("Name: %s, Employee number: %d, Salary: %f",
         employee->name, employee->employeeNumber, employee->salary);
}

void dumpEmployees(struct employee *employees[]) {
  int i;
  
  printf("Current data:");
  for (i=0; i < 10; i++) {
    printf("\n  %d: ", i);
    if (employees[i] == NULL) {
      printf("Free slot");
    } else {
      dumpEmployee(employees[i]);
    }
  }
  printf("\n");
}

void freeEmployees(struct employee  *employees[]) {
  int i;
  
  for (i=0; i < 10; i++) {
    deleteEmployee(&(employees[i]));
  }
}

int main(void) {
  struct employee *employees[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
  int action;
  
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
