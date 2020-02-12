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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();

}

// getInt:
int getInt(void)
{
	int num, i = 0;
	char lastChar;

	scanf("%d%c", &num, &lastChar);

	for (i = 0; i < 1; i++) // a loop for checking the input
	{
		if (lastChar != '\n') // checks if is there something other than an integer
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &num, &lastChar);
			i--;
		}
	}

	return num;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int rangeNum, x = 0;
	rangeNum = getInt(); // getting an integer using getInt function

	for (x = 0; x < 1; x++)
	{
		if (rangeNum < min || rangeNum > max) // checking if the integer is in range
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
			rangeNum = getInt();
			x--;
		}
	}

	return rangeNum;
}

// yes:
int yes(void)
{
	int y, rtrnValue = 0;
	char prmpt, check;
	scanf("%c%c", &prmpt, &check);

	for (y = 0; y < 1; y++)
	{
		if (check != '\n') // checking if there is more than one character
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			scanf("%c%c", &prmpt, &check);
			y--;
		}
		else
		{
			if (prmpt == 'y' || prmpt == 'Y')
			{
				rtrnValue = 1;

			}
			else if (prmpt == 'n' || prmpt == 'N')
			{
				rtrnValue = 0;

			}
			else
			{
				clearKeyboard();
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
				scanf("%c%c", &prmpt, &check);
				y--;

			}

		}
	}

	return rtrnValue;
}

// menu:
int menu(void)
{
	const int menuMin = 0;
	const int menuMax = 6;
	int secNum = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	secNum = getIntInRange(menuMin, menuMax); // getting the section number using the getIntInRange

	return secNum;
}


