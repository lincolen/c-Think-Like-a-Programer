#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using integer = unsigned int;

integer inputMode =16, outputMode = 16;

char decimaltoChar(const integer decimalValue) {
	//assert decimal >= 0 && decimal < inputmode
	if (decimalValue <= 9) return '0' + decimalValue;
    return 'a' + decimalValue - 10;
}

integer charToDecimal(const char digit) {
	if (digit <= '9' && digit >= '0') {
		return  (digit - '0');
	}
	return 10 + digit - 'a';
}

integer toDecimal(std::string string) {
	//assert charchters in string are between in the range of inputMode
	integer DecimalNumber = 0;
	for(std::string::iterator it = string.begin(); it != string.end(); ++it){

		DecimalNumber *= inputMode;
		DecimalNumber += charToDecimal(*it);
	}
	return DecimalNumber;
}

std::string fromDecimal(integer decimalValue) {
	//assert decimal number is positive
	std::string buffer = "";
	
	integer reminder;
	integer factor;
	do {
		factor = decimalValue / outputMode;
		reminder = decimalValue % outputMode;
		buffer += decimaltoChar(reminder);
		decimalValue = factor;
	} while (decimalValue != 0);

	std::string newValue = "";
	for (std::string::reverse_iterator ri = buffer.rbegin(); ri != buffer.rend(); ++ri) {
		newValue += *ri;
	}
	return newValue;
}

int main() {
	do {
		cout << "Enter input base from 2 to 16 " << endl;
		cin >> inputMode;
	} while (inputMode < 2 || inputMode > 16);

	do {
		cout << "Enter output base from 2 to 16 " << endl;
		cin >> outputMode;
	} while (outputMode < 2 || outputMode > 16);
	
	cout << "enter value in base " << inputMode << " to be converted to base " << outputMode << endl;
	std::string str;
	cin >> str;
	
	cout << fromDecimal(toDecimal(str));
}