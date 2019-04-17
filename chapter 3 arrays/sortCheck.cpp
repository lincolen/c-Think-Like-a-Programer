#include<iostream>
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

template<class T = int> int numricalCompare(const void * x, const void * y) {
	return  int(*(T*)x - *(T*)y);
}

bool sortCheck(const int arr[], const int & arraySize) {
	
	for (int i = 0; i < arraySize - 1; ++i) {
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
}

int main() {
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 2, 1, 2 };
	
	sortCheck(arr1, 3);
	cout << "array 1 is sorted properly: " << sortCheck(arr1, 3) << endl;
	cout << "array 2 is sorted properly: " << sortCheck(arr2, 3) << endl;
}