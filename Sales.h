#ifndef SALES_H
#define SALES_H

#include<string>
#include"BookShop.h"

using namespace std;

class Sales :public BookShop
{
	public:
		Sales(long long int _customerTell=0, string _customerName="", string _customerAdress="");
		~Sales();
		void setCustomerTell(long long int _customerTell);
		void setCustomerName(string _customerName);
		void setCustomerAdress(string _customerAdress);
		long long int getCustomerTell() const;
		string getCustomerName() const;
		string getCustomerAdress() const;
		int takeSellId();
		int takeSellNumber();
		void takeInfOfCust(int a,int b);
		void decreaseBook(int i,int n);
	
	private:
		long long int customerTell;
		string customerName;		
		string customerAdress;
		
};

#endif
