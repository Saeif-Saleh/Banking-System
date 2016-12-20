#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
const int size=300;
string Name[size];
double Balance[size];
int ID[size];
float Amount;
int AccountNumber;
int choice;//This is for Menu function
void menu();// Prototype for the  main function to call it anywhere.

//newaccount

void newaccount()//This function is responsbile for opening new account.
{
ofstream outfile;//writing to the file.
ifstream infile;//reading from the file 
int NewID=1;// starts from 1
int numaccount =0; //starts from zero
infile.open("BankInformation.txt");//opening the file.
while ( infile>>ID[numaccount]>>Name[numaccount]>>Balance[numaccount])  // Reading from the file.
{ 
numaccount++;
NewID++;
}
ID[numaccount]=NewID;//ID number for the new customer
cout<<" Please enter your first name to be your Account Name "<<endl;
cin>>Name[numaccount]; //Enter the name of new customer
cout<<" Your bank ID number  is : "<<ID[numaccount]<<endl;          //   Giving the new customer new ID 
Balance[numaccount]=0;
cout<<" Your balance is : "<<Balance[numaccount]<<"  QR."<<endl;
cout<<endl;
cout<<" Please keep your ID number to use it in any action to your acount .. "<<endl;
outfile.open("BankInformation.txt");
for( int p=0;p<NewID;p++)// print changes into the file
outfile<<ID[p]<<" "<<Name[p]<<" "<<Balance[p]<<" "<<endl;
outfile.close(); //closing the file.
cout<<"\n\n"<<endl; //giving a space
menu(); //caling the menu again
}

//withdraw

void withdraw()
{  ofstream outfile;  // writing to the file
ifstream infile;    // reading from the file
int z =0;
infile.open("BankInformation.txt");
while (  infile>>ID[z]>>Name[z]>>Balance[z])
{ 
z++;
}
infile.close();
cout<<" First...Enter The Account ID Number If you want withdraw Money"<<endl;
cin>>AccountNumber;
bool temp=false;   
for ( int i=0;i<z;i++)
{   if (ID[i]==AccountNumber)     //Checking if the account number= any ID number in the system.
{   temp=true;      // if that is true do the following
cout<<" Your available Balance is : "<<Balance[i]<<"  QR."<<endl;
cout<<" Second..Enter the Amount to withdraw "<<endl;
cin>>Amount;  // Entering the amount of money
if ( Amount >= Balance[i] || Amount < 0)  // Validation if the Entering value is larger than the value in the system or less than zero. 
cout<<"Sorry .. Faild .. No Balance ! or Invalid Process"<<endl; // 
else
Balance[i]= Balance[i]-Amount;   // If it is ok the customer will be able to withdraw from his balance
cout<<" Your Balance now is : "<<Balance[i]<<"  QR."<<endl; 
}
}
if(!temp) cout<<" Wrong Account Number ID "<<endl; // if the accountnumber was not find in the system this message will appear.
{
outfile.open("BankInformation.txt");
for( int p=0;p<z;p++)// print changing into file
outfile<<ID[p]<<" "<<Name[p]<<" "<<Balance[p]<<" "<<endl;
outfile.close(); }
cout<<"\n\n"<<endl;
menu(); //calling the menu again
}

//deposit

