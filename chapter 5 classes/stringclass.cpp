#include<iostream>
#include<algorithm> // min,

using std::cin;
using std::cout;
using std::endl;
using std::min;

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
	char operator[] (int pos) const;
	void remove(const int pos, const int removeLength);

		friend std::ostream& operator << (std::ostream& ostream, const String& string);

	private:
		char * _str;
		void clearString();
		bool isValidString(const char * cString) const;
		int cStringLength(const char * cString) const;
		char* getcString() const;
		int length() const;
		
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

	//test append
	myString2.append('X');
	cout <<"append X to str2* " << myString2 << endl;

	//test remove
	cout << "\nremove test*" << endl;
	cout << "test invalid argumetn pos less then 0: ";
	try {
		myString2.remove(-1, 6);
	}
	catch (char * e) {
		cout << e << endl;
	}
	cout << "test invalid argumetn length less then 0: ";
	try {
		myString2.remove(6, -4);
	}
	catch (char * e) {
		cout << e << endl;
	}
	cout << "test invalid argumetn pos excceds string length: ";
	try {
		myString2.remove(40, 6);
	}
	catch (char * e) {
		cout << e << endl;
	}
	cout << "test remove 3 from pos 4: ";
	myString2.remove(4, 3); 
	cout << myString2 << endl;

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

char String::operator[] (int pos) const{
	return this->characterAt(pos);
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

int String::length() const {
	return cStringLength(_str);
}
void String::append(const char c) {
	if (c == NULL)
		return;

	int stringLength = this->length();

	char * newString = new char[stringLength + 2];
	for (int i = 0; i < stringLength; ++i) {
		newString[i] = this->characterAt(i);
	}
	newString[stringLength] = c;
	newString[stringLength + 1] = NULL;
	delete[] _str;
	_str = newString;
}

void String::remove(const int pos, const int removeLength) {
	//input validation
	int oldLength = this->length();
	if (pos < 0 || removeLength < 0 || pos >= oldLength) { //non negative integers, pos does not exceed string length
		throw "Error invalid arguments";
		return;
	}
	
	/*
	int newLength = (pos + removeLength >= oldLength) ? pos : oldLength - removeLength;
	
	char * newStr = new char[newLength + 1];
	for (int i = 0; i < pos; ++i) {
		newStr[i] = (*this)[i];
	}

	for (int i = pos; i < newLength; ++i) {
		newStr[i] = (*this)[i + removeLength]; 
	}
	newStr[newLength] = NULL;

	delete[] _str;
	_str = newStr;
	*/
	if (pos + removeLength >= oldLength) {
		_str[pos] = NULL;
	}
	else {
		int i = -1;
		do {
			++i;
			_str[pos + i] = _str[pos + removeLength + i];
		} while (_str[i] != NULL);
	}
}