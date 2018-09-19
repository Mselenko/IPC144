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
#include<string.h>
#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------
#define MAXCONTACTS 5

void clearKeyboard(void)
{
	while (getchar() != '\n');
}
void pause(void) {
	printf("(Press Enter to Continue)");
	printf("\n");
	clearKeyboard();
}
int getInt(void) {
	int num;
	char newline = 0;
	do {
		scanf("%d%c", &num, &newline);
		if (newline != '\n') {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	} while (newline != '\n');
	return num;
}

int getIntInRange(int min, int max) {
	int value;
	do {
		value = getInt();
		if (value < min || value > max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (value < min || value > max);
	return value;
}

int yes(void) {
	char ch;
	char newline = 0;
	do {
		scanf(" %c%c", &ch, &newline);
		if (!(ch == 'y' || ch == 'Y' || ch == 'N' || ch == 'n') || newline != '\n') {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			if (newline != '\n')  clearKeyboard();
		}
	} while (!(ch == 'y' || ch == 'Y' || ch == 'N' || ch == 'n') || newline != '\n');
	if (newline != '\n') clearKeyboard();
	return ch == 'y' || ch == 'Y';
}

int menu(void) {
	int selection;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");
	selection = getIntInRange(0, 6);
	printf("\n");
	return selection;
}

void ContactManagerSystem(void) {
	struct Contact contact[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" }},
		{ { "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
		{ { "Morgan", "A.", "Jones" },
		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" } },
		{ { "Sasha",{ '\0' }, "Williams" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" } },
	};
	int selection = 1;
	while (selection != -1) {
		selection = menu();
		switch (selection) {
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			printf("<<< Feature to sort is unavailable >>>");
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes()) {
				selection = -1;
			}
			printf("\n");
			break;
		}
	}
	printf("Contact Management System: terminated\n");
}

void getTenDigitPhone(char *telNum)
{
	do {
		scanf("%10s", telNum);
		if (strlen(telNum) != 10)
			printf("Enter a 10-digit phone number: ");
	} while (strlen(telNum) != 10);
}

int findContactIndex(const struct Contact *contacts, int size, const char *cellNum)
{
	int i;
	int f = -1;
	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			f=i;
			break;
		}
	}
	return f;
}

void displayContactHeader(void) {
	int i;
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|");
	for (i = 0; i < 30; i++)
		printf(" ");
	printf("Contacts Listing");
	for (i = 0; i < 31; i++)
		printf(" ");
	printf("|\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

void displayContactFooter(int ncont) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: ");
	printf("%d\n\n", ncont);
}

void displayContact(const struct Contact* cont) {
	printf(" %s", cont->name.firstName);
	if (strlen(cont->name.middleInitial) != 0)
		printf(" %s ", cont->name.middleInitial);
	 else
		printf(" ");
	printf("%s\n", cont->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", cont->numbers.cell, cont->numbers.home, cont->numbers.business);
	printf("       %d %s, ", cont->address.streetNumber, cont->address.street);
	if (cont->address.apartmentNumber > 0)
		printf("Apt# %d, ",cont->address.apartmentNumber);
	    printf("%s, %s\n", cont->address.city, cont->address.postalCode);
}

void displayContacts(const struct Contact* cont, int size) {
	int ncont = 0;
	int i;
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (strlen(cont[i].numbers.cell) > 0) {
			displayContact(&cont[i]);
			ncont++;
		}
	}
	displayContactFooter(ncont);
}


void searchContacts(const struct Contact* cont, int size) {
	char phoneNum[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	printf("\n");
	int find = findContactIndex(cont, size, phoneNum);
	if (find != -1) {
		displayContact(&cont[find]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}


void addContact(struct Contact* cont, int size) {
	int x = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (strlen(cont[i].numbers.cell) == 0) {
			getContact(&cont[i]);
			printf("--- New contact added! ---\n");
			x++;
			break;
		}
	}
	if(x==0)
	printf("*** ERROR: The contact list is full! ***\n");
}

void updateContact(struct Contact* cont, int size) {
	char phone[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone);
	int find = findContactIndex(cont, size, phone);
	if (find == -1) {
		printf("*** Contact NOT FOUND ***\n");
		pause();
		printf("\n");
	}
	else {
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&cont[find]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1)
			getName(&cont[find].name);
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
			getAddress(&cont[find].address);
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			*cont[find].numbers.cell = '\0';
			*cont[find].numbers.business = '\0';
			*cont[find].numbers.home = '\0';
			getNumbers(&cont[find].numbers);
		}
		printf("--- Contact Updated! ---\n");
		pause();
	 }
}

void deleteContact(struct Contact* cont, int size) {
	char phone[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone);
	printf("\n");
	int find = findContactIndex(cont, size, phone);
	if (find == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("Contact found:");
		printf("\n");
		displayContact(&cont[find]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1) {
			*cont[find].numbers.cell = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

void sortContacts(struct Contact* cont, int size) {
	printf("<<< Feature to sort is unavailable >>>\n");
}