void deposit()  // This function is responsible for deopsing money
{  ofstream outfile; // Printing changes
ifstream infile;// Reading from the file
//int counter=0;
int z =0;
infile.open("BankInformation.txt");
while (  infile>>ID[z]>>Name[z]>>Balance[z])
{ 
z++;
}
infile.close();
cout<<" First..Enter The Account ID Number If you want Deposit Money"<<endl;
cin>>AccountNumber;

bool temp=false;
for (int i=0;i<z;i++)
{   if (ID[i]==AccountNumber) // if the account number was found in the file then do the following.
{   temp=true;
cout<<" Your available Balance is : "<<Balance[i]<<"  QR."<<endl;// Telling the customer his balance in the bank before he deposit. 
cout<<" Second..Enter the Amount to Deposit"<<endl; 
cin>>Amount;  // Entering the new amount of money that will be deposited.

if (Amount < 0)  // Validation if the Entering value is less than zero. 
cout<<"Sorry .. Faild .. No Balance ! or Invalid Process"<<endl; // 
else
Balance[i]= Balance[i]+Amount; // Adding to the Balance in the system.
cout<<" Your Balance now is : "<<Balance[i]<<"  QR."<<endl; // Telling the customer the new balance
}

}
if(!temp) cout<<"Wrong Account Number"<<endl; // if the account number was not found.

outfile.open("BankInformation.txt");
for( int p=0;p<z;p++)// print changing into file
outfile<<ID[p]<<" "<<Name[p]<<" "<<Balance[p]<<" "<<endl;

outfile.close();// close the file
cout<<"\n\n"<<endl;
menu(); //calling the function again
}

//displayinfo

void displayinfo()// This function is responsible for displaying the informaion of certain customer.
{ofstream outfile;// Writing to the file
ifstream infile;// Reading from the file.
infile.open("BankInformation.txt");// Opening the file.
int counter=0;
int i =0;
while (!infile.eof())
{ infile>>ID[i]>>Name[i]>>Balance[i];  // Copying the Data in the system to the arrays
i++;
counter++;
}
infile.close();
cout<<" Enter The Account ID To show it's details "<<endl; // Prompting the user to enter his account ID
cin>>AccountNumber;
bool temp=false;  
for ( int i=0;i<counter;i++)       //Searching for the accountnumber in the system     
{   if (ID[i]==AccountNumber) // if the account number was found then do the following.
{   temp=true;
cout<<" AccountNumber \t "<< " AccountName\t"<<"       Balance\t";
cout<<"\n  "<<ID[i]<<"\t            "<<Name[i]<<setw(20)<<Balance[i]<<"  QR."<<endl; //displaying the ID and the name and the Balance.
}
}
if(!temp) cout<<" Wrong Account Number ID ! "<<endl; // If the account number was not found then display this message.
cout<<endl;
menu();// and then calling the menu again
}
void displaytotal() // This function is responsbile for displaying the total money in the whole system.
{ofstream outfile; // Writing to the file.
ifstream infile;    // reading from the file.
infile.open("BankInformation.txt");  // opening the file.
int counter=0;
int i =0;
while (!infile.eof())
{ infile>>ID[i]>>Name[i]>>Balance[i];  // Copying the Data from the system to the arrays
i++;
counter++;
}
infile.close();
double sum=0;  //  Varaible to find the sum of the Balances
for (int i=0;i<counter; i++) 
sum=sum  + Balance[i];  // Adding to the sum everytime 
cout<<" The Total Balance for all Customers is : " <<sum<<"  QR."<<endl;
cout<<"\n\n"<<endl;// To give a space after the previous transaction
menu();// calling the menu again
}

// exit function

void exit()
{   cout<<" Every thing has been saved, Thanks for using our Bank .. "<<endl;
}

// menu function


void menu()  // This is the menu which will appear always till the user press 6 to exit
{
cout<<"Welcome to our Banking System\nYou can do one of the following actions using this banking \nsystem:"<<endl;
cout<<"1. Add a new account "<<endl;
cout<<"2. Withdraw from the account"<<endl;
cout<<"3. Deposit to the account"<<endl;
cout<<"4. Display the account information"<<endl;
cout<<"5. Display total of the customers' balances"<<endl;
cout<<"6. Exit"<<endl;
cout<<"Your Choice is ";
cin>>choice;  // Entering the choice of the customer
switch (choice)
{
case 1:
newaccount();
break;
case 2:
withdraw();
break;
case 3:
deposit();
break;
case 4:
displayinfo();
break;
case 5:
displaytotal();
break;
case 6:
exit();
break;
default:cout<<"Wrong Choice Try Againg Please"<<endl; 
	    cout<<"\nPlease Choose One Of The Choices"<<endl;
menu();// if anyone of the choices wasn't choosen then call the function again
}
}

//Main


void main()
{ menu(); //calling the  menu
}

