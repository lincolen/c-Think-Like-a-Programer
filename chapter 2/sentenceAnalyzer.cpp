#include<iostream>
#include<string>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;


bool isVowel(const char c) {
	static const char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'U' , 'I', 'O' };
	int size = sizeof(vowels) / sizeof(char);
	for (int i = 0;  i < size ; ++i) {
		if (c == vowels[i]) return true;
	}
	return false;
}

int main() {
	std::string word;
	 int maximumVowels = 0;
	 int longestWord = 0;
	 int numOfWords = 0;
	
	do {
		cin >> word;
		int vowels = 0;
		int wordLength = 0;

		for (std::string::iterator it = word.begin(); it != word.end(); ++it) {
			++wordLength;
			if (isVowel(*it)) vowels++;
		}
		++numOfWords;
		longestWord = std::max(longestWord, wordLength);
		maximumVowels = std::max(maximumVowels, vowels);
	} while (cin.get() != 10);
	cout << "Number of words: " << numOfWords << '\n';
	cout << "Longest word: " << longestWord << '\n';
	cout << "Most vowels in a word: " << maximumVowels << '\n';
}