//// Workshop 5 - Functions and Error Handling
//// 2020/02 - Cornel
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <iomanip>
//#include<array>
//#include <fstream>
//#include <string>
//#include "Book.h"
//#include "Book.h"
//
//using namespace sdds;
//
//// ws books.txt
//int main(int argc, char** argv)
//{
//	std::cout << "Command Line:\n";
//	std::cout << "--------------------------\n";
//	for (int i = 0; i < argc; i++)
//		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
//	std::cout << "--------------------------\n\n";
//
//	// get the books
//	sdds::Book library[7];
//	{
//		// TODO: load the collection of books from the file "argv[1]".
//		//       - read one line at a time, and pass it to the Book constructor
//		//       - store each book read into the array "library"
//		//       - lines that start with "#" are considered comments and should be ignored
//		std::ifstream ifs(argv[1]);
//		string line="";
//		//ifs.open(argv[1]);
//		//cout << argv[1] << endl;
//		//cout << strerror(errno);
//		if (ifs.is_open()) {
//			for (int i = 0; i < 9; i++) {
//				getline(ifs, line);
//				if (line[0] != '#') {
//					for(int j = 0; j < 9; j++) {
//						if (library[j].title() == "") {
//							library[j] = Book{ line };
//							break;
//						}
//					}
//				}
//			}
//
//		}
//	}
//
//	double usdToCadRate = 1.3;
//	double gbpToCadRate = 1.5;
//
//	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
//	//       - the expression should receive a single parameter of type "Book&"
//	//       - if the book was published in US, multiply the price with "usdToCadRate"
//	//            and save the new price in the book object
//	//       - if the book was published in UK between 1990 and 1999 (inclussive),
//	//            multiply the price with "gbpToCadRate" and save the new price in the book object
//
//	auto lam = [usdToCadRate, gbpToCadRate](Book &b) {
//		string uk = " UK ";
//		string us = " US ";
//		string uk2 = "UK ";
//		//cout <<"|"<< b.country() << "|" << endl;
//		//double temp=0;
//		//cout << b.country() << endl;
//		//cout << b.year() << endl;
//		if (b.country().compare(us)==0) { 
//			 b.price() *= usdToCadRate; 
//		} else if (b.country().compare(uk)==0 && b.year() >= 1990 && b.year() <= 1999) {
//			//cout << b.price() << endl;
//			b.price() *= gbpToCadRate;
//			// cout << b.price() << endl;
//		}else if(b.country().compare(uk2) == 0 && b.year() >= 1990 && b.year() <= 1999)
//			b.price() *= gbpToCadRate;
//
//	};
//	//publicationcountry.erase(remove(publicationcountry.begin(), publicationcountry.end(), ' '), publicationcountry.end());
//
//
//
//	std::cout << "-----------------------------------------\n";
//	std::cout << "The library content\n";
//	std::cout << "-----------------------------------------\n";
//	for (int i=0;i< 7;i++)
//		std::cout << library[i];
//	std::cout << "-----------------------------------------\n\n";
//
//	// TODO: iterate over the library and update the price of each book
//	//         using the lambda defined above.
//
//	for (auto& book : library)
//		lam(book);
//
//
//	std::cout << "-----------------------------------------\n";
//	std::cout << "The library content (updated prices)\n";
//	std::cout << "-----------------------------------------\n";
//	for (auto& book : library)
//		std::cout << book;
//	std::cout << "-----------------------------------------\n";
//
//	return 0;
//}
