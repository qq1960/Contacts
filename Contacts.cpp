<<<<<<< HEAD
// Assignment
//
//
// Author: Neil Burman
// Date: 11/03/2008 (UK)
// Revived: 2017-04-15
// Filename: Contacts.cpp
//

///////////////////////////////////////////

// Standard includes

#include <iostream>
#include <string>
#include <cstring>

// Import other includes
// This is windows only!
//#include <conio>

//using namespace std;

// CLASS : CAddress
class CAddress
{
    public:
        // Constructor
        CAddress(char* streetaddress, char* areaname, char* town, char* postcode, char* country);
    
        // Destructor    
        ~CAddress();
    
        // Copy constructor    
        CAddress(const CAddress& address);
        
        // Overloaded operators
        CAddress& operator = (const CAddress& address);
    
        // Member functions:
        char* GetStreetAddress(void);
        char* GetAreaName(void);
        char* GetTown(void);
        char* GetPostcode(void);
        char* GetCountry(void);
        void SetStreetAddress(char* streetaddress);
    
        void SetAreaName(char* areaname);
        void SetTown(char* town);
        void SetPostcode(char* postcode);
        void SetCountry(char* country);
    
    private:

    // hidden default constructor:    
    CAddress()
    {
    }
    
    // Properties:
    char* cpStreetAddress;      // Street Address
    char* cpAreaName;           // Area Name
    char* cpTown;               // Town
    char* cpPostcode;           // Postcode
    char* cpCountry;            // Country
};

// Class Constructor
CAddress::CAddress(char* streetaddress, char* areaname, char* town, char* postcode, char* country)
{

// Initialise the pointers
cpStreetAddress = NULL;
cpAreaName = NULL;
cpTown = NULL;
cpPostcode = NULL;
cpCountry = NULL;

// Use member functions
SetStreetAddress(streetaddress);
SetAreaName(areaname);
SetTown(town);
SetPostcode(postcode);
SetCountry(country);
}

// Class Destructor
CAddress::~CAddress()
{
    // Delete the items
    delete [] cpStreetAddress;
    delete [] cpAreaName;
    delete [] cpTown;
    delete [] cpPostcode;
    delete [] cpCountry;
}





// Member functions follow;

// "Get" functions

// Get Street Address

char* CAddress::GetStreetAddress(void)

{

// Declare a new string

char* streetaddress = new char[strlen(cpStreetAddress) + 1];



// Assign data to the pointer:

strcpy(streetaddress, cpStreetAddress);



// Return the pointer to the new string:

return streetaddress;

}



// Get Area Name

char* CAddress::GetAreaName(void)

{

// Declare a new string

char* areaname = new char[strlen(cpAreaName) + 1];



// Assign data to the pointer:

strcpy(areaname, cpAreaName);



// Return the pointer to the new string:

return areaname;

}



// Get Town

char* CAddress::GetTown(void)

{

// Declare a new string

char* town = new char[strlen(cpTown) + 1];



// Assign data to the pointer:

strcpy(town, cpTown);



// Return the pointer to the new string:

return town;

}



// Get Postcode

char* CAddress::GetPostcode(void)

{

// Declare a new string

char* postcode = new char[strlen(cpPostcode) + 1];



// Assign data to the pointer:

strcpy(postcode, cpPostcode);



// Return the pointer to the new string:

return postcode;

}



// Get Country

char* CAddress::GetCountry(void)

{

// Declare a new string

char* country = new char[strlen(cpCountry) + 1];



// Assign data to the pointer:

strcpy(country, cpCountry);



// Return the pointer to the new string:

return country;

}



// "Set" functions

// Set Street Address

void CAddress::SetStreetAddress(char* streetaddress)

{

// Check the need to delete

if (cpStreetAddress)

{

delete [] cpStreetAddress;

}



// Resize for the new data

cpStreetAddress = new char[strlen(streetaddress) + 1];

// Assign the data

strcpy(cpStreetAddress, streetaddress);

}



