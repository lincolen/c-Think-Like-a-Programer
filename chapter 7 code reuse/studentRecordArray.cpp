#include<iostream>
#include<string>
#include"studentRecord.cpp"
#include<cassert>
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

void printArray(StudentRecord * arr[], int size);
int compareStudents(const void * st1, const void * st2);

int main() {
	
	srand(2);
	//set up an initial array with random placements

	const int length = 8;
	StudentRecord * students[length];
	for (int i = 0; i < length; ++i) {
		int score = (i % 2 == 0) ? -1 : rand() % 101;
		students[i] = new StudentRecord(10 + i, score, ("studnet" + std::to_string(i)));
	}
	printArray(students, length);

	StudentRecord * sortingArray[length];
	int newLength = 0;
	for (int i = 0; i < length; ++i) {
		if (students[i]->getGrade() != -1) {
			sortingArray[newLength] = students[i];
			++newLength;
		}
	}
	cout << sortingArray[0]->getGrade() << endl;
	qsort(sortingArray, sizeof(int), newLength, compareStudents);

	newLength = 0;
	//sort out the array according to student grade
	for (int i = 0; i < length; ++i) {
		if (students[i]->getGrade() != -1) {
			students[i] = sortingArray[newLength];
			++newLength;
		}

	}
	
	printArray(students, length);
	
}

void printArray(StudentRecord * array[], const int size) {
	assert(array != nullptr);
	cout << "prining out array contents" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "studnet: " << array[i]->getName() << " grade: " << array[i]->getGrade() << endl;
	}
}

int compareStudents(const void * st1, const void * st2) {
	return (*(StudentRecord**)st1)->getGrade() - (*(StudentRecord**)st2)->getGrade();
}