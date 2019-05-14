//representing integers as lists
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

namespace intAsList {
	
	struct intNode {
		int digit;
		intNode * next;
	};

	//alias for new int type
	using extendedInt = intNode * ;


	//least significant digit first
	extendedInt intToList(int input) {

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

	void deleteInt(extendedInt & myInt) {
		intNode * itr, *next;
		itr = myInt;
		while (itr != nullptr) {
			next = itr->next;
			delete itr;
			itr = next;
		}
		myInt = nullptr;
	}

	extendedInt add(const extendedInt integer1, const extendedInt integer2) {
		if (integer1 == nullptr || integer2 == nullptr) {
			std::cerr << "error empty pointer passed as argument";
			return nullptr;
		}

		extendedInt newInteger = new intNode;

		//processing the head
		intNode *itr1(integer1), *itr2(integer2), *itrNew(newInteger);
		int carry = 0;
		int digit1, digit2;

		digit1 = itr1 ? itr1->digit : 0;
		digit2 = itr2 ? itr2->digit : 0;
		itrNew->digit = (digit1 + digit2 + carry) % 10;
		carry = (digit1 + digit2 + carry) / 10;

		itr1 = itr1 ? itr1->next : nullptr;
		itr2 = itr2 ? itr2->next : nullptr;


		//main part
		while (itr1 != nullptr || itr2 != nullptr || carry != 0) {
			itrNew->next = new intNode;
			itrNew = itrNew->next;

			digit1 = itr1 ? itr1->digit : 0;
			digit2 = itr2 ? itr2->digit : 0;
			itrNew->digit = (digit1 + digit2 + carry) % 10;
			carry = (digit1 + digit2 + carry) / 10;

			itr1 = itr1 ? itr1->next : nullptr;
			itr2 = itr2 ? itr2->next : nullptr;
		}


		itrNew->next = nullptr;

		return newInteger;

	}

}

using namespace intAsList;

int main() {

	//test int to list
	extendedInt myInt, myInt2;
	myInt = intToList(255);
	printExtendedInt(myInt);
	
	//test add
	myInt2 = intToList(1855);
	printExtendedInt(myInt2);
	extendedInt myInt3 = add(myInt, nullptr);
	printExtendedInt(myInt3);

	deleteInt(myInt);
	deleteInt(myInt2);
	deleteInt(myInt3);

	return 0;
}
