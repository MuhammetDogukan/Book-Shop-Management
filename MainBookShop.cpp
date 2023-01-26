#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include "BookShop.h"
#include "WholeSaler.h"
#include "Sales.h"

using namespace std;

int main()
{
	int move;
	do
	{
		int x;
		system("CLS");
		cout<<"\tBook Shop Managment System\n\tYou can control your inventory"<<endl;
		cout<<"[1] Add book"<<endl;
		cout<<"[2] Show all books"<<endl;
		cout<<"[3] Delete book"<<endl;
		cout<<"[4] Change information of book"<<endl;
		cout<<"[5] Increase the number of books you want"<<endl;
		cout<<"[6] information about the warehouse"<<endl;
		cout<<"[7] Add wholesaler"<<endl;
		cout<<"[8] Show wholesaler"<<endl;
		cout<<"[9] Profit Calculator"<<endl;
		cout<<"[10] Sell book"<<endl;
		cout<<"[11] Exit"<<endl;
		cout<<"Select the action you want to do:";
		cin>>move;
		
		if(move==1)
		{
			
			system("CLS");
			WholeSaler salerInf1("",0);
		
			
			BookShop myBook(0,"","",0,0,0,salerInf1);
			myBook.writeToFile();
			
			system("CLS");
			
		}
		else if(move==2)
		{
			system("CLS");
			WholeSaler salerInf1("",0);
			BookShop showMyBook(0,"","",0,0,0,salerInf1);
			showMyBook.showFromFile();
			
			
		}
		else if(move==3)
		{
			system("CLS");
			WholeSaler salerInf1("",0);
			BookShop showMyBook(0,"","",0,0,0,salerInf1);
			showMyBook.showFromFile();
			showMyBook.deleteBook();
			
			
		}
		else if(move==4)
		{
			system("CLS");
			WholeSaler salerInf1("",0);
			BookShop book1(0,"","",0,0,0,salerInf1);
			book1.showFromFile();
			book1.changeBook();	
			
		}
		else if(move==5)
		{
			system("CLS");
			WholeSaler salerInf1("",0);
			BookShop book1(0,"","",0,0,0,salerInf1);
			book1.showFromFile();
			
			int currentId;
			string currentName;
			string currentAuthor;
			float currentPurchase;
			float currentSale;
			int currentNumber;
			int wantedId;
			int increase;
			
			ifstream currentBook;
			ofstream editBook;
			currentBook.open("Books.txt");
			editBook.open("Booksedit.txt",ios::app);
			
			
			
			if(currentBook.is_open())
			{
				cout<<"Enter the id you want to increase: ";
				cin>>wantedId;
				
				cout<<"how much do you want to increase: ";
				cin>>increase;
				
				currentBook >> currentId>> currentName>> currentAuthor>>currentPurchase>> currentSale>> currentNumber;
				while(!currentBook.eof())
				{
					int j=0;
					
					
					if (wantedId==currentId)
					{
						currentNumber+=increase;
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
		else if(move==6)
		{
			system("CLS");
			ifstream show;
			show.open("Warehouse.txt", ios::in);
			
			int type;
			int total;
			if(show.is_open())	
			{
				show>>type;
				show>>total;
				
				cout<<"You have a total of "<<type<<" types of books"<<endl;
				cout<<"You have a total of "<<total<<" books"<<endl;
			}
			
			else
			{
				cout<<"There isn't book attached"<<endl;
			}
			show.close();
			string x;
			cout<<"Press something to continue: ";
			cin>>x;
		}
		else if(move==7)
		{
			system("CLS");
			WholeSaler myWholeSaler("",0);
			myWholeSaler.addToFile();
			string x;
			cout<<"Press something to continue: ";
			cin>>x;
		}
		else if(move==8)
		{
			system("CLS");
			WholeSaler Saler1("",0);
			Saler1.readFromFile();
			string x;
			cout<<"Press something to continue: ";
			cin>>x;
		}
		else if(move==9)
		{
			system("CLS");
			WholeSaler salerInf1("",0);
			BookShop calculator(0,"","",0,0,0,salerInf1);
			float profit;
			float a;
			
			cout<<"Please enter puchase price: ";
			cin>>a;
			calculator.setPurchasePrice(a);
			cout<<"Please enter sale price: ";
			cin>>a;
			calculator.setSalePrice(a);
			cout<<"Please enter number of book: ";
			cin>>a;
			calculator.setNumberOfBook(a);
			
			--calculator;
			cout<<calculator;
			
			
		}
		else if (move==10)
		{
			system("CLS");
			Sales customer;
			customer.showFromFile();
			if (customer.indicator != 5)
			{
				customer.setBookId(customer.takeSellId());
				customer.setNumberOfBook(customer.takeSellNumber());
				customer.decreaseBook(customer.getBookId(),customer.getNumberOfBook());
				customer.takeInfOfCust(customer.takeSellId(),customer.getNumberOfBook());
			}
			
			
			
		}
		else if(move==11)
		{
			cout<<endl<<"You are leaving the program"<<endl;
			
		}
		else 
		{
			cout<<"You entered wrong key"<<endl;
			system("pause");
		}
	}while(move!=11);
	
	
	return 0;
}
