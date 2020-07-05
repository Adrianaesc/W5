#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <stdexcept>

using namespace std;
namespace sdds {

	template <typename T>
	class Collection {

		string m_name;
		T *arr;
		int m_size;
		void (*m_observer )(const Collection<T>& c, const T& cc);

	public:

		Collection(string n) {
			m_name = n;
			arr = nullptr;
			m_size = 0;
			m_observer = nullptr;
		};

		Collection(const Collection& c) {
			//nothing
		};

		Collection& operator=(const Collection& other) {
			//nothing
			return *this;
		};

		~Collection() {
			delete[] arr;
		};

		const string& name() const {
			return m_name;
		};

		size_t size()const {
			return (size_t)m_size;
		};

		void setObserver( void (*observer)(const Collection<T>& t, const T& c) ) {
			m_observer=observer;
		};
		
		Collection<T>& operator+=(const T& item) {
			int count = 0;
			if (m_size == 0) {
				arr = new T[1];
				m_size = 1;
				T t = item;
				arr[0] = t;
			}
			else {
				for (int i = 0; i < m_size; i++) {
					if (arr[i].title() == item.title()) {
						count++;
					}
					else if (arr[i].title() == "") {
						T t = item;
						arr[i] = t;
						m_size++;
					}
				}
				if (count == 0) {
					T* temp = new T[m_size];
					for (int i = 0; i < m_size; i++) {
							temp[i] = arr[i];
					}

					delete[] arr;
					arr = new T[m_size + 1];

					for (int i = 0; i < m_size; i++) {
							arr[i] = temp[i];
					}
					delete[] temp;
					T t = item;
					arr[m_size] = t;
					m_size++;

					if (m_observer != nullptr) {
						m_observer(*this, item);
					}
				}
			}
			return *this;
		};

		T& operator[](size_t idx)const {
			//T temp;
			
				if (idx >= (size_t)m_size) {

//					throw out_of_range("Bad index [" + m_size +"]. Collection has ["+m_size +"] items.");
					//throw out_of_range(s);
					string s = "";
					s+="Bad index [" + to_string(m_size);
					s += "]. Collection has [" + to_string(m_size);
					s+="] items.";
					throw out_of_range(s );

				}

			return arr[idx];
		};

		T* operator[](string ti)const {
			T *temp=nullptr;
			for (int i = 0; i < m_size; i++) {
				//cout << ti << endl;
				//cout << arr[i].title() << endl;
				if (arr[i].title() == ti) {
					temp = &arr[i];
				}
			}
			return temp;
		};


		friend ostream& operator<<(ostream& os, Collection& c) {
			for (int i = 0; i < c.m_size; i++) {
				os << c.arr[i];
			};
			return os;
		};

	};

};

#endif