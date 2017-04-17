//Telephone Directory
// *** Needs debugging *** //

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

class phoneBook{
    char name[20],phno[15];
    public:
    void getdata();
    void showdata();
    char *getname(){ return name; }
    char *getphno(){ return phno; }
    void update(char *nm,char *telno){
        strcpy(name,nm);
        strcpy(phno,telno);
    }
};

void phoneBook :: getdata(){
    cout<<"\nEnter Name : ";
    cin>>name;
    cout<<"Enter Phone No. : ";
    cin>>phno;
}

void phoneBook :: showdata(){
    cout<<"\n";
    cout<<setw(20)<<name;
    cout<<setw(15)<<phno;
}


int main(){
    
    phoneBook rec;
    fstream file;
    
    std::cout << "Opening data file" << std::endl;
    
    file.open("phone.dat", ios::ate | ios::in | ios::out | ios::binary);
    
    std::cout << "File opened" << std::endl;
    
    char ch;
    char nm[20];
    char telno[6];
    int choice;
    int found = 0;
    int cnt;
    bool keepOn = true;
    
    while(keepOn){

        //std::cout << "\033[2J" << std::flush; // This is VT100 clear screen and will also work
        
        cout << "\n*****Phone Book*****\n";
        cout << "1) Add New Record\n";
        cout << "2) Display All Records\n";
        cout << "3) Search Telephone No.\n";
        cout << "4) Search Person Name\n";
        cout << "5) Update Telephone No.\n";
        cout << "6) Exit\n";
        cout << "Choose your option : ";
        
        cin >> choice;
        switch(choice){
            case 1 : //New Record
                 rec.getdata();
                 cin.get(ch);
                 file.write((char *) &rec, sizeof(rec));
                 break;

            case 2 : //Display All Records
                 file.seekg(0,ios::beg);
                 cout<<"\n\nRecords in Phone Book\n";
                 while(file){
                    file.read((char *) &rec, sizeof(rec));
                    if(!file.eof())
                        rec.showdata();
                 }
                 file.clear();
                 //getch();
                 cin.get(ch);
                 break;

            case 3 : //Search Tel. no. when person name is known.
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 //getch();
                 cin.get(ch);
                 break;

            case 4 : //Search name on basis of tel. no
                 cout << "\n\nEnter Telephone No : ";
                 cin >> telno;
                 file.seekg(0,ios::beg);
                 found = 0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(telno,rec.getphno())==0)
                    {
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 //getch();
                 cin.get(ch);
                 break;

            case 5 : //Update Telephone No.
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 cnt = 0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    cnt++;
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        break;
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 else
                 {
                    int location = (cnt-1) * sizeof(rec);
                    cin.get(ch);
                    if(file.eof())
                        file.clear();

                    cout<<"Enter New Telephone No : ";
                    cin>>telno;
                    file.seekp(location);
                    rec.update(nm,telno);
                    file.write((char *) &rec, sizeof(rec));
                    file.flush();
                 }
                 break;
            
            case 6 : // Exit
                std::cout << "Exit - Have a nice day!" << std::endl;
                keepOn = false;
                break;
            
            default :
                 std::cout << "Invalid option - Abort" << std::endl;
                 keepOn = false;
                 break;
            //case 6 : return(0);
        }
    }
    std::cout << "Closing file" << std::endl;
    file.close();
    return(EXIT_SUCCESS);
}