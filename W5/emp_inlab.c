/*
Name: Margarite Selenko
Student number:147393169
Email:mselenko@
Workshop:5
Section:
Date:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 2

struct Employee{
  int id;
  int age;
  double salary;
};


// Declare Struct Employee 


/* main program */
int main(void) {
 
  int cnt;
  int numofEmployee = 0;
  int option = 0;
  printf("---=== EMPLOYEE DATA ===---\n\n");

  struct Employee emp[SIZE] = { {0,0,0.0} };

  // Declare a struct Employee array "emp" with SIZE elements 
  // and initialize all elements to zero

  do {
    // Print the option list
    printf("1. Display Employee Information\n");
    printf("2. Add Employee\n");
    printf("0. Exit\n\n");
    printf("Please select from the above options: ");

    // Capture input to option variable
    scanf("%d", &option);
    printf("\n");

    switch (option) {
    case 0:
      printf("Exiting Employee Data Program. Good Bye!!!\n");
      break;

    case 1: 
      printf("EMP ID  EMP AGE EMP SALARY\n");
      printf("======  ======= ==========\n");
      for (cnt = 0; cnt < SIZE; cnt++) {
        if (emp[cnt].id > 0) {
          printf("%6d%9d%11.2lf\n", emp[cnt].id, emp[cnt].age, emp[cnt].salary);
        }
      }
      printf("\n");
      break;

    case 2:
      printf("Adding Employee\n");
      printf("===============\n");
      if (numofEmployee < SIZE) {
         printf("Enter Employee ID: ");
        scanf("%d", &emp[numofEmployee].id);
        printf("Enter Employee Age: ");
        scanf("%d", &emp[numofEmployee].age);
        printf("Enter Employee Salary: ");
        scanf("%lf", &emp[numofEmployee].salary);
        printf("\n");
        numofEmployee++;    
      }
      else {
        printf("\nERROR!!! MAximum Number of Employees Reached\n");
      }   
      break;
    default:
      printf("\nERROR: Incorrect Option: Try Again\n");
    }
  } while (option != 0);
  return 0;
}