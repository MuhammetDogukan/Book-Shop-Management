#include <string>
#ifndef WHOLESALER_H
#define WHOLESALER_H

using namespace std;

class WholeSaler
{
	public:
		WholeSaler(string salerName="",long long int salerTell=0);
		~WholeSaler();
		void setSalerName(string saler);
		void setSalerTell(long long int tell);
		string getSalerName() const;
		int getSalerTell() const;
		void addToFile();
		void addToFile(int id);
		void readFromFile();
		
		
	
	
	
	private:
		string salerName;
		int salerTell;
		
};

#endif
