#include<iostream>
#include<cstdlib> // qsort

using std::cout;
using std::cin;
using std::endl;

struct modeStruct {
	int value = 0;
	int numOfApperences = 0;
};

int compare(const void * x,const  void * y) {
	return *(int*)x - *(int*)y;
}

modeStruct findMode(const int * array, const int &arraySize) {
	int  * sortedArray = new int[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		sortedArray[i] = array[i];
	}


	qsort(sortedArray, arraySize, sizeof(sortedArray[0]), compare);

	int mode = sortedArray[0];
	int apperences = 1;
	int maxApperences = 1;
	for (int i = 1; i < arraySize; ++i) {
		
		if (sortedArray[i] != sortedArray[i - 1] || i == arraySize - 1 ) {
			if (apperences > maxApperences) {
				mode = sortedArray[i - 1];
				maxApperences = apperences;
			}
			apperences = 1;
		}
		else {
			++apperences;
		}
		
	}
	
	modeStruct md;
	md.value = mode;
	md.numOfApperences = maxApperences;

	delete[] sortedArray;
	return md;
}

int main() {
	int arr1[] = { 1, 3, 1 ,24, 24, 24, 3, 2, 24, 24, 24, 24,24, 3, 3 , 3, 1,2, 6, 24, 24, 3,24,24,24,24,24, 3 };
	int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
	modeStruct myMode;
	myMode = findMode(arr1, arr1Size);
	cout << "the mode is: " << myMode.value << " it appears " << myMode.numOfApperences << " times" << endl;
}