#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int digitCount = 0;
	int sum = 0;
	int digit;
	char c;

	cout << "enter a 12 digit number to find an ISBN13 checkusm digit" << endl;
	
	for (int i = 0; i < 12; i++) {
		c = cin.get();
		++digitCount;
		digit = c - '0';
		if (digitCount % 2 == 0)
			sum += 3 * digit;
		else
			sum += digit;
	}

	int checkDigit;
	checkDigit = 10 - (sum % 10);
	cout << "the check digit is: " << checkDigit << endl;

}