// Set Area Name

void CAddress::SetAreaName(char* areaname)

{

// Check the need to delete

if (cpAreaName)

{

delete [] cpAreaName;

}



// Resize for the new data

cpAreaName = new char[strlen(areaname) + 1];

// Assign the data

strcpy(cpAreaName, areaname);

}



// Set Town;

void CAddress::SetTown(char* town)

{

// Check the need to delete

if (cpTown)

{

delete [] cpTown;

}



// Resize for the new data

cpTown = new char[strlen(town) + 1];

// Assign the data

strcpy(cpTown, town);

}



// Set Postcode;

void CAddress::SetPostcode(char* postcode)

{

// Check the need to delete

if (cpPostcode)

{

delete [] cpPostcode;

}



// Resize for the new data

cpPostcode = new char[strlen(postcode) + 1];

// Assign the data

strcpy(cpPostcode, postcode);

}



// Set Country

void CAddress::SetCountry(char* country)

{

// Check the need to delete

if (cpCountry)

{

delete [] cpCountry;

}



// Resize for the new data

cpCountry = new char[strlen(country) + 1];

// Assign the data

strcpy(cpCountry, country);

}







////////////////////////////////////////////////////////////////////





class CDate

{

public:

unsigned short Day;

unsigned short Month;

unsigned short Year;



CDate()

{

Day = 0;

Month = 0;

Year = 0;

}



~CDate()

{

}

};



class CEventDate

{

public:

char Description[255];

/*

CEventDate()

{

Day = 0;

Month = 0;

Year = 0;

}

*/

~CEventDate()

{

}

};







class CName

{

public:

char Title[5];

char FirstName[30];

char MiddleNames[30][4];

char LastName[30];



/* CName()

{

Height = 0.0;

Width = 0.0;

Depth = 0.0;

}



// If only 3 items entered, assume no middle name

CName(char t, double w, double d)

{

Height = h;

Width = w;

Depth = d;

}



*/

~CName()

{

}

};



class CNameListItem

{

public:

CName* ThisItem;

CNameListItem* PreviousItem;

CNameListItem* NextItem;



CNameListItem(CName* b, CNameListItem* p, CNameListItem* n)

{

PreviousItem = p;

NextItem = n;



ThisItem = b;

}



~CNameListItem()

{

CNameListItem* p = this->PreviousItem;

CNameListItem* n = this->NextItem;



if (p != NULL)

{

if ( n == NULL)

{

p->NextItem = NULL;

}

else

{

p->NextItem = n;

}

}



delete ThisItem;

}



private:

CNameListItem()

{

}

};





class CNameList

{

public:

CNameListItem* FirstItem;



CNameList(CName* b)

{

FirstItem = new CNameListItem(b, NULL, NULL);

}



~CNameList()

{

while (FirstItem->NextItem != NULL)

{

RemoveLast();

}



delete FirstItem;

}



CNameListItem* AddFirst(CName* b)

{

CNameListItem* n = new CNameListItem(b, NULL, FirstItem);



FirstItem->PreviousItem = n;

FirstItem = n;

return n;

}



CNameListItem* AddLast(CName* b)

{

CNameListItem* last;



last = this->FirstItem;



while (last->NextItem != NULL)

{

last = last->NextItem;

}



CNameListItem* n = new CNameListItem(b, last, NULL);



last->NextItem = n;



return n;

}



void RemoveFirst(void)

{

CNameListItem* b;

b = FirstItem->NextItem;

delete FirstItem;

FirstItem = b;

FirstItem->PreviousItem = NULL;

}



void RemoveLast(void)

{

CNameListItem* b;

b = this->FirstItem;



while (b->NextItem != NULL)

{

b = b->NextItem;

}



b->PreviousItem->NextItem = NULL;



delete b;

}



int CountItems(void)

{

int i = 1;



CNameListItem* b = this->FirstItem;



while (b->NextItem != NULL)

{

b = b->NextItem;

i++;

}



return i;

}



CNameListItem* GetItem(int i)

{

int iCounter = 1;



if (i > 0 && i <= CountItems())

{

CNameListItem* b = this->FirstItem;

while (iCounter < i)

{

b = b->NextItem;

iCounter++;

}

return b;

}

return NULL;

}



private:

CNameList()

{

}

};



