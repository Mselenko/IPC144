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

  int main(void)
  {

    struct Contacts contacts = { {{0}} };
    contacts.address.streetNumber = 0;
    contacts.address.street[41] = '\0';
    contacts.address.apartmentNumber = 0;
    contacts.address.postalCode[8] = '\0';
    contacts.address.city[41] = '\0';

    printf("Contact Management System\n");
    printf("-------------------------\n");

    getName(&contacts.name);
    getAddress(&contacts.address);
    getNumbers(&contacts.numbers);

    printf("\nContact Details\n");
    printf("---------------\n");
    printf("Name Details\n");

    printf("First name: %s\n", contacts.name.firstName);
    printf("Middle initial(s):%s\n", contacts.name.middleInitial);
    printf("Last name: %s\n", contacts.name.lastName);
    printf("\n");

    printf("Address Details\n");
    printf("Street number: %d\n", contacts.address.streetNumber);
    printf("Street name: %s\n", contacts.address.street);
    printf("Apartment: %d\n", contacts.address.apartmentNumber);
    printf("Postal code: %s\n", contacts.address.postalCode);
    printf("City: %s\n", contacts.address.city);
    printf("\n");

    printf("Phone Numbers:\n");
    printf("Cell phone number: %s\n", contacts.numbers.cell);
    printf("Home phone number: %s\n", contacts.numbers.home);
    printf("Business phone number: %s\n", contacts.numbers.business);
    printf("\n");
    printf("Structure test for Contact using functions done!\n");
    
    return 0;
}

