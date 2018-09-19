// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

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

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

struct Address
{
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers
{
	char cell[11];
	char home[11];
	char business[11];
};

struct Contact
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

void getName(struct Name *n);
void getAddress(struct Address *a);
void getNumbers(struct Numbers *num);
void getContact(struct Contact *contact);

// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
