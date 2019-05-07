#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class MyString {
	private:
		char * str;

	public:
		//empty intilization
		MyString() {
			str = new char[1];
			str[0] = 0;
		}

		//destrucotr
		~MyString() {
			delete[] str;
		}

		//access like array
		char operator [](const int pos) const {
			if (pos > str[0] + 1) return NULL;
			return str[pos];
		}

		//copy initialize
		MyString(const MyString & fromString) {
			const int length = fromString[0];
			str = new char[length + 1];
			str[0] = length;
			for (int i = 1; i <= length; ++i) {
				str[i] = fromString[i];
			}
		}

		//copy assignment
		MyString& operator =(const MyString & fromString) {
			if (this == &fromString) {
				return *this;
			}
			
			delete[]  str;
			int length = fromString[0];
			str = new char[length + 1];
			str[0] = length;
			for (int i = 1;  i <= length; ++i) {
				str[i] = fromString[i];
			}
			return *this;
		}

		//print the contents of the string
		void print() const{
			const int length = str[0];
			for (int i = 1; i <= length; ++i) {
				cout << str[i];
			}
		};

		MyString& append(const char c) {
			const int length = str[0];
			char * temp = new char[length + 2];
			temp[0] = length + 1;
			for (int i = 1; i <= length; ++i) {
				temp[i] = str[i];
			}
			temp[length + 1] = c;
			delete[] str;
			str = temp;

			return *this;
		}

		//lets concatenate create a new string object more effiently
		friend MyString concatenate(const MyString & str1, const MyString & str2);

};

std::ostream& operator <<(std::ostream& ostream, const MyString & string) {
	string.print();
	return ostream;
}

MyString concatenate(const MyString & str1, const MyString & str2) {
	const int length1 = str1[0];
	const int length2 = str2[0];
	MyString newStr;
	delete[] newStr.str;
	newStr.str = new char[length1 + length2 + 1];
	newStr.str[0] = length1 + length2;
	for (int i = 1; i <= length1; ++i) {
		newStr.str[i] = str1[i];
		
	}
	for (int i = 1; i <= length2; ++i) {
		newStr.str[ length1 + i] = str2[i];
		
	}

	cout << newStr << endl;
	return newStr;
};

int main() {
	MyString str, str2;
	cout << str << endl;
	str.append('A');
	cout << str << endl;
	str2 = str;
	cout << str2 << endl;
	str = concatenate(str, str2);
	cout << str << endl;
}