class COrganisation

{

public:

char CompanyName[50];



~COrganisation()

{

}

};



int main(void)
{
    std::cout << " Contact Management" << std::endl;
    std::cout << " ==================" << std::endl;
    std::cout << "" << std::endl;
    
    std::cout << "Please hit the ESC key when done" << std::endl << std::endl;
    
    return(0);
}
=======
// Assignment 
//
//
// Author: Neil Burman
// Date: 11/03/2008 (UK)
// Filename: Contacts.cpp
//
///////////////////////////////////////////
// Standard includes
#include <iostream>
#include <string>

// Import other includes
#include <conio.h>

using namespace std;


// CLASS : CAddress
class CAddress
{
public:
// Constructor
CAddress(char* streetaddress, char* areaname, char* town, char* postcode, char* country);

// Destructor
~CAddress();

// Copy constructor
CAddress(const CAddress& address);

// Overloaded operators
CAddress& operator = (const CAddress& address);

// Member functions:
char* GetStreetAddress(void);
char* GetAreaName(void);
char* GetTown(void);
char* GetPostcode(void);
char* GetCountry(void);

void SetStreetAddress(char* streetaddress);
void SetAreaName(char* areaname);
void SetTown(char* town);
void SetPostcode(char* postcode);
void SetCountry(char* country);

private:
// hidden default constructor:
CAddress()
{
}

// Properties:
char* cpStreetAddress; // Street Address
char* cpAreaName; // Area Name
char* cpTown; // Town
char* cpPostcode; // Postcode
char* cpCountry; // Country

};

// Class Constructor
CAddress::CAddress(char* streetaddress, char* areaname, char* town, char* postcode, char* country)
{
// Initialise the pointers
cpStreetAddress = NULL;
cpAreaName = NULL;
cpTown = NULL;
cpPostcode = NULL;
cpCountry = NULL;

// Use member functions
SetStreetAddress(streetaddress);
SetAreaName(areaname);
SetTown(town);
SetPostcode(postcode);
SetCountry(country);

}

// Class Destructor
CAddress::~CAddress()
{
// Delete the items
	delete [] cpStreetAddress;
	delete [] cpAreaName;
	delete [] cpTown;
	delete [] cpPostcode;
	delete [] cpCountry;
}


// Member functions follow;
// "Get" functions
// Get Street Address
char* CAddress::GetStreetAddress(void)
{
	// Declare a new string
	char* streetaddress = new char[strlen(cpStreetAddress) + 1];

	// Assign data to the pointer:
	strcpy(streetaddress, cpStreetAddress);

	// Return the pointer to the new string:
	return streetaddress;
}

// Get Area Name
char* CAddress::GetAreaName(void)
{
	// Declare a new string
	char* areaname = new char[strlen(cpAreaName) + 1];

	// Assign data to the pointer:
	strcpy(areaname, cpAreaName);

	// Return the pointer to the new string:
	return areaname;
}

// Get Town
char* CAddress::GetTown(void)
{
	// Declare a new string
	char* town = new char[strlen(cpTown) + 1];

	// Assign data to the pointer:
	strcpy(town, cpTown);

	// Return the pointer to the new string:
	return town;
}

// Get Postcode
char* CAddress::GetPostcode(void)
{
	// Declare a new string
	char* postcode = new char[strlen(cpPostcode) + 1];

	// Assign data to the pointer:
	strcpy(postcode, cpPostcode);

	// Return the pointer to the new string:
	return postcode;
}

