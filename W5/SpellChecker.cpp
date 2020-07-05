#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "SpellChecker.h"

using namespace std;
namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		//cout << strerror(errno);
		if (!file.is_open()) {
				throw "Bad file name!";
			
		}
		else {
			
			//if (file.is_open()) {
				string line[6];
				size_t index=0;
				for (int i = 0; i < 5; i++) {
					getline(file, line[i]);

					index = line[i].find(' ');
					m_badWords[i]=line[i].substr(0,index);
					if (m_badWords[i][0] == ' ')
						m_badWords[i].erase(0, 1);
					if (m_badWords[i][m_badWords[i].length()-1] == ' ')
						m_badWords[i].erase(m_badWords[i].length() - 1, 1);
					//cout << m_badWords[i] <<"|"<< endl;
					line[i].erase(0, index);

					line[i] = regex_replace(line[i], regex("^ +"), " ");
					m_goodWords[i] = line[i];
					if (m_goodWords[i][0] == ' ')
						m_goodWords[i].erase(0, 1);
					if (m_goodWords[i][m_goodWords[i].length() - 1] == ' ')
						m_goodWords[i].erase(m_goodWords[i].length() - 1, 1);
					//cout << m_goodWords[i] <<"|"<< endl;;

				}
			}
		

	}

	void SpellChecker::operator()(std::string& text) const {
		int index = 0;
		for (int i = 0; i < 5; i++) {
			index = text.find(m_badWords[i]);
			if (index>=0)
			text.replace(index ,m_badWords[i].length() ,m_goodWords[i]);
			index = text.find(m_badWords[i]);
			if (index >= 0)
				text.replace(index, m_badWords[i].length(), m_goodWords[i]);
		}
	}


}