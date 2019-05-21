#include<iostream>
#include<string>
#include<cstdlib> // rand() , srand()
#include<ctime> // time()

using std::cin;
using std::cout;
using std::endl;




char cipher(const char & letter, const char cipherTable[26], const int & size) {
	
	if (letter > 'a') return cipherTable[(letter - 'a') % 26];
	return cipherTable[(letter - 'A') % 26];

}

char decipher(const char & letter ,  const char cipherTable[26], const int & size) {
	
	for (int i = 0; i < size; ++i) {
		if (letter == cipherTable[i]) return 'a' + i;
	}
	return '\0';
}

void randomizeCypher(char cipherTable[26], const int & size) {
	bool * isUsed = new bool[size];
	for (int i = 0; i < size; ++i) {
		isUsed[i] = false;
	}

	for (int i = 0; i < size; ++i) {
		int rand;
		srand(time(0));
		do {
			rand = std::rand() % 26;
			cipherTable[i] = 'A' + rand;
		} while (rand == i || isUsed[rand] == true);
		isUsed[rand] = true;
	}
	delete[] isUsed;
}

int main() {
	const int SIZE = 26;
	char cipherTable[SIZE] = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
	randomizeCypher(cipherTable, 26);
	std::string input;
	std::string code = "";
	cout << "eneter a simple messege to be cipherd" << endl;
	
	do {
		cin >> input;
		for (char letter : input) {
			code += cipher(letter, cipherTable, SIZE);
		}
		code += ' ';

	} while (cin.get() != 10);

	cout << " the coded messege is: " << code << endl;
	cout << "the decoded messege is: ";

	for (char letter : code) {
		if (letter == ' ') {
			cout << letter;
			continue;
		}
		cout << decipher(letter, cipherTable, SIZE);
	}

}