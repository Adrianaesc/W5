#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>

using namespace std;
namespace sdds {

	class SpellChecker {

		string m_badWords[6];
		string m_goodWords[6];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;

	};

}


#endif