#include<iostream>

using std::cin;
using std::cout;
using std::endl;

using arrayString = char *;

char characterAt(const arrayString string, const int position) {
	return string[position];
}

int length(const arrayString &str) {
	int length = 0;
		while (str[length] != 0) {
			length++;
	}
	return length;
}

void append(arrayString &string, const char c) {
	int stringLength = length(string);


	arrayString newString = new char[stringLength + 2];
	for (int i = 0; i < stringLength; ++i) {
		newString[i] = string[i];
	}
	newString[stringLength] = c;
	newString[stringLength + 1] = 0;
	delete[] string;
	string = newString;
}

void concatenate(arrayString &str1, const arrayString &str2) {
	const int str1Length = length(str1);
	const int str2Length = length(str2);
	const int newStrLength = str1Length + str2Length;
	arrayString newStr = new char[str1Length + str2Length + 1];
	for (int i = 0; i < str1Length; ++i) {
		newStr[i] = str1[i];
	}
	for (int i = 0; i < str2Length; ++i) {
		newStr[str1Length + i] = str2[i];
	}
	newStr[newStrLength] = NULL;

	delete[] str1;
	str1 = newStr;

}

//caller is generly responisable for valied input, caller is responsible for memory deallocation 
arrayString substring(const arrayString str,const int position,const int length) {
	//assert a valid arrayString obejct is passed, position on length are within string range
	
	//check for ilegel start position, and empty 
	try {
		if (position < 0) 	throw("error start position is less then zero");
		if (str == nullptr) throw("error nullptr passed as argument");
			
	}catch (char * err) {
		std::cerr << err << endl;
		return nullptr;
	}

	//create substring
	arrayString substring = new char[length + 1];
	for (int i = 0; i < length; ++i) {
		substring[i] = str[position + i];
	}
	substring[length] = NULL;
	return substring;
}

void printString(const arrayString str) {
	int i = 0;
	while (str[i] != NULL) {
		cout << str[i];
		++i;
	}
	cout << endl;
}

//compares the contents of str1 in startPos to the contents of str2, input validation is mostly up to the caller
bool compareSubstring(const arrayString str1, const arrayString str2, const int startPos) {
	//assert str1 and str2 are valied arrayStrings, str2 is not an empty string, strartPos is within str1 range
	try {
		if (startPos < 0) 	throw("error start position is less then zero");
		if (str1 == nullptr || str2 == nullptr) throw("error nullptr passed as argument");
		if (str2[0] == 0) throw("error str2 is and empty string");
	}
	catch (char * err) {
		std::cerr << err << endl;
		return false;
	}

	int itr = 0;
	while (str2[itr] != NULL) {
		if (str1[startPos + itr] != str2[itr]) return false;
		++itr;
	}
	return true;
}

void replaceString(arrayString & str,const arrayString expression,const arrayString newExpression) {
	//assert str, expression, newExpression are valied strings, expression/newExpression is not an empty string
	try {
		if (str == nullptr || expression == nullptr || newExpression == nullptr) throw("error nullptr passed as argument");
		if (expression[0] == 0) throw("error expression is an empty string");
		if (newExpression[0] == 0) throw("error new expression is an empty string");
	}
	catch (char * err) {
		std::cerr << err << endl;
		return;
	}
	
	
	int expressionLength = 0;
	while (expression[expressionLength] != NULL) {
		++expressionLength;
	}

	arrayString newStr = new char[1];
	newStr[0] = NULL;

	int itr = 0;
	while (str[itr] != NULL) {
		if (compareSubstring(str, expression, itr)) {
			concatenate(newStr, newExpression);
			itr += expressionLength;
		}else {
			append(newStr, str[itr]);
			++itr;
		}
	}
	
	delete[] str;
	str = newStr;

}

int main() {
	//


	//initializing test array
	arrayString str = new char[1];
	str[0] = NULL;

	//checking append and printstring
	for (int i = 0; i < 6; ++i) {
		append(str, 'a' + i);
	}
	printString(str);

	//checking replaceString
	concatenate(str, "cd");
	replaceString(str, "cd", "xyz");
	printString(str);

	//checking substring, and substring input validation (this use causes a memory leak, but for this scale it should be fine)
	printString(substring(str, 2, 14));
	substring(nullptr, 0, 0);
	substring(str, -3, 4);
	delete[] str;
}
