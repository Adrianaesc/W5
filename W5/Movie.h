#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>

using namespace std;
namespace sdds {

	class Movie {

		string m_title;
		int year;
		string desc;

	public:

		Movie();
		const string& title()const;
		Movie(const string& strMovie);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(desc);
		}

		friend ostream& operator<<(ostream& os,const Movie& m);

	};

}

#endif