// Get Country
char* CAddress::GetCountry(void)
{
	// Declare a new string
	char* country = new char[strlen(cpCountry) + 1];

	// Assign data to the pointer:
	strcpy(country, cpCountry);

	// Return the pointer to the new string:
	return country;
}

// "Set" functions
// Set Street Address
void CAddress::SetStreetAddress(char* streetaddress)
{
// Check the need to delete
if (cpStreetAddress)
	{
		delete [] cpStreetAddress;
	}

// Resize for the new data
cpStreetAddress = new char[strlen(streetaddress) + 1];
// Assign the data
strcpy(cpStreetAddress, streetaddress);
}

// Set Area Name
void CAddress::SetAreaName(char* areaname)
{
// Check the need to delete
if (cpAreaName)
{
delete [] cpAreaName;
}

// Resize for the new data
cpAreaName = new char[strlen(areaname) + 1];
// Assign the data
strcpy(cpAreaName, areaname);
}

// Set Town;
void CAddress::SetTown(char* town)
{
// Check the need to delete
if (cpTown)
{
delete [] cpTown;
}

// Resize for the new data
cpTown = new char[strlen(town) + 1];
// Assign the data
strcpy(cpTown, town);
}

// Set Postcode;
void CAddress::SetPostcode(char* postcode)
{
// Check the need to delete
if (cpPostcode)
{
delete [] cpPostcode;
}

// Resize for the new data
cpPostcode = new char[strlen(postcode) + 1];
// Assign the data
strcpy(cpPostcode, postcode);
}

// Set Country
void CAddress::SetCountry(char* country)
{
// Check the need to delete
if (cpCountry)
{
delete [] cpCountry;
}

// Resize for the new data
cpCountry = new char[strlen(country) + 1];
// Assign the data
strcpy(cpCountry, country);
}



////////////////////////////////////////////////////////////////////
// (The following will need to be replaced)
////////////////////////////////////////////////////////////////////

class CDate
{
public:
unsigned short Day;
unsigned short Month;
unsigned short Year;

CDate()
{
Day = 0;
Month = 0;
Year = 0;
}

~CDate()
{
}
};

class CEventDate
{
public:
char Description[255];
/*
CEventDate()
{
Day = 0;
Month = 0;
Year = 0;
}
*/
~CEventDate()
{
}
};



class CName
{
public:
char Title[5];
char FirstName[30];
char MiddleNames[30][4];
char LastName[30];

/* CName()
{
Height = 0.0;
Width = 0.0;
Depth = 0.0;
}

// If only 3 items entered, assume no middle name
CName(char t, double w, double d)
{
Height = h;
Width = w;
Depth = d;
}

*/
~CName()
{
}
};

class COrganisation
{
public:
char CompanyName[50];

~COrganisation()
{
}
};
////////////////////////////////////////////////////////////////////
// (End of replacement section)
////////////////////////////////////////////////////////////////////


// Linked list classes follow
class CNameListItem
{
public:
CName* ThisItem;
CNameListItem* PreviousItem;
CNameListItem* NextItem;

CNameListItem(CName* b, CNameListItem* p, CNameListItem* n)
{
PreviousItem = p;
NextItem = n;

ThisItem = b;
}

~CNameListItem()
{
CNameListItem* p = this->PreviousItem;
CNameListItem* n = this->NextItem;

if (p != NULL)
{
if ( n == NULL)
{
p->NextItem = NULL;
}
else
{
p->NextItem = n;
}
}

delete ThisItem;
}

private:
CNameListItem()
{
}
};


