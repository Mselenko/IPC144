/*
Name: Margarita Selenko
Student number:147393169
Email:margonia111@gmail.com
Workshop:5
Section: IPCSTX
Date:10/16/17
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4

struct Employee {
  int id;
  int age;
  double salary;
};

int main(void) {
  int b = 0;
  int cnt;
  int a = 0;
  int num = 0;
  int option = 0;
  printf("---=== EMPLOYEE DATA ===---\n\n");

  struct Employee emp[SIZE] = { { 0,0,0.0 } };

  do {
    printf("1. Display Employee Information\n");
    printf("2. Add Employee\n");
    printf("3. Update Employee Salary\n");
    printf("4. Remove Employee\n");
    printf("0. Exit\n\n");
    printf("Please select from the above options: ");
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
      if (num < SIZE) {
        printf("Enter Employee ID: ");
        scanf("%d", &emp[num].id);
        printf("Enter Employee Age: ");
        scanf("%d", &emp[num].age);
        printf("Enter Employee Salary: ");
        scanf("%lf", &emp[num].salary);
        printf("\n");
        num++;
      }
      else {
        printf("ERROR!!! Maximum Number of Employees Reached\n\n");
      }
      break;

    case 3:
      printf("Update Employee Salary\n");
      printf("=====================\n");
      do {
        printf("Enter Employee ID: ");
        scanf("%d", &b);
        for (cnt = 0; cnt < SIZE; cnt++) {
          if (b == emp[cnt].id) {
            printf("The current salary is %0.2lf\n", emp[cnt].salary);
            printf("Enter Employee New Salary: ");
            scanf("%lf", &emp[cnt].salary);
            printf("\n");
            b = -1;
          }
        }
      } while (b != -1);
      break;

    case 4:
      printf("Remove Employee\n");
      printf("================\n");
      do {
        printf("Enter Employee ID: ");
        scanf("%d", &a);
        for (cnt = 0; cnt < SIZE; cnt++) {
          if (a == emp[cnt].id) {
            printf("Employee %d will be removed\n\n", a);
            emp[cnt].id = 0;
            a = -1;
            num--;
          }
        }
      } while (a != -1);  
      break;

    default:
      printf("ERROR: Incorrect Option: Try Again\n\n");
    }
  } while (option != 0);
  return 0;
}
