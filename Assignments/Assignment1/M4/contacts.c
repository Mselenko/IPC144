/* -------------------------------------------
Name: Margarita Selenko
Student number: 147393169
Email: mselenko@myseneca.ca
Section:IPC144SXX
Date: 11/1/17
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

void getName(struct Name *n)
{
  char c='\0';
  
  printf("Please enter the contact's first name: ");
  scanf("%30s", n->firstName);

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%6s", n->middleInitial);
  }

  printf("Please enter the contact's last name: ");
  scanf("%35s", n->lastName);
}

void getAddress(struct Address *a)
{
  char c = '\0';
  printf("Please enter the contact's street number: ");
  scanf("%d", &a->streetNumber);
  printf("Please enter the contact's street name: ");
  scanf("%40s", a->street);
  printf("Do you want to enter an apartment number? (y or n): ");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("Please enter the contact's apartment number: ");
    scanf("%d", &a->apartmentNumber);
  }
  printf("Please enter the contact's postal code: ");
  scanf(" %7[^\n]s", a->postalCode);
  printf("Please enter the contact's city: ");
  scanf("%40s", a->city);
}

void getNumbers(struct Numbers *num)
{
  char c = '\0';
  printf("Do you want to enter a cell phone number? (y or n): ");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("Please enter the contact's cell phone number: ");
    scanf("%20s", num->cell);
  }

  printf("Do you want to enter a home phone number? (y or n): ");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("Please enter the contact's home phone number: ");
    scanf("%20s", num->home);
  }

  printf("Do you want to enter a business phone number? (y or n): ");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("Please enter the contact's business phone number: ");
    scanf("%20s", num->business);
  }
}