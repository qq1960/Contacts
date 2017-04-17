//Telephone Directory
// *** Needs debugging *** //

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

//using namespace std;

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
    std::cout << "\nEnter Name : ";
    std::cin >> name;
    std::cout << "Enter Phone No. : ";
    std::cin >> phno;
}

void phoneBook :: showdata(){
    std::cout << "\n";
    std::cout << std::setw(20) << name;
    std::cout << std::setw(15) << phno;
}


int main(){
    
    phoneBook rec;
    std::fstream file;
    
    std::cout << "Opening data file" << std::endl;
    
    file.open("phone.dat",
        std::ios::ate | std::ios::in | std::ios::out | std::ios::binary);
    
    if (file)
    {
        std::cout << "File opened" << std::endl;
    } else {
        std::ofstream outfile ("phone.dat");
        std::cout << "Created new file!" << std::endl;
        outfile.close();
        
        file.open("phone.dat",
            std::ios::ate | std::ios::in | std::ios::out | std::ios::binary);
    }
    
    char ch;
    char nm[20];
    char telno[6];
    int choice;
    int found = 0;
    int cnt;
    bool keepOn = true;
    
    while(keepOn){

        //std::cout << "\033[2J" << std::flush; // This is VT100 clear screen and will also work
        
        std::cout << "\n*****Phone Book*****\n";
        std::cout << "1) Add New Record\n";
        std::cout << "2) Display All Records\n";
        std::cout << "3) Search by Person\n";
        std::cout << "4) Search by Phone #\n";
        std::cout << "5) Update Phone #\n";
        std::cout << "6) Exit\n\n";
        std::cout << "Choose your option : ";
        
        std::cin >> choice;
        switch(choice){
            case 1 : //New Record
                 rec.getdata();
                 std::cin.get(ch);
                 file.write((char *) &rec, sizeof(rec));
                 break;

            case 2 : //Display All Records
                 file.seekg(0, std::ios::beg);
                 std::cout << "\n\nRecords in Phone Book\n";
                 while(file){
                    file.read((char *) &rec, sizeof(rec));
                    if(!file.eof())
                        rec.showdata();
                 }
                 file.clear();
                 //getch();
                 std::cin.get(ch);
                 break;

            case 3 : //Search Tel. no. when person name is known.
                 std::cout << "\n\nEnter Name : ";
                 std::cin >> nm;
                 file.seekg(0, std::ios::beg);
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
                    std::cout << "\n\n---Record Not found---\n";
                 //getch();
                 std::cin.get(ch);
                 break;

            case 4 : //Search name on basis of tel. no
                 std::cout << "\n\nEnter Telephone No : ";
                 std::cin >> telno;
                 file.seekg(0, std::ios::beg);
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
                    std::cout<<"\n\n---Record Not found---\n";
                 //getch();
                 std::cin.get(ch);
                 break;

            case 5 : //Update Telephone No.
                 std::cout << "\n\nEnter Name : ";
                 std::cin>>nm;
                 file.seekg(0,std::ios::beg);
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
                    std::cout << "\n\n---Record Not found---\n";
                 else
                 {
                    int location = (cnt-1) * sizeof(rec);
                    std::cin.get(ch);
                    if(file.eof())
                        file.clear();

                    std::cout << "Enter New Telephone No : ";
                    std::cin >> telno;
                    file.seekp(location);
                    rec.update(nm, telno);
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