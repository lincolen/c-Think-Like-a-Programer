#include<iostream>

using namespace std;

int main() {}

bool iterativeOddParity(const bool * array, const int size) {
	bool parity = false;
	for (int i = 0; i < size; ++i) {
		if (array[i]) {
			parity = !parity;
		}
	}
	return parity;
}

bool recursiveOddParity(const bool * array, const int size) {
	if (size == 0)
		return false;

	return (array[size - 1]) ? !recursiveOddParity(array, size -1) : recursiveOddParity(array, size - 1)
}