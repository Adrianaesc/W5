#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <iomanip>
#include "Movie.h"

using namespace std;
namespace sdds{

	Movie::Movie() {
		m_title="";
		year=0;
		desc="";
	}


	const string& Movie::title()const {
	//	cout << m_title << endl;
		return m_title;
	}

	Movie::Movie(const string& strMovie) {
		string mov=strMovie;
		int index = 0;

		index = mov.find(",");
		m_title = mov.substr(0, index);
		mov.erase(0, index +1);
		if (m_title[0] == ' ')
			m_title.erase(0, 1);
		if (m_title[m_title.length() - 1]==' ')
		m_title.erase(m_title.length() - 1, 1);
		if (m_title[m_title.length() - 1] == ' ')
		m_title.erase(m_title.length() - 1, 1);
		if (m_title[m_title.length() - 1] == ' ')
			m_title.erase(m_title.length() - 1, 1);

		index = mov.find(",");
		year = stoi(mov.substr(0,index));
		mov.erase(0, index+1);


		index = mov.find('.');
		desc = mov.substr(0, index+1);
		desc = regex_replace(desc, regex("^ +"), " ");
		if (desc[0] == ' ')
			desc.erase(0, 1);
		if (m_title[0] == ' ')
			m_title.erase(0, 1);
		if (desc[desc.length() - 1], 1);
		desc.erase(desc.length() - 1, 1);



	}

	ostream& operator<<(ostream &os,const Movie& m) {
		os << setw(40) << setfill(' ')<<m.m_title<<" | ";
		os << setw(4) << setfill(' ') << m.year << " | ";
		os << m.desc <<"."<< endl;

		return os;

	}

}