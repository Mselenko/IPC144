/* ------------------------------------------------------------------
Name: Margarita Selenko
Student number: 147393169
Email: mselenko@myseneca.ca
Section: IPC144SXX
Date: 12/23/17
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/

#include "contacts.h"
void clearKeyboard(void);
void pause(void);
int getInt(void);
int getIntInRange(int min, int max);
int yes(void);
int menu(void);
void ContactManagerSystem(void);
void getTenDigitPhone(char *telNum);
int findContactIndex(const struct Contact[], int, const char[]);
void displayContactHeader(void);
void displayContactFooter(int ncont);
void displayContact(const struct Contact* cont);
void displayContacts(const struct Contact* cont, int size);
void searchContacts(const struct Contact* cont, int size);
void addContact(struct Contact* cont, int size);
void updateContact(struct Contact* cont, int size);
void deleteContact(struct Contact* cont, int size);
void sortContacts(struct Contact* cont, int size);
