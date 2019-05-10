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

char characterAt(const String string,const int position) {
	charNode * node = string;
	if (string == nullptr) {
		cout << "error empty string";
		return NULL;
	}

	for (int i = 0; i < position; ++i) {
		if (node->next == nullptr) {
			cout << "error position exceeds string length" << endl;
			return 0;
		}
		
		node = node->next;
		//cout << node->c;
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
	charNode * itr,* next;
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
	charNode * itr1, * itr2;
	//check for empty pointers
	/*
	try {
		if (str1 == nullptr || str2 == nullptr) throw "arguments dosent point to anything";
	}
	catch(char * e){
		std::cerr << e << endl;
		return newStr;
	}
	*/
	
	//copy str1 contents
	if (str1 != nullptr) {
		newStr = new charNode;
		itr1 = newStr;
		itr2 = str1;

		itr1->c = itr2->c;
		while (itr2->next != nullptr) {
			itr2 = itr2->next;
			itr1->next = new charNode;
			itr1 = itr1->next;

			itr1->c = itr2->c;
		}
		itr1->next = nullptr;
	}

	//copy str2 contents
	if (str2 != nullptr) {
		//in case str1 was empty
		if (newStr == nullptr) {
			newStr = new charNode;
			itr1 = newStr;
		}
		//in case str1 was not empty
		else {
			itr1->next = new charNode;
			itr1 = itr1->next;
		}

		itr2 = str2;
		itr1->c = itr2->c;

		while (itr2->next != nullptr) {
			itr2 = itr2->next;
			itr1->next = new charNode;
			itr1 = itr1->next;

			itr1->c = itr2->c;
		}
		itr1->next = nullptr;
	}
	return newStr;
}

void removeChars(String & str, const int pos, const int length) {
	charNode * cutoff, *itr, * next;
	
	//empty string
	if (str == nullptr) {
		return;
	}

	//if removeing from the begining
	if (pos == 0) {
		itr = str;
		next = itr;
		for (int i = 0; i < length; ++i) {
			itr = next;
			next = itr->next;
			delete itr;
			if (next == nullptr) {
				str = nullptr;
				return;
			}
			
		}
		str = next;
		return;
	}

	//set cutoff
	cutoff = str;
	for (int i = 0; i < pos - 1; ++i) {
		if (cutoff->next == nullptr) return;
		cutoff = cutoff->next;
	}
	itr = cutoff;
	next = itr->next;
	for (int i = 0; i < length; ++i) {
		itr = next;
		next = itr->next;
		delete itr;
		if (next == nullptr) {
			cutoff->next = nullptr;
			return;
		}		
	}
	cutoff->next = next;
	return;

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

	//cheaking concatenate
	String str2 = nullptr;
	printString(str2);

	str2 = concatenate(nullptr, nullptr);
	printString(str2);
	deleteString(str2);

	str2 = concatenate(str, nullptr);
	printString(str2);
	deleteString(str2);

	str2 = concatenate(nullptr, str);
	printString(str2);
	deleteString(str2);

	str2 = concatenate(str, str);
	printString(str2);

	//check remove chars
	removeChars(str2, 3, 10);
	printString(str2);

	deleteString(str);
	deleteString(str2);
}