#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>

using namespace std;
namespace sdds {

	class Book {
		string author;
		string Btitle;
		string publicationcountry;
		size_t pubYear;
		double Bprice;
		string desc;

	public:
		Book();
		const std::string& title()const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		Book& operator=(Book& book);

		friend ostream& operator<<(ostream& os, Book& b);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(desc);
		}
	};

}

#endif