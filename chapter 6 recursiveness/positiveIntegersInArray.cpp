#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

}

int iterativeSum(const int * array, const int size) {
	int Sum = 0;

	for (int i = 0; i < size; ++i) {
		if (array[i] > 0)
			sum += array[i];
	}
	return sum;
}

int recursiveCount(const int * array, const int size) {
	if (size = 0)
		return 0;

	int sum = (array[size - 1] > 0) ? array[size - 1] : 0;
	return sum + recursiveCount(array, size - 1);
}