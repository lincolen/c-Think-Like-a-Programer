#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class String {
	public:	
		String();
		String(const char *);
		//String(const String *);
		//~String();
		String & operator = (String & rhs);
		char characterAt(const int position);
		void concatenate(const String& str2);
		void append(const char c);

		friend std::ostream& operator << (std::ostream& ostream, const String& string);

	private:
		char * _str;
		void clearString();
		bool isValidString(const char * cString) const;
		int cStringLength(const char * cString);
		char* getcString() const;
};

int main(){
	String myString = "hello world";
	cout << myString;
}

std::ostream& operator<< (std::ostream& ostream,const String& string) {
	ostream << (string.getcString());
	return ostream;
}
String::String() {
	_str = new char[1];
	_str[0] = NULL;
}

char* String::getcString() const{
	return _str;
}

bool String::isValidString(const char * cString) const{
	if (cString != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//return length as number of charchters in the string nor includeing null
int String::cStringLength(const char * cString) {
	//data validation
	if (!isValidString(cString)) {
		throw("Error empty pointer passed as argument");
		return -1;
	}

	int length = 0;
	while (cString[length] != NULL) {
		++length;
	}
	return length;
}


String::String(const char * cString) {
	//data validation and error handeling
	if (!isValidString(cString)) {
		throw("error empty pointer passed as initilazier argument");
		_str = "";
		return;
	}
	int length = cStringLength(cString);
	_str = new char[length + 1];
	for (int i = 0; i < length + 2; ++i) {
		_str[i] = cString[i];
	}
}