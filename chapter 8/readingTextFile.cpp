#include<iostream>
#include<string>
#include<list>
#include<fstream> 
#include<cstdlib> //exit(), EXIT_FAILURE
#include<algorithm> //foreach)()


using std::cin;
using std::cout;
using std::endl;

int main(){
	std::ifstream myFile;
	myFile.open("words.txt");
	if (!myFile.is_open()) {
		std::cerr << "text file not found" << endl;
		exit(EXIT_FAILURE);
	}

	std::list<std::string> wordList;
	std::string word;

	while (myFile >> word) {
		wordList.push_front(word);
	}

	std::for_each(wordList.begin(), wordList.end(), [](std::string str) {cout << str << endl;});
	cout << "number of words in list: " << wordList.size() << endl;

	myFile.close();
}