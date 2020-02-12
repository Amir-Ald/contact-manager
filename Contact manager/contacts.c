/* -------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
#include "contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name)
{
	int midP = 0;
	//First Name
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	clearKeyboard();
	// Middle name
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	midP = yes();


	if (midP == 1) // checking if the user entered y as a yes
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
		clearKeyboard();
	}
	// Last name
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
	clearKeyboard();
}
// getAddress:
void getAddress(struct Address *address)
{
	int aptP, z, j = 0;
	// Street number
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	for (z = 0; z < 1; z++)
	{
		if (address->streetNumber < 0)
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
			address->streetNumber = getInt();
			z--;
		}
	}

	// Street name
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();
	// Apartment number
	printf("Do you want to enter an apartment number? (y or n): ");
	aptP = yes();

	if (aptP == 1) // checking if the user entered y as a yes
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		for (j = 0; j < 1; j++)
		{
			if (address->apartmentNumber < 0)
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
				address->apartmentNumber = getInt();
				j--;
			}
		}
	}

	// Postal code
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearKeyboard();
	// City name
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearKeyboard();
}
// getNumbers:
void getNumbers(struct Numbers *numbers)
{

	int hNumP = 0;
	int bNumP = 0;
	//Cell phone number
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	clearKeyboard();
	// Home phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	hNumP = yes();

	if (hNumP == 1) // checking if the user entered y as a yes
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		clearKeyboard();
	}
	//Business number
	printf("Do you want to enter a business phone number? (y or n): ");
	bNumP = yes();
	if (bNumP == 1) // checking if the user entered y as a yes
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business) ;
		clearKeyboard();
	}
}

// getContact:
void getContact(struct Contact *contact)
{
	getName(&contact->name); //getting the contact's name
	getAddress(&contact->address); //getting the contact's address
	getNumbers(&contact->numbers); //getting the contact's numbers
}
