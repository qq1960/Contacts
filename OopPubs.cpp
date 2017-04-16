// Object Oriented Publications

#include<iostream.h>
#include<stdio.h>

class publication                                           //  abstract class
{
     protected:
          
     // static const     char name[29]="H & M publication";  char title[50];
         float price;
    
     public:
          
         publication()
         {
             price=0;
         }
      
         virtual ~ publication()                            //  VIRTUAL DESTRUCTOR
            { }
      
         virtualvoid getdata()                               //   VIRTUAL FUNCTION
         {
             cout<<"enter title"<<endl;
            gets(title);                                      //   ENTER NAME  
             cout<<"enter price"<<endl;
             cin>>price;
         }
     
         virtualvoid putdata() 
         {
            // cout<<name<<endl; 
             cout<<"title : "<<title<<endl<<" price : "<<price<<endl;
         }
};

class book:public publication                                      //'book' inherited from 'publication'
{
     protected:
        
         long pagecount;
    
     public:
        
         book()
         {
             pagecount=0;
         }
        
         ~book()
         { }
        
         void getdata()                                         //  FUNCTION OVERRIDING
         {
             publication::getdata();
             cout<<"enter total pages"<<endl;
             cin>>pagecount;
         }
         
         void putdata()                                            //  FUNCTION OVERRIDING
         {
             publication::putdata(); 
             cout<<"Total pages : "<<pagecount<<endl;
         }
};

class casete:public publication
{
    protected:
        
        int mins;

    public:
    
        casete()
        {
            mins=0;
        }
    
        ~casete()
        {    }
    
        void getdata()                                               //   FUNCTION OVERRIDING
        {
            publication::getdata();
            cout<<"enter time in mins"<<endl;
            cin>>mins;
        }
        
        void putdata()                                                  //   FUNCTION OVERRIDING
        {
            publication::putdata(); 
            cout<<"time : "<<mins<<" mins"<<endl;
        }
    
        friend  int secs(casete cs);                                   //   FRIEND FUNCTION
};
class disk:public publication
{
      protected:
         
          char format[4];
     
      public:
        
          ~    disk()
          { }
        
          disk()
          {  }
        
          void getdata()                                            //   FUNCTION OVERRIDING
        {
            publication::getdata();
            cout<<"enter disk type"<<endl;
            gets(format);
        }
        
          void putdata()                                           //   FUNCTION OVERRIDING
        {
            publication::putdata(); 
            cout<<"Disk type : "<<format<<endl;
        }
};
class language:public book                                        //MULTILEVEL INHERITANCE (pub->book->lang)
{
       protected:
        
           char lang[7];
        
       public:
         
            ~language()
            {    }
           
            void getdata()                                            //   FUNCTION OVERRIDING
            {   
                book::getdata();
                   cout<<"enter language "<<endl;
                cin>>lang;
        
            }
            
            void putdata()                                             //   FUNCTION OVERRIDING
            { 
                book::putdata();
                cout<<"language : ";
                cout<<lang<<endl;
            }
};

int secs(casete cs)                                                    //   FRIEND FUNCTION DEFINITION
{
    return (cs.mins * 60);
     
}

int main()
{ 
     char f,e;
xyz:                                                                     // GOTO STATEMENT
     {
        publication *bookk,  *cassete, *diskk;                           //BASE CLASS POINTERS
        casete c;
      
        bookk=new language;
        cassete=new casete;                                              // INSTANTIATING OBJECTS
        diskk=new disk;
    
        cout<<"enter book particulars"<<endl;
        bookk->getdata();    
        cout<<endl;
    
        cout<<"enter cassette particulars"<<endl;
        cassete->getdata();                                             //      DYNAMIC BINDING
        cout<<endl;

        cout<<"enter disk particulars"<<endl;
        diskk->getdata();
        cout<<"want to display the entered data y/n?"<<endl;
        cin>>e;
       
        if(e=='y')
       {
         cout<<" book particulars"<<endl;                                //  DISPLAY DATA
         bookk->putdata();
         cout<<endl;

         cout<<" cassette particulars"<<endl;
         cassete->putdata();
         cout<<"time in secs "<<secs(c)<<endl<<endl;                     //     FRIEND FUNCTION CALLING
     
         cout<<" disk particulars"<<endl;
         diskk->putdata();
         cout<<endl;
       }
           
        cout<<"want to enter more data y/n"<<endl;
        cin>>f;
        
        if(f=='y')
        {
            goto xyz;
        }
        elsereturn 0;
       
       delete bookk;
       delete cassete;
       delete diskk;    
     
     }
 
     while(f!='n');
   
     return 0;
}
