/* -------------------------------------------
Name: Margarita Selenko
Student number: 147393169
Email: mselenko@myseneca.ca
Section: IPCSTX
Date: 26 October
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the nenamet line:
#include "contacts.h"
void getPostalCode(char *p) {
  char pc1[4];
  char pc2[4];
  scanf("%s", pc1);
  scanf("%s", pc2);
  for (int i = 0; i <= 7; i++)
  {
    if (i < 3)
      p[i] = pc1[i];
    if (i == 3)
      p[i] = ' ';
    if (i > 3)
      p[i] = pc2[i - 4];
    if (i == 7)
      p[i] = '\0';
  }
}


int main(void)
{
  struct Name name = {0};
  struct Address address = { 0 };
  struct Numbers numbers = { 0 };
  char c[2] = " ";

  printf("Contact Management System\n");
  printf("-------------------------\n");

  printf("Please enter the contact's first name: ");
  scanf("%30s", name.firstName);

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  scanf("%s", &c);
  if ((strcmp(c, "y") == 0) || (strcmp(c, "Y") == 0)) {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%6s", name.middleInitial);
  }

  printf("Please enter the contact's last name: ");
  scanf("%35s", name.lastName);

  printf("Please enter the contact's street number: ");
  scanf("%d", &address.streetNumber);
  printf("Please enter the contact's street name: ");
  scanf("%40s", address.street);
  printf("Do you want to enter an apartment number? (y or n): ");
  scanf("%s", &c);
  if ((strcmp(c, "y") == 0) || (strcmp(c, "Y") == 0)) {
    printf("Please enter the contact's apartment number: ");
    scanf("%d", &address.apartmentNumber);
  }
  printf("Please enter the contact's postal code: ");
  getPostalCode(address.postalCode);


  printf("Please enter the contact's city: ");
  scanf("%40s", address.city);

  printf("Do you want to enter a cell phone number? (y or n): ");
  scanf("%s", &c);
  if ((strcmp(c, "y") == 0) || (strcmp(c, "Y") == 0)) {
    printf("Please enter the contact's cell phone number: ");
    scanf("%20s", numbers.cell);
  }

  printf("Do you want to enter a home phone number? (y or n): ");
  scanf("%s", &c);
  if ((strcmp(c, "y") == 0) || (strcmp(c, "Y") == 0)) {
    printf("Please enter the contact's home phone number: ");
    scanf("%20s", numbers.home);
  }

  printf("Do you want to enter a business phone number? (y or n): ");
  scanf("%s", &c);
  if ((strcmp(c, "y") == 0) || (strcmp(c, "Y") == 0)) {
    printf("Please enter the contact's business phone number: ");
    scanf("%20s", numbers.business);
  }

  printf("\nContact Details\n");
  printf("---------------\n");
  printf("Name Details\n");

  printf("First name: %s\n", name.firstName);
  printf("Middle initial(s):%s\n", name.middleInitial);
  printf("Last name: %s\n", name.lastName);
  printf("\n");

  printf("Address Details\n");
  printf("Street number: %d\n", address.streetNumber);
  printf("Street name: %s\n", address.street);
  printf("Apartment: %d\n", address.apartmentNumber);
  printf("Postal code: %s\n", address.postalCode);
  printf("City: %s\n", address.city);
  printf("\n");

  printf("Phone Numbers:\n");
  printf("Cell phone number: %s\n", numbers.cell);
  printf("Home phone number: %s\n", numbers.home);
  printf("Business phone number: %s\n", numbers.business);
  printf("\n");
  printf("Structure test for Name, Address, and Numbers Done!\n");

  return 0;
}

