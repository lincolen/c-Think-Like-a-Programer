#include<iostream>

using std::cin;
using std::cout;
using std::endl;

enum modes {DECIMAL, BINARY, HEXADECIMAL}
inputMode, outputMode;

int DigitHexaToDecimal(const char c) {
	if (c <= '9') {
		return  (c - '0');
	}
	return 10 + c - 'a';
}

char DigitDecimalToHexa(const int decimal) {
	//assert decimal >= 0 && dcimal <= 15
	const int table[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	if (decimal <= 9) return '0' + decimal;
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
	unsigned long int DecimalNumber = 0;
	char c;
	
	c = cin.get();
	while (c != '\n') {
		DecimalNumber *= 2;
		DecimalNumber += c - '0';

		c = cin.get();
	}
	return DecimalNumber;
}


int main() {
	int decimal;
	cin >> decimal;
	DecimalToHexa(decimal);

}

