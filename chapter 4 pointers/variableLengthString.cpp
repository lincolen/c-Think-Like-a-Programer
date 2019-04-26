#include<iostream>

using std::cin;
using std::cout;
using std::endl;

using arrayString = char *;

char characterAt(const arrayString string, const int position) {
	return string[position];
}

int length(const arrayString &arr) {
	int length = 0;
		while (arr[length] != 0) {
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
	newStr[newStrLength] = 0;

	delete[] str1;
	str1 = newStr;

}

int main() {

}
