//This program sortes a list of of data structure sutdnet that holds a grade an ID and a name , according to the grade then prints out the result
//and the sorts out the list again according to the ID and the prints out the results
#include<iostream>
#include<cstdlib> //qsort
#include<string> //string

using std::cin;
using std::cout;
using std::endl;


//basic compare function for numerical values
template<class T = int> int numricalCompare(const void * x, const void * y) {
	return  int (*(T*)x - *(T*)y);
}

//data structure 
class Student {
	public:
		int grade;
		int studentID;
		std::string name;

		Student(int grade, int studentID, std::string name) : grade(grade), studentID(studentID), name(name) {
		};
};

int compareStudentByGrade(const void * x, const void * y) {
	Student * st1 = (Student *)x;
	Student * st2 = (Student *)y;
	return numricalCompare(&st1->grade, &st2->grade);
}

int compareStudentByID(const void * x, const void * y) {
	Student * st1 = (Student *)x;
	Student * st2 = (Student *)y;
	return numricalCompare(&st1->studentID, &st2->studentID);
}

int main() {
	// initializing an int array with random data
	int array[] = {7, 5, 14, 55, 187, 66, 97};
	int arraySize = sizeof(array) / sizeof(array[0]);

	//initializing a student array with random data
	Student studentArray[] = {
		{87, 10001, "Fred"},
		{28, 10002 , "Tom"},
		{100, 10003, "Alister"},
		{78, 10004, "Sasha" },
		{84, 10005, "Erin"},
		{98, 10006, "Bellinda"},
		{75, 10007, "Leslie" },
		{70, 10008, "Candy"},
		{81, 10009, "Aretha"},
		{68, 10010, "Veronica"}
	};
	int studentArraySize = sizeof(studentArray) / sizeof(studentArray[0]);

	//sorting and printing out the standard array
	std::qsort(array, arraySize, sizeof(array[0]), numricalCompare<int>);
	cout << "Array after sort: " << '\n';
	for (auto i : array) {
			cout << i << '\n';
	}

	//sorting and printing out the student array by grade
	std::qsort(studentArray, studentArraySize, sizeof(studentArray[0]), compareStudentByGrade);
	cout << "After sorting students by grade " << '\n';
	for (Student student : studentArray) {
		cout << "grade " << student.grade << " ID " << student.studentID << " name " << student.name << '\n';
	}
	cout << '\n';

	//sorting and printing out the student array by ID
	std::qsort(studentArray, studentArraySize, sizeof(studentArray[0]), compareStudentByID);
	cout << "After sorting students by ID " << '\n';
	for (Student student : studentArray) {
		cout << "grade " << student.grade << " ID " << student.studentID << " name " << student.name << '\n';
	}

}  