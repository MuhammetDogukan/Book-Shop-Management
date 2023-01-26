#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "BookShop.h"
#include "WholeSaler.h"

using namespace std;

int BookShop::typesOfBook=0;
int BookShop::totalNumberOfBooks=0;
float BookShop::profit=0;
int BookShop::indicator=0;

BookShop::BookShop( const int &id, const string &name, const string &author, const float &purchase, const float &sale, const int &number,
	const WholeSaler &salersInf)
	: bookId(id),
   	  bookName(name),
	  authorName(author),
	  purchasePrice(purchase),
	  salePrice(sale),
	  numberOfBook(number),
	  salerInf(salersInf)
{
	
}
BookShop::BookShop()
{
	setBookId(0);
	setBookName("");
	setAuthorName("");
	setPurchasePrice(0);
	setSalePrice(0);
	setNumberOfBook(0);
}
BookShop::~BookShop()
{
	string x;
	cout<<"Press something to continue: ";
	cin>>x;
}

void BookShop::setBookId(int id)
{
	bookId=id;
}

void BookShop::setBookName(string name)
{
	if(name.size()<=25)
	{
		bookName=name;
	}
	else 
	{
		bookName=name.substr(0,25);
		cerr<<"The program takes only first 25 characters as book name.";
	}
}

