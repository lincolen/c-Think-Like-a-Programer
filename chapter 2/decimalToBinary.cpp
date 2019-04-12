#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int decimalNumber;
	std::string buffer = "";
	cout << "enter a decimal number to convert to binary: " << endl;
	cin >> decimalNumber;
	//assert a postive integer in the int range 
	cout << "the binary number is: ";
	{
		int reminder;
		int factor;
		do {
			factor = decimalNumber / 2;
			reminder = decimalNumber % 2;

			buffer += reminder + '0';

			decimalNumber = factor;
		} while (decimalNumber != 0);
	}

	for (std::string::reverse_iterator ri = buffer.rbegin(); ri != buffer.rend(); ++ri) {
		cout << *ri;
	}
	cout << '\n';

	cout << endl;
}