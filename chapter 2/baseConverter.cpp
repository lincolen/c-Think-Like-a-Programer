#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;

enum modes {DECIMAL, BINARY, HEXADECIMAL}
inputMode, outputMode;

int DigitHexaToDecimal(const char c) {
	if (c <= '9' && c >= '0') {
		return  (c - '0');
	}
	return 10 + c - 'a';
}

char DigitDecimalToHexa(const int decimal) {
	//assert decimal >= 0 && decimal <= 15
	if (decimal <= 9) return '0' + decimal;
	const int table[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	return table[decimal % 10];
}

int HexaToDecimal() {
	int buffer = 0;
	char hexaDigit = cin.get();
	while (hexaDigit != '\n') {
		buffer = buffer * 16 + DigitHexaToDecimal(hexaDigit);
		hexaDigit = cin.get();
	}	
	return buffer;
}

void DecimalToHexa(int decimalNumber) {
	int remainder = 0;
	int factor = 0;
	int bufferCount = 0;
	char buffer[20];
	do {
		remainder = decimalNumber % 16;
		factor = decimalNumber / 16;
		buffer[bufferCount] = DigitDecimalToHexa(remainder);
		++bufferCount;
		decimalNumber = factor;
	
	} while (decimalNumber != 0);

	for (--bufferCount; bufferCount >= 0; bufferCount--) {
		cout << buffer[bufferCount];
	}

}

int binaryToDecimal() {
	int DecimalNumber = 0;
	char c;
	
	c = cin.get();
	while (c != '\n') {
		DecimalNumber *= 2;
		DecimalNumber += c - '0';

		c = cin.get();
	}
	return DecimalNumber;
}

void decimalToBinary(int decimalNumber) {
	//assert decimal number is positive
	std::string buffer = ""; 
	int reminder;
	int factor;
	do {
		factor = decimalNumber / 2;
		reminder = decimalNumber % 2;
		buffer += DigitDecimalToHexa(reminder);
		decimalNumber = factor;
	} while (decimalNumber != 0);

	for (std::string::reverse_iterator ri = buffer.rbegin(); ri != buffer.rend(); ++ri) {
		cout << *ri;
	}
	cout << '\n';
	return;
}

void setInputMode() {
	char input;
	do {
		cout << "enter input base: (h)exa, (d)ecimal (b)inary " << endl;
		cin >> input;
		cin.ignore();
		switch (input) {
		case 'd':
			inputMode = DECIMAL;
			break;
		case 'b':
			inputMode = BINARY;
			break;
		case 'h':
			inputMode = HEXADECIMAL;
			break;
		default:
			cout << "unrecognized charchter entered " << endl;
		}
	} while (input != 'd' && input != 'h' && input != 'b');
}

void setOutputMode() {
	char output;
	do {
		cout << "enter output base: (h)exa, (d)ecimal (b)inary " << endl;
		cin >> output;
		cin.ignore();
		switch (output) {
		case 'd':
			outputMode = DECIMAL;
			break;
		case 'b':
			outputMode = BINARY;
			break;
		case 'h':
			outputMode = HEXADECIMAL;
			break;
		default:
			cout << "unrecognized charchter entered " << endl;
		}
	} while (output != 'd' && output != 'h' && output != 'b');
}



int main() {
	setInputMode();
	setOutputMode();

	cout << "entere value to be converted: " << endl;
	
	//assert inputed apropriate value
	int decimalValue;
	switch (inputMode){
		case DECIMAL:
			cin >> decimalValue;
			break;
		case BINARY:
			decimalValue = binaryToDecimal();
			break;
		case HEXADECIMAL:
			decimalValue = HexaToDecimal();
			break;
		default: 
			cout << "an error has ocurred " << endl;
	}

	switch (outputMode){
		case DECIMAL:
			cout << "the Decimal value is " << decimalValue << endl;
			break;
		case BINARY:
			cout << "The binary value is: ";
			decimalToBinary(decimalValue);
			break;
		case HEXADECIMAL:
			cout << "The hexa decimal value is: ";
			DecimalToHexa(decimalValue);
			break;
		default:
			cout << "an error has ocurred " << endl;
	}
	
}

