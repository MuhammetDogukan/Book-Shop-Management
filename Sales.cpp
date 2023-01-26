#include<string>
#include <iostream>
#include<fstream>
#include"Sales.h"
#include"BookShop.h"
using namespace std;

Sales::Sales(long long int _customerTell, string _customerName, string _customerAdress)
{
	setCustomerTell(_customerTell);
	setCustomerName(_customerName);
	setCustomerAdress(_customerAdress);
}
Sales::~Sales()
{
	
}
void Sales::setCustomerTell(long long int _customerTell)
{
	customerTell= _customerTell;
}
void Sales::setCustomerName(string _customerName)
{
	customerName= _customerName;
}
void Sales::setCustomerAdress(string _customerAdress)
{
	customerAdress= _customerAdress;
}
long long int Sales::getCustomerTell() const
{
	return customerTell;
}
string Sales::getCustomerName() const
{
	return customerName;
}
string Sales::getCustomerAdress() const
{
	return customerAdress;
}
int Sales::takeSellId()
{
	int takenId;
	cout<<"Please enter the Id of the book you want to buy: ";
	cin>>takenId;
	return takenId;
}
int Sales::takeSellNumber()
{
	int takenNumber;
	cout<<"how many books do you want to buy: ";
	cin>>takenNumber;
	return takenNumber;
}
void Sales::takeInfOfCust(int a,int b)
{
	string infName;
	string infAdress;
	long long int infTell;
	
	cout<<"Please enter your name: ";
	cin>>infName;
	cout<<"Please enter your adress: ";
	cin>>infAdress;
	cout<<"Please enter your tell number: ";
	cin>>infTell;
	
	ofstream info;
	info.open("CustomerInf", ios::out|ios::app);
	info<<"Recipient's name: "<<infName<<endl;
	info<<"Buyer's address: "<<infAdress<<endl;
	info<<"Recipient's phone number: "<<infTell<<endl;
	info<<"ID of the purchased book: "<<a<<endl;
	info<<"Number of books the buyer purchased: "<<b<<endl;
	
	info.close();
}
void Sales::decreaseBook(int i,int n)
{
	int currentId;
	string currentName;
	string currentAuthor;
	float currentPurchase;
	float currentSale;
	int currentNumber;
	int wantedId;
	
	ifstream currentBook;
	ofstream editBook;
	currentBook.open("Books.txt");
	editBook.open("Booksedit.txt",ios::app);
	
	
	if(currentBook.is_open())
	{
		currentBook >> currentId>> currentName>> currentAuthor>>currentPurchase>> currentSale>> currentNumber;
		while(!currentBook.eof())
		{
			int j=0;
			
			
			if (i==currentId)
			{
				currentNumber=n;
				
			}
			
			editBook<< currentId <<endl<< currentName<<endl<< currentAuthor<<endl << currentPurchase <<endl<< currentSale<<endl<< currentNumber<<endl;
		
			currentBook >> currentId>> currentName>> currentAuthor>>currentPurchase>> currentSale>> currentNumber;
			
			
		}
		
		currentBook.close();
	    editBook.close();
	    remove("Books.txt");
	    rename("Booksedit.txt","Books.txt");
	    
	    
	}
	
}
