#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	unsigned long int DecimalNumber = 0;
	char c;
	cout << "enter a binary number to convert to decimal" << endl;
	c = cin.get();
	while (c != '\n') {
		DecimalNumber *= 2;
		DecimalNumber += c - '0';

		c = cin.get();
	}

	cout << "the number in decimal is: " << DecimalNumber << endl;
}