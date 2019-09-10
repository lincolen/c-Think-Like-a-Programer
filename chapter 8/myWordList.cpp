//word list class for hangman cheater program
#include<iostream>
#include<string>
#include<list>
#include<fstream> 
#include<assert.h> //assert 
#include<algorithm> //foreach)()
#include<cassert>

using std::cout;
using std::endl;

class MyWordList {
	public:
		MyWordList();
		MyWordList(const std::string fileName); //construct from file
		MyWordList & getWordsFromFile(const std::string fileName);
		void printList() const;
		int countWordsWithoutLetter(const char letter) const;
		MyWordList & removeWordOfWrongLength(const int length);

	private:
		std::list<std::string> wordList;
};

int main() {
	MyWordList wordList("words.txt");

	cout << "\nlength of list " << wordList.countWordsWithoutLetter('7') << endl;
	cout << "number of words without the letter 'a' " << wordList.countWordsWithoutLetter('a') << endl;

	cout << "\nmaintain only words that have three letters " << endl;
	wordList.removeWordOfWrongLength(3).printList();
	cout << "\nlength of list " << wordList.countWordsWithoutLetter('7') << endl;
}

MyWordList::MyWordList(const std::string fileName) {
	this->getWordsFromFile(fileName);
}

MyWordList & MyWordList::getWordsFromFile(const std::string fileName) {
	std::ifstream file;
	file.open(fileName);

	assert("file is found" && file.is_open());
	file.clear();

	std::string word;

	while (file >> word) {
		this->wordList.push_front(word);
	}

	file.close();
	return *this;
}

void MyWordList::printList() const {
	cout << "number of words in list: " << wordList.size() << endl;
	std::for_each(this->wordList.begin(), this->wordList.end(), [](const std::string & str) {cout << str << endl;});
}

int MyWordList::countWordsWithoutLetter(const char letter) const {
	return std::count_if(this->wordList.begin(), this->wordList.end(), [letter](const std::string & str) {return str.find(letter) == std::string::npos;});
}

//remove all words from the list that have a diffrent number of letters then indicated by the argument
MyWordList & MyWordList::removeWordOfWrongLength(const int length) {
	assert("argument is non negtive" && length >= 0);
	std::list<std::string>::iterator itr = this->wordList.begin(); 
	while(itr != this->wordList.end()) {
		if (itr->length() != length) {
			itr = this->wordList.erase(itr);
		}
		else {
			++itr;
		}
	}
	return *this;
}
