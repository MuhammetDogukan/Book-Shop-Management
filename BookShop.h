#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include<string>
#include "WholeSaler.h"

using namespace std;

class BookShop
{
		friend ostream &operator<<(ostream &output, BookShop &myBookShop);
	public:
		BookShop(const int &, const string &, const string &, const float &, const float &, const int &,
			const WholeSaler &);
		BookShop();
		~BookShop();
		void setBookId(int id);
		void setBookName(string name);
		void setAuthorName(string author);
		void setPurchasePrice(float purchase);
		void setSalePrice(float sale);
		void setNumberOfBook(int number);
		int getBookId() const;
		string getBookName() const;
		string getAuthorName() const;
		template<typename T>
		T getPurchasePrice() const;
		template<typename T>
		T getSalePrice() const;
		int getNumberOfBook() const;
		static int getTypesOfBook();
		static int getTotalNumberOfBooks();
		static float getProfit();
		void writeToFile();
		void showFromFile();
		void deleteBook();
		void changeBook();
		BookShop &operator+=(int number);
		BookShop &operator--();
		static int indicator;
		
	private:
		int bookId;
		string bookName;
		string authorName;
		float purchasePrice;
		float salePrice;
		int numberOfBook;	
		const WholeSaler salerInf;
		
		
		static int typesOfBook;
		static int totalNumberOfBooks;
		static float profit;
		
};

#endif
