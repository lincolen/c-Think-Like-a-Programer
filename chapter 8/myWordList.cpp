//word list class for hangman cheater program
#include<iostream>
#include<string>
#include<list>
#include<fstream> 
#include<assert.h> //assert 
#include<algorithm> //foreach)()

using std::cout;
using std::endl;

class MyWordList {
	public:
		MyWordList();
		MyWordList(const std::string fileName); //construct from file
		MyWordList & getWordsFromFile(const std::string fileName);
		void printList() const;

	private:
		std::list<std::string> wordList;
};

int main() {
	MyWordList wordList("words.txt");
	wordList.printList();
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
	std::for_each(this->wordList.begin(), this->wordList.end(), [](std::string str) {cout << str << endl;});
}
