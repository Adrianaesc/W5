#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include<regex>
#include <algorithm>
#include "Book.h"

using namespace std;
namespace sdds {

	Book::Book() {
		author="";
		Btitle="";
		publicationcountry="";
		pubYear=0;
		Bprice=0;
		desc="";
	}

	const std::string& Book::title()const {
		return Btitle;
	}

	const std::string& Book::country() const {
		return publicationcountry;
	}

	const size_t& Book::year() const {
		//const int& temp = pubYear;
		//return temp;
		return this->pubYear;
	}

	double& Book::price() {
		return Bprice;
	}

	Book::Book(const std::string& strBook) {
		//AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		author = "";
		Btitle="";
		publicationcountry="";
		pubYear = 0;
		Bprice = 0;
		desc="";

		string book;
		book = strBook;

		int index=0;
		book = regex_replace(book, regex(" +"), " ");
		book = regex_replace(book, regex("^ +"), " ");


		index = book.find(',');
		author = book.substr(0, index);
		book.erase(0, index +1);
		if (author[author.length() - 1] == ' ')
			author.erase(author.length() - 1, 1);
		if (author[0] == ' ')
			author.erase(0, 1);

		index = book.find(',');
		Btitle = book.substr(0, index);
		book.erase(0, index + 1);

		if (Btitle[Btitle.length() - 1] == ' ')
			Btitle.erase(Btitle.length() - 1, 1);
		if (Btitle[Btitle.length() - 1] == ' ')
			Btitle.erase(Btitle.length() - 1, 1);
		if (Btitle[0] == ' ')
			Btitle.erase(0, 1);


		index = book.find(',');
		publicationcountry = book.substr(0, index);
		book.erase(0, index + 1);
		if (publicationcountry[publicationcountry.length() - 1] == ' ')
			publicationcountry.erase(publicationcountry.length() - 1, 1);
		if (publicationcountry[0] == ' ')
			publicationcountry.erase(0, 1);
		if (publicationcountry[0] == ' ')
			publicationcountry.erase(0, 1);

		index = book.find(',');
		Bprice = stod(book.substr(0, index));
		book.erase(0, index + 1);


		index = book.find(',');
		pubYear = stoi(book.substr(0, index));
		book.erase(0, index + 1);

		index = book.find('\n');
		desc = book.substr(0, index);
		book.erase(0, index + 1);
		if (desc[0] == ' ')
			desc.erase(0, 1);

	}

	ostream& operator<<(ostream& os, Book& b) {

		os << setw(20) << setfill(' ') <<b.author<<" | ";
		os<< setw(22) << setfill(' ') << b.Btitle << " | ";
		os<< setw(5) << setfill(' ') << b.publicationcountry << " | ";
		os<< setw(4) << setfill(' ')  << b.pubYear << " | ";
		os<< setw(6) << setfill(' ') <<setprecision(2)<< fixed<<b.Bprice << " | ";
		os<< b.desc<<endl;
		return os;
	}

	Book& Book::operator=(Book& book) {
		author = book.author;
		Btitle = book.Btitle;
		publicationcountry = book.publicationcountry;
		pubYear = book.pubYear;
		Bprice = book.Bprice;
		desc = book.desc;

		return *this;
	}


}