void BookShop::setAuthorName(string author)
{
	if(author.size()<=25)
	{
		authorName=author;
	}
	else 
	{
		authorName=author.substr(0,25);
		cerr<<"The program takes only first 25 characters as author name.";
	}
}
void BookShop::setPurchasePrice(float purchase)
{
	purchasePrice=purchase;
}
void BookShop::setSalePrice(float sale)
{
	salePrice=sale;
}
void BookShop::setNumberOfBook(int number)
{
	numberOfBook=number;
}
int BookShop::getBookId() const
{
	return bookId;
}
string BookShop::getBookName() const
{
	return bookName;
}
string BookShop::getAuthorName() const
{
	return authorName;
}
template<typename T>
T BookShop::getPurchasePrice() const
{
	return purchasePrice;
}
template<typename T>
T BookShop::getSalePrice() const
{
	return salePrice;
}
int BookShop::getNumberOfBook() const
{
	return numberOfBook;
}
int BookShop::getTypesOfBook()
{
	return typesOfBook;
}
int BookShop::getTotalNumberOfBooks()
{
	return totalNumberOfBooks;
}
float BookShop::getProfit()
{
	return profit;
}
void BookShop::writeToFile()
{
	
	
	int id;
	string name;
	string author;
	float purchase;
	float sale;
	int number;
	string salerName;
	
	system("CLS");
	do
	{
		cout<<"Please enter the 7 digit book ID: ";
		cin>>id;
	}while (id<999999||id>10000000);
	cin.ignore();
	cout<<"Please enter the book name: ";
	getline(cin,name);
	cout<<"Please enter the author of the book: ";
	getline(cin,author);
	cout<<"Please enter purchase price of the book: ";
	cin>>purchase;
	cout<<"Please enter sale price of the book: ";
	cin>>sale;
	cout<<"Please enter the number of book: ";
	cin>>number;
	WholeSaler myWholeSaler("",0);
	myWholeSaler.addToFile(id);
	
	ifstream old;
	old.open("Warehouse.txt",ios::in);
	old>>typesOfBook;
	old>>totalNumberOfBooks;
	old.close();
	
	ofstream write;
	write.open("Books.txt", ios::out|ios::app);
	write<<id<<endl;
	write<<name<<endl;
	write<<author<<endl;
	write<<purchase<<endl;
	write<<sale<<endl;
	write<<number<<endl;
	
	totalNumberOfBooks=totalNumberOfBooks + number;
	typesOfBook++;
	
	ofstream inf;
	inf.open("Warehouse.txt", ios::out|ios::trunc);
	inf<<typesOfBook<<endl;
	inf<<totalNumberOfBooks<<endl;
	
	inf.close();
	write.close();
}
void BookShop::showFromFile()
{
	int readId;
	string readName;
	string readAuthor;
	float readPurchase;
	float readSale;
	int readNumber;
	
	ifstream show;
	show.open("Books.txt", ios::in);
	if(show.is_open())
	{
		cout<<"\t_Book ID_"<<setw(20)<<"_Book Name_"<<setw(20)<<"_Author Name_"<<setw(20)<<"_Purchase Price_"<<setw(20)<<"_Sale Price_"<<setw(20)<<"_Number of Book_"<<endl;
		show>>readId>>readName>>readAuthor>>readPurchase>>readSale>>readNumber;
		while(!show.eof())
		{
			cout<<"\t"<<readId<<setw(20)<<readName<<setw(20)<<readAuthor<<setw(20)<<readPurchase<<setw(20)<<readSale<<setw(20)<<readNumber<<endl;
			show>>readId>>readName>>readAuthor>>readPurchase>>readSale>>readNumber;
		}
	}
	else
	{
		cout<<"There isn't book attached"<<endl;
		indicator=5;
	}
	show.close();
}
void BookShop::deleteBook()
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
		cout<<"Enter the id you want to delete: ";
		cin>>wantedId;
		
		currentBook >> currentId>> currentName>> currentAuthor>>currentPurchase>> currentSale>> currentNumber;
	
		while(!currentBook.eof())
		{
			int j=0;
			
			
			if (wantedId==currentId)
			{
				int control=2;
				do
				{
					cout<<"Are you sure you want to delete book number "<<currentId<<"(1/0):";
					cin>>control;
					if(control==1)
					{
						j=1;
						cout<<"The book is deleted"<<endl;
					}
					else if(control==0)
					{
						cout<<"The book is not deleted"<<endl;
					}
					else 
					{
						cout<<"Wrong key"<<endl;
					}
				}while(control!=1&&control!=2);
				
			}
			if(j==0)
			{
				editBook<< currentId <<endl<< currentName<<endl<< currentAuthor<<endl << currentPurchase <<endl<< currentSale<<endl<< currentNumber<<endl;
				
			}
			currentBook >> currentId>> currentName>> currentAuthor>>currentPurchase>> currentSale>> currentNumber;
			
			
		}
		
		currentBook.close();
	    editBook.close();
	    remove("Books.txt");
	    rename("Booksedit.txt","Books.txt");
	}
	
	
	
}
void BookShop::changeBook()
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
	
	cout<<"Enter the id you want to change: ";
	cin>>wantedId;
	if(currentBook.is_open())
	{
		currentBook >> currentId>> currentName>> currentAuthor>>currentPurchase>> currentSale>> currentNumber;
		while(!currentBook.eof())
		{
			
			
			if (wantedId==currentId)
			{
				do
				{
					cout<<"What is the new Id: ";
					cin>>currentId;
				}while (currentId<999999||currentId>10000000);
				
				cout<<"What is the new book name: ";
				cin>>currentName;
				
				cout<<"What is the new author name: ";
				cin>>currentAuthor;
				
				cout<<"What is the new new purchase: ";
				cin>>currentPurchase;
				
				cout<<"What is the new sale: ";
				cin>>currentSale;
				
				cout<<"What is the new number of book: ";
				cin>>currentNumber;
				
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
BookShop &BookShop::operator+=(int number)
{
	int totalNumber;
	totalNumber=numberOfBook+number;
	return *this;
}
ostream &operator<<(ostream &output, BookShop &myBookShop)
{
	output<<"\nPruchase Price: "<<myBookShop.purchasePrice
	<<"\nSale Price: "<<myBookShop.salePrice
	<<"\nNumber of Book: "<<myBookShop.numberOfBook
	<<"\nThe profit: "<<myBookShop.profit<<endl;
	
	return output;
}
BookShop &BookShop::operator--()
{
	
	
	
	profit=(salePrice - purchasePrice)*numberOfBook;
	
	return *this;
}
