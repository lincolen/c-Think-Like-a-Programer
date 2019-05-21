#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class String {
	public:	
		String();
		String(const char *); //construct string from cString
		String(const String &); // copy constructor
		~String();
		String& operator= (String & rhs); //copy assignment
		char characterAt(const int position) const; //return charcter at passed poition, if position is invalid (pos < 0) throws an error, if position excceds string length return null
		void concatenate(const String& str2);
		void append(const char c);

		friend std::ostream& operator << (std::ostream& ostream, const String& string);

	private:
		char * _str;
		void clearString();
		bool isValidString(const char * cString) const;
		int cStringLength(const char * cString) const;
		char* getcString() const;
		
};

int main(){
	//test defult constructor 
	String * myString = new String();
	cout << "out put empty string: " << *myString << endl;
	delete myString;

	//test cString constructor
	myString =new String("hello world");
	cout << *myString << endl;

	//test copy constructor
	String myString2 = *myString;
	cout << myString2 << endl;

	//test charchter at
	try {
		cout <<"charchter at -3: " << myString2.characterAt(-3) << endl;
	}
	catch (const char * e){
		cout << e << endl;
	}
	cout << "charchter at 3: " << myString2.characterAt(3) << endl;
	cout << "charchter at 100: " << myString2.characterAt(100) << endl;

	//test copy assignment
	delete myString;
	myString = new String("copy this!");
	myString2 = *myString;
	cout << "copied string: " << myString2 << endl;

	//test concecrate
	myString2.concatenate(myString2);
	cout <<"concaracte with itself: " << myString2 << endl;

	delete myString;
}

std::ostream& operator<< (std::ostream& ostream,const String& string) {
	ostream << (string.getcString());
	return ostream;
}
String::String() {
	_str = new char[1];
	_str[0] = NULL;
}

String::~String() {
	delete _str;
	//cout << "this is the destructor" << endl;
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
int String::cStringLength(const char * cString) const {
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

String::String(const String& origin) : String(origin.getcString()) {
}

char String::characterAt(const int pos) const {
	//input validation
	if (pos < 0) {
		throw "invalid position passed as argument";
		return NULL;
	}

	const int strLength = cStringLength(_str);
	//pos exeeds string range
	if (pos >= strLength) {
	//	throw "position excceds string length";
		return NULL;
	}
	else {
		return _str[pos];
	}
}

String& String::operator = (String & rhs) {
	if (this == &rhs)
		return *this;

	delete _str;
	const char * cString = rhs.getcString();
	int length = cStringLength(cString);
	_str = new char[length + 1];
	for (int i = 0; i < length + 2; ++i) {
		_str[i] = cString[i];
	}

	return *this;
};

void String::concatenate(const String& str2) {
	const int str1Length = cStringLength(this->getcString());
	const int str2Length = cStringLength(str2.getcString());
	const int newStrLength = str1Length + str2Length;
	char * newStr = new char[str1Length + str2Length + 1];
	for (int i = 0; i < str1Length; ++i) {
		newStr[i] = this->characterAt(i);
	}
	for (int i = 0; i < str2Length; ++i) {
		newStr[str1Length + i] = str2.characterAt(i);
	}
	newStr[newStrLength] = NULL;

	delete[] _str;
	_str = newStr;
}