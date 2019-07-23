#include<iostream>
#include<string>
#include"studentRecord.cpp"
#include<cassert>
#include<cstdlib> // qsort

using std::cin;
using std::cout;
using std::endl;

void printArray(StudentRecord * arr[], int size);
int compareStudentsByGrade(const void * st1, const void * st2);
int compareStudentsByID(const void * st1, const void * st2);
int interpolationSearch( StudentRecord ** arr, const int val, int size,  int start = 0);

int main() {
	
	cout << "\nset up an initial array with random placements:" << endl;
	srand(2);
	const int length = 8;
	StudentRecord * students[length];
	for (int i = 0; i < length; ++i) {
		int score = (i % 2 == 0) ? -1 : rand() % 101;
		int id = rand() % 30;
		students[i] = new StudentRecord(id, score, ("student" + std::to_string(i)));
	}
	printArray(students, length);

	//create a sorting array for valid records
	StudentRecord * sortingArray[length];
	int newLength = 0;
	for (int i = 0; i < length; ++i) {
		if (students[i]->getGrade() != -1) {
			sortingArray[newLength] = students[i];
			++newLength;
		}
	}
	cout << sortingArray[0]->getGrade() << endl;
	qsort(sortingArray, sizeof(int), newLength, compareStudentsByGrade);

	newLength = 0;
	cout << "\nsort out the array according to student grade:" << endl;
	for (int i = 0; i < length; ++i) {
		if (students[i]->getGrade() != -1) {
			students[i] = sortingArray[newLength];
			++newLength;
		}
	}
	printArray(students, length);

	cout << "\nSort students by id:" << endl;
	qsort(students, length, sizeof(int), compareStudentsByID);
	printArray(students, length);

	cout << "\nSerch for students by id using interpolation search" << endl;
	cout << "search for 10: " << interpolationSearch(students, 10, length) << endl;
	cout << "search for -40: " << interpolationSearch(students, -30, length) << endl;
	cout << "search for 18: " << interpolationSearch(students, 18, length) << endl;

	StudentRecord * students2[length];
	for (int i = 0; i < length; ++i) {
		students2[i] = new StudentRecord(2, 50, ("student" + std::to_string(i)));
	}
	printArray(students2, length);
	cout << "failure example? search for 2 in a mono value array of 2: " << interpolationSearch(students2, 2, length) << endl;

}

void printArray(StudentRecord * array[], const int size) {
	assert(array != nullptr);
	cout << "printing out array contents" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "id: " << array[i]->getID() << " student: " << array[i]->getName() << " grade: " << array[i]->getGrade() << endl;
	}
}

int compareStudentsByGrade(const void * st1, const void * st2) {
	return (*(StudentRecord**)st1)->getGrade() - (*(StudentRecord**)st2)->getGrade();
}

int compareStudentsByID(const void * st1, const void * st2) {
	return (*(StudentRecord**)st1)->getID() - (*(StudentRecord**)st2)->getID();
}

//returns position of value in array if it exists, otherwise return -1
int interpolationSearch( StudentRecord ** arr, const int val, int size, int start){
	int high = size - 1;
	int low = start;
	assert(arr != nullptr && high >= low);

	

	int pos;
	
	while (high >= low && val >= arr[low]->getID() && val <= arr[high]->getID()) {

		if (arr[low]->getID() == arr[high]->getID()) {
			pos = low;
		}else {
			pos = low + ((val - arr[low]->getID())*(high - low) / (arr[high]->getID() - arr[low]->getID()));
		}

		if (arr[pos]->getID() == val) {
			return pos;
		}
		if (arr[pos]->getID() < val) {
			low = pos + 1;
		}else {
			high = pos - 1;
		}
	}
	return -1;
}

