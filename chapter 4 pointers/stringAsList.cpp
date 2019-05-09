//implements strings as lists rather then null terminated arrays
#include<iostream>

using std::cout;
using std::endl;

struct charNode {
	char c;
	charNode * next;
};

using String = charNode * ;



void append(String &string, const char c) {
	if (string == nullptr) {
		string = new charNode;
		string->c = c;
		string->next = nullptr;
		return;
	}
	charNode * node = string;
	while (node->next != nullptr) {
		node = node->next;
	}

	node->next = new charNode;
	node = node->next;
	node->c = c;
	node->next = nullptr;	
}

char characterAt(String string, int position) {
	charNode * node = string;
	for (int i = 0; i <= position; ++i) {
		if (node == nullptr) {
			cout << "error position exceeds string length" << endl;
			return 0;
		}
		node = node->next;
	}
	return node->c;
}

void printString(String string) {
	while (string != nullptr) {
		cout << string->c;
		string = string->next;
	}
	cout << endl;
}

void deleteString(const String str) {
	charNode * itr, next;
	next = str;
	while (next != nullptr) {
		itr = next;
		next = itr->next;
		delete itr;
	}
}

String concatenate(const String str1, const String str2) {
	//assume proper formated strings
	
	String newStr = nullptr;
	charNode * itr1, itr2;
	//check for empty pointers
	try {
		if (str1 == nullptr || str2 == nullptr) throw "argument dosent point to anything";
	}
	catch(char * e){
		std::cerr << e << endl;
		return newStr;
	}




	
}

int main() {

	String str = nullptr;
	
	//checking print string and append
	printString(str);
	append(str, 'a');
	append(str, 'b');
	append(str, 'c');
	printString(str);

	//checking characterAt
	cout << characterAt(str, 2) << endl;
	cout << characterAt(str, 3) << endl;
}