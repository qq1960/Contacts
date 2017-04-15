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
