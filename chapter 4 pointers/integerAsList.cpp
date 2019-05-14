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

extendedInt add(const extendedInt integer1, const extendedInt integer2) {
	if (integer1 == nullptr || integer2 == nullptr) {
		std::cerr << "empty pointer passed as argument";
		return nullptr;
	}

	extendedInt newInteger = new intNode;

	intNode *itr1(integer1), *itr2(integer2), *itrNew(newInteger);
	int carry = 0;
	int digit1, digit2;
	digit1 = itr1 ? itr1->digit : 0;
	digit2 = itr2 ? itr2->digit : 0;
	itrNew->digit = (digit1 + digit2 + carry) % 10;
	carry = (digit1 + digit2 + carry) / 10;
	
	while (itr1->next != nullptr || itr2->next != nullptr || carry != 0) {
		itr1 = itr1 ? itr1->next : nullptr;
		itr2 = itr2 ? itr2->next : nullptr;
		itrNew->next = new intNode;
		itrNew = itrNew->next;
		itrNew->next = nullptr;


		digit1 = itr1 ? itr1->digit : 0;
		digit2 = itr2 ? itr2->digit : 0;
		itrNew->digit = (digit1 + digit2 + carry) % 10;
		carry = (digit1 + digit2 + carry) / 10;
		cout << newInteger << endl;
	}

	cout <<  "asdasdasd" << endl;
	printExtendedInt(newInteger);
	itrNew->next = nullptr;
	
	return newInteger;
	
}



int main(){
	extendedInt myInt, myInt2;
	myInt = intToList(255);
	
	
	printExtendedInt(myInt);
	cout << (myInt ? true : false) << endl;
	myInt2 = intToList(1000);
	printExtendedInt(myInt2);

	extendedInt myInt3 = add(myInt, myInt2);
	printExtendedInt(myInt3);
	cout << "yabadaba";
}