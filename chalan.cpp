#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include<process.h>

class vech_rec
{   int num,i;
    char fname[20],vech[10],name[20], date[15], addrs[50], crime[20];
    long int reg,number,amount;
    void disp();
public:
    void get();
    void enter();
    void show();
    void del();
    void mod();
    void amount1();


}c;
void vech_rec::amount1()
{
	if(strcmp(crime,"red light")==0)
	{
		amount=100;
	}
	else if(strcmp(crime,"helmet")==0)
	{
		amount=100;
	}
	else if(strcmp(crime,"without license")==0)
	{
		amount=500;
	}
	else if(strcmp(crime,"triple riding")==0)
	{
		amount=100;
	}
	else if(strcmp(crime,"minor age")==0)
	{
		amount=500;
	}
	else if(strcmp(crime,"improper parking")==0)
	{
		amount= 100;
	}
	else if(strcmp(crime,"defective number plate")==0)
	{
		amount=100;
	}
	else if(strcmp(crime,"over speeding")==0)
	{
		amount=300;
	}
	else
	{
		cout<<"\n court challan";
	}
}
/*--------------------------------------------------------------------------*/
/*
	FUNCTION FOR GETTING THE DETAILS OF THE VEHICLE
								*/
void vech_rec::get()
{
    puts("\nEnter name of owner:");
    gets(name);
    puts("\nEnter father's name:");
    gets(fname);
    puts("\nEnter vehicle number:");
    gets(vech);
    puts("\nEnter registration number:");
    cin>>reg;
    puts("\nEnter registration date");
    gets(date);
    puts("\nEnter address:");
    gets(addrs);
    puts("\nEnter crime commited:");
    gets(crime);
    c.amount1();
    cout<<"\n amount";
    cout<<amount;

}
/*--------------------------------------------------------------------------*/
/*
	FUNCTION FOR SHOWING THE DETAILS OF THE VEHICLE
								*/
void vech_rec::disp()
{
    cout<<"\nThe record of vehicle:\n";
    cout<<"\nName of owner: "<<name;
    cout<<"\nName of father: "<<fname;
    cout<<"\nVehicle number:"<<vech;
    cout<<"\nRegistration number:"<<reg;
    cout<<"\nregistration date: "<<date;
    cout<<"\nAddress: "<<addrs;
    cout<<"\nCrime: "<<crime;
    cout<<"\n amount:"<<amount;

}
/*--------------------------------------------------------------------------*/
/*	FUNCTION FOR ENTERING THE DETAILS OF A VEHICLE
							      */
void vech_rec::enter()
{
    ofstream ofile;
    ofile.open("challan", ios::app);
    get();
    ofile.write((char*)&c, sizeof(c));
    ofile.close();
}
/*--------------------------------------------------------------------------*/
/*
	FUNCTION FOR VIEWING THE DETAILS OF VEHICLE
							  */
void vech_rec::show()
{
    long int reg1,choice,k=0;
    ifstream ifile;
    ifile.open("challan",ios::app);
    ifile.seekg(0, ios::beg);
    ifile.read((char*)&c, sizeof(c));

    cout<<"\n press 1 for whole data";
    cout<<"\n press 2 for single data";
    cin>>choice;
	switch(choice)
	{
	    case 1:
	    while(ifile)
	    {
	    disp();
	      ifile.read((char*)&c, sizeof(c));
	    }
	     break;
   case 2:   cout<<"\n enter registration number whose record you want see" ;
		cin>>reg1;
	   if(!ifile)
	   {
	   break;
	   }
	   ifile.seekg(0);

	   while(ifile)
	   {
		 ifile.read((char*)&c, sizeof(c));

		   if(reg==reg1)
		   {
			 disp();
			 k=1;
			 break;

		   }
	   }
	   if(k==0)
	   cout<<"\n not found";
   break;

    default :
    cout<<"wrong input";
    break;
    }

    ifile.close();
}
/*--------------------------------------------------------------------------*/
/*
	FUNCTION FOR DELETING THE RECORDS OF A VEHICLE
								*/
void vech_rec::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("challan", ios::app);
    ofstream ofile;
    ofile.open("new", ios::app);
    puts("\nEnter the vehicle number whose records you want to delete");
    gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
    if (strcmpi(b,vech ))
    ofile.write((char*)&c, sizeof(c));
    ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove ("challan");
    rename("new", "challan");
    cout<<"\n record deleted";
}
/*--------------------------------------------------------------------------*/
/*
	FUNCTION FOR MODIFYING THE DETAILS OF A VEHICLE
								*/
void vech_rec::mod()
{
    char d[20];
    int p;
    puts("\nEnter vehicle number whose record you want to modify\n");
    gets(d);
    fstream f;
    f.open("challan", ios::in|ios::out);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a=f.tellg();
    while(! f.eof())
    {
	if (!strcmpi(d, vech))
	{
	    puts("\nPress 1 to change name\nPress 2 to change address\nPress 3 to change crime committed\npress 4 to exit");
	    cin>>p;
	    switch(p)
	    {
	    case 1:
	    cout<<"\n enter name";
		gets(name);
		break;

	    case 2:
	    cout<<"\n enter address";
		gets(addrs);
		break;
	    case 3:
	    cout<<"\n enter crime";
		gets(crime);
		c.amount1();
		cout<<"\n amount:"<<amount;
		break;
	    case 4:exit(0);
	    }
	    f.seekg(a-sizeof(c), ios::beg);
	    f.write((char*)&c, sizeof(c));
	}
	f.read((char*)&c, sizeof(c));
	a=f.tellg();
    }
    f.close();
}
/*--------------------------------------------------------------------------*/
/*
	MAIN FUNCTION
			*/
void main ()
{
    clrscr();
    char pwd[4];
    int i=0;
    while(i<5)
    {
    pwd[i]=getch();
    cout<<"*";
    ++i;
    }
    cout<<endl;
    if(strcmpi(pwd,"ishan")==0)
    {
    cout<<"\t\t\t WELCOME \t\t\t";

    int ch;
    char choice;
    do
    {
    cout<<"\n\t\t\t VEHICLE CHALLAN MANAGEMENT \t\t\t";
cout<<"\n1. View vehicle details                 ";
    cout<<"\n2. Add new vehicle details              ";
    cout<<"\n3. Delete a vehicle record              ";
    cout<<"\n4. Modify a vehicle record              ";
    cout<<"\n5. Exit                                  ";
    cout<<"\nEnter your choice: ";
    cin>>ch;

    clrscr();
    switch(ch)
    {
    case 1:
	     cout<<"\n you choose viewing";
	     c.show();
	break;
    case 2:
	    cout<<"\n you choose adding";
	    c.enter();

	    break;
    case 3: cout<<"\n you choose delete";
	    c.del();
	    break;
    case 4: cout<<"\n you choose modifying";
	    c.mod();
	    break;
    case 5:
	    goto exit;
    default:
	{
	 cout<<"\nerror!";
	}
	break;
    }
    cout<<"\ncontinue? (y/n)\n";
    cin>>choice;
    clrscr();
    }while(choice=='y'||choice=='Y');
    exit:
    cout<<"\n !!!!!Good bye!!!!\n";

    getch();
    }
    else
    {
    cout<<"\n wrong password";
    }
    getch();

}
/*--------------------------------------------------------------------------*/
