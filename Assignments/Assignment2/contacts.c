/* -------------------------------------------
Name: Margarita Selenko
Student number: 147393169
Email: mselenko@myseneca.ca
Section: IPC144SXX
Date: 12/23/17
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name *n)
{
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", n->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6s", n->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", n->lastName);
}

void getAddress(struct Address *a)
{
	printf("Please enter the contact's street number: ");
	a->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", a->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's apartment number: ");
		a->apartmentNumber = getInt();
	}
	 else {
		a->apartmentNumber = 0;
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", a->postalCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", a->city);
	clearKeyboard();
}

void getNumbers(struct Numbers *num)
{
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(num->cell);
	clearKeyboard();
	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(num->home);
		clearKeyboard();
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(num->business);
		clearKeyboard();
	}
}

void getContact(struct Contact * contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
