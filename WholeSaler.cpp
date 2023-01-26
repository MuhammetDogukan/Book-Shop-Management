#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "WholeSaler.h"

using namespace std;

WholeSaler::WholeSaler(string salerName, long long int salerTell)
{
	setSalerName(salerName);
	setSalerTell(salerTell);
}
WholeSaler::~WholeSaler()
{
	
}
void WholeSaler::setSalerName(string saler)
{
	salerName=saler;
}
void WholeSaler::setSalerTell(long long int tell)
{
	salerTell=tell;
}
string WholeSaler::getSalerName() const
{
	return salerName;
}
int WholeSaler::getSalerTell() const
{
	return salerTell;
}
void WholeSaler::addToFile()
{
	int id=0;
	string name;
	long long int tell;
			
	
	cin.ignore();
	cout<<"Please enter the wholesaler name: ";
	getline(cin,name);
	do
	{		
		cout<<"Please enter the 10 digit wholesaler tell: ";
		cin>>tell;
	}while (tell<999999999||tell>10000000000);
			
	
	
	ofstream add;
	add.open("WholeSaler.txt", ios::out|ios::app);
	
	add<<id<<endl;
	add<<name<<endl;
	add<<tell<<endl;
	
	add.close();

}
void WholeSaler::addToFile(int id)
{
	string name;
	long long int tell;
			
	cin.ignore();
	cout<<"Please enter the wholesaler name: ";
	getline(cin,name);
	do
	{		
		cout<<"Please enter the 10 digit wholesaler tell: ";
		cin>>tell;
	}while (tell<999999999||tell>10000000000);
			
	
	
	ofstream add;
	add.open("WholeSaler.txt", ios::out|ios::app);
	
	add<<id<<endl;
	add<<name<<endl;
	add<<tell<<endl;
	
	add.close();
	
}
void WholeSaler::readFromFile()
{
	int id;
	string readName;
	long long int readTell;
	
	ifstream show;
	show.open("WholeSaler.txt", ios::in);
	if(show.is_open())
	{
		cout<<"\t_ID of The Book You Bought_"<<setw(20)<<"_Wholesaler Name_"<<setw(20)<<"_Wholesaler Tell_"<<endl;
		show>>id>>readName>>readTell;
		while(!show.eof())
		{
			cout<<"\t"<<id<<setw(35)<<readName<<setw(29)<<readTell<<endl;
			show>>id>>readName>>readTell;
		}
	}
	else
	{
		cout<<"There isn't book attached"<<endl;
	}
	show.close();
	
}