class CNameList
{
public:
CNameListItem* FirstItem;

CNameList(CName* b)
{
FirstItem = new CNameListItem(b, NULL, NULL);
}

~CNameList()
{
while (FirstItem->NextItem != NULL)
{
RemoveLast();
}

delete FirstItem;
}

CNameListItem* AddFirst(CName* b)
{
CNameListItem* n = new CNameListItem(b, NULL, FirstItem);

FirstItem->PreviousItem = n;
FirstItem = n;
return n;
}

CNameListItem* AddLast(CName* b)
{
CNameListItem* last;

last = this->FirstItem;

while (last->NextItem != NULL)
{
last = last->NextItem;
}

CNameListItem* n = new CNameListItem(b, last, NULL);

last->NextItem = n;

return n;
}

void RemoveFirst(void)
{
CNameListItem* b;
b = FirstItem->NextItem;
delete FirstItem;
FirstItem = b;
FirstItem->PreviousItem = NULL;
}

void RemoveLast(void)
{
CNameListItem* b;
b = this->FirstItem;

while (b->NextItem != NULL)
{
b = b->NextItem;
}

b->PreviousItem->NextItem = NULL;

delete b;
}

int CountItems(void)
{
int i = 1;

CNameListItem* b = this->FirstItem;

while (b->NextItem != NULL)
{
b = b->NextItem;
i++;
}

return i;
}

CNameListItem* GetItem(int i)
{
int iCounter = 1;

if (i > 0 && i <= CountItems())
{
CNameListItem* b = this->FirstItem;
while (iCounter < i)
{
b = b->NextItem;
iCounter++;
}
return b;
}
return NULL;
}

private:
CNameList()
{
}
};
// End of linked list handling classes

///////////////////////////////////////////
// File handling classes to go in here
// File to be text, comma delimited, 
// one contact per line.
// (Don't forget to escape commas when saving
// and un-escape when printing/processing.
///////////////////////////////////////////

// Handle user exceptions
class UserException
{
public:
UserException();
UserException(const char errormessage[]);
};

// Generic exception handling
UserException::UserException()
{
cout << "An exception has occurred. Please contact the helpdesk."
<< endl;
}

UserException::UserException(const char errormessage[])
{
cout << "That is not a valid choice." << endl
	<< endl << "\t***" << errormessage << "***" << endl << endl;

cout << "Please re-run the application again" << endl << endl;
}

// Application class
class CApplication
{
private:

int GetUserChoice(void)
{
int iSelect; // User selection

cout << " Contact Management" << endl;
cout << " ==================" << endl;
cout << endl << endl;
cout << " 1. Read contacts file" << endl << endl;
cout << " 2. Display an existing contact" << endl << endl;
cout << " 3. Add a new contact" << endl << endl;
cout << " 4. Modify an existing contact" << endl << endl;
cout << " 5. Delete an existing contact" << endl << endl;
cout << " 6. Save contacts to file" << endl << endl;
////////////////////////////////
// The following for future use.
// cout << " ?. Export contacts to a human-readable file" << endl << endl;
////////////////////////////////
cout << endl << endl;
cout << " 7. Exit program" << endl << endl;
cout << endl << endl;
cout << " Please make your selection : ";
cin >> iSelect;
cout << endl;

return iSelect;
}

void UserExit(void)
{
// Check here if user has made changes and has not saved data to a file,
// ask if they want to do so.

cout << "Goodbye and have a nice day!" << endl;
}

public:
CApplication()
{
}

~CApplication()
{
}

void Run(void)
{
int iUserChoice;

iUserChoice = GetUserChoice();

// Debugging
cout << "The user chose : " << static_cast<int>(iUserChoice) << endl;

try
	{
	if (iUserChoice > 7)
	throw UserException("Value too high");

	if (iUserChoice < 1)
	throw UserException("Value too low");

	}
		catch (UserException& cErrorMessage)
		{
		// Nothing goes in here(?)
		}
	}
};

// Main program starts here
void main(void)
{
	CApplication* app = new CApplication();

	app->Run();

	delete app;
}
>>>>>>> 0071a5e865c42753a136462ae9a5fb03846245ed
