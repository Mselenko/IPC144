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
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

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
  char cell[21];
  char home[21];
  char business[21];
};

struct Contacts
{
  struct Name name;
  struct Address address;
  struct Numbers numbers;
};

void getName(struct Name *n);
void getAddress(struct Address *a);
void getNumbers(struct Numbers *num);