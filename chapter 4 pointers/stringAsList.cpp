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