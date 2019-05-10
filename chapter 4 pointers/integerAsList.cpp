//representing integers as lists
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

struct intNode {
	int digit;
	intNode * next;
};

using extendedInt = intNode * ;


//least significant it first
extendedInt intToList(int input){
	
	extendedInt newInt = nullptr;
	intNode * node;

	if (input < 0) {
		std::cerr << "input is negetive" << endl;
		return newInt;
	}

	node = new intNode;
	newInt = node;
	node->digit = input % 10;
	input /= 10;
	while (input != 0) {
		node->next = new intNode;
		node = node->next;
		node->digit = input % 10;
		input /= 10;
	}
	node->next = nullptr;
	return newInt;

}

void printExtendedInt(const extendedInt intger) {
	intNode * itr;
	itr = intger;
	while (itr != nullptr) {
		cout << itr->digit;
		itr = itr->next;
	}
	cout << endl;
}

void deleteInt(const extendedInt myInt) {
	intNode * itr, *next;
	itr = myInt;
	while (itr != nullptr) {
		next = itr->next;
		delete itr;
		itr = next;
	}
}

int main(){
	extendedInt myInt;
	myInt = intToList(255);
	cout << "hello" << endl;
	printExtendedInt(myInt);
}