// contactManagerSystem:
void contactManagerSystem(void)
{
	int choice, exit = 0;
	struct Contact contacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
{ "4161112222", "4162223333", "4163334444" } },
{
{ "Maggie", "R.", "Greene" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9051112222", "9052223333", "9053334444" } },
{
{ "Morgan", "A.", "Jones" },
{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
{ "7051112222", "7052223333", "7053334444" } },
{
{ "Sasha", {'\0'}, "Williams" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9052223333", "9052223333", "9054445555" } },
	};

	do
	{
		
		
		choice = menu();

		switch (choice) // checking the entered number
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			exit = yes();
			printf("\n");
			break;

		}

	} while (exit == 0);
	printf("Contact Management System: terminated\n");

}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int isDigit = 0;
	unsigned int i = 0;
	while (needInput == 1) {
		scanf("%10s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		while (i < strlen(phoneNum) && isDigit == 0) {
			if (phoneNum[i] <= '0' && phoneNum[i] >= '9')
				isDigit = 0;
			else
				isDigit = 1;
			i++;
		}
		
		if (strlen(phoneNum) == 10 && isDigit==1)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, rtrn = 0;
	
	for ( i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			rtrn = i;
			i = size;
		}
		else {
			rtrn= -1 ;
		}
			
	}

	return rtrn;
}


// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact *contact)
{
	//Name
	printf(" %s", contact->name.firstName);
	if (*contact->name.middleInitial != 0)
	{
		printf(" %s", contact->name.middleInitial);
	}
	printf(" %s\n", contact->name.lastName);
	//Number
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	//Address
	printf("       %d %s,", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber != 0)
	{
		printf("Apt# %d,", contact->address.apartmentNumber);
	}
	printf(" %s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i, vCount = 0;
	displayContactHeader();
	
	for ( i = 0; i < size; i++)
	{
		if (*contacts[i].numbers.cell != '\0')
		{
			displayContact(&contacts[i]);
			vCount++;
		}

	}

	displayContactFooter(vCount);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char cellN[11] = {0};
	int searchRslt = 0;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellN);
	searchRslt =findContactIndex(contacts, size, cellN);
	
	if (searchRslt = -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		displayContact(&contacts[searchRslt]);
		printf("\n");
	}
	
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int emptyIndex = 0;
	emptyIndex = findContactIndex(contacts, size, "\0");

	if (emptyIndex == -1)
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
	else
	{
		printf("\n");
		getContact(&contacts[emptyIndex]);
		printf("--- New contact added! ---\n");
	}

}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char cellN[11] = {'\0'};
	int indxNum, fPrmpt, sPrmpt, tPrmpt = 0;
	getTenDigitPhone(cellN);
	indxNum = findContactIndex(contacts, size, cellN);

	if (indxNum == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[indxNum]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		fPrmpt = yes();
		if (fPrmpt == 1)
		{
			getName(&contacts[indxNum].name);
		}

		printf("Do you want to update the address? (y or n): ");
		sPrmpt = yes();
		if (sPrmpt == 1)
		{
			getAddress(&contacts[indxNum].address);
		}
		
		printf("Do you want to update the numbers? (y or n): ");
		tPrmpt = yes();
		if (tPrmpt == 1)
		{
			getNumbers(&contacts[indxNum].numbers);
		}

		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char cNum;
	int cIndx, prmpt = 0;
	getTenDigitPhone(&cNum);
	cIndx = findContactIndex(contacts, size, &cNum);
	if (cIndx == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("Contact found:\n");
		displayContact(&contacts[cIndx]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		prmpt = yes();
		if (prmpt == 1)
		{
			*contacts[cIndx].numbers.cell = '0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j, m, tempIntgr = 0;
	char tempStrng;
	for (i = 0; i < size; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(contacts[j].numbers.cell, contacts[i].numbers.cell) < 0)
			{
				m = j;
			}
			
		}
		if (m != i)
		{
			//Switching First Name
			tempStrng = *contacts[i].name.firstName;
			*contacts[i].name.firstName = *contacts[m].name.firstName;
			*contacts[m].name.firstName = tempStrng;
			
			//Switching Last Name
			tempStrng = *contacts[i].name.lastName;
			*contacts[i].name.lastName = *contacts[m].name.lastName;
			*contacts[m].name.lastName = tempStrng;
			
			//Switching Middle name
			tempStrng = *contacts[i].name.middleInitial;
			*contacts[i].name.middleInitial = *contacts[m].name.middleInitial;
			*contacts[m].name.middleInitial = tempStrng;
			
			//Switching Cell number
			tempStrng = *contacts[i].numbers.cell;
			*contacts[i].numbers.cell = *contacts[m].numbers.cell;
			*contacts[m].numbers.cell = tempStrng;
			
			//Switching Home number
			tempStrng = *contacts[i].numbers.home;
			*contacts[i].numbers.home = *contacts[m].numbers.home;
			*contacts[m].numbers.home = tempStrng;

			//Switching Business number
			tempStrng = *contacts[i].numbers.business;
			*contacts[i].numbers.business = *contacts[m].numbers.business;
			*contacts[m].numbers.business = tempStrng;
			
			//Switching Street
			tempStrng = *contacts[i].address.street;
			*contacts[i].address.street = *contacts[m].address.street;
			*contacts[m].address.street = tempStrng;

			//Switching Postal code
			tempStrng = *contacts[i].address.postalCode;
			*contacts[i].address.postalCode = *contacts[m].address.postalCode;
			*contacts[m].address.postalCode = tempStrng;
			
			//Switching City
			tempStrng = *contacts[i].address.city;
			*contacts[i].address.city = *contacts[m].address.city;
			*contacts[m].address.city = tempStrng;
			
			//Switching Apartment Number
			tempIntgr = contacts[i].address.apartmentNumber;
			contacts[i].address.apartmentNumber = contacts[m].address.apartmentNumber;
			contacts[m].address.apartmentNumber = tempIntgr;
			
			//Switching Street number
			tempStrng = contacts[i].address.streetNumber;
			contacts[i].address.streetNumber = contacts[m].address.streetNumber;
			contacts[m].address.streetNumber = tempIntgr;
		}
	}


	printf("--- Contacts sorted! ---\n");
}