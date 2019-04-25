#include<iostream>

using std::cin;
using std::cout;
using std::endl;

struct Student{
	int ID;
	int grade;
	Student * next;
};

void addRecord(Student * &studentList, const int ID, const int grade) {
	Student * newStudent = new Student;
	newStudent->grade = grade;
	newStudent->ID = ID;
	newStudent->next = studentList;
	studentList = newStudent;

	/* if appending to end of list
	if (studentList == nullptr) {
		studentList = newStudent;
		return;
	}
	Student * index = studentList;
	while (index->next != nullptr) {
		index = index->next;
	}

	index->next = newStudent;	
	*/
}

double avarageRecord(Student * studentList) {
	int numOfStudents = 0;
	int sum = 0;
	Student * index = studentList;
	if (studentList == nullptr) {
		return 0.0;
	}

	do {
		sum += index->grade;
		++numOfStudents;
		index = index->next;
	} while (index != nullptr);

	return (double)sum / (double)numOfStudents;

}

void printList(Student * studentList) {
	Student * student = studentList;
	while (student != nullptr) {
		cout << "id: " << student->ID << " grade: " << student->grade << endl;
		student = student->next;
	}
}

int main() {
	Student * studentList = nullptr;
	printList(studentList);
	for (int i = 1; i < 4; ++i) {
		addRecord(studentList, i, i);
	}
	printList(studentList);
	cout << "avarage " << avarageRecord(studentList) << endl;
}