//this file defines a list data type student and povides some basic functions to manipulate it
#include<iostream>

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

//the student grade avarege
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

//removes the student accoeding to its ID from the studene list
void removeRecord(Student * &studentList,const int id) {
	Student * student = studentList;
	Student * prevStudent = nullptr;
	
	//in case of empty list
	if (studentList == nullptr) {
		cout << "error empty list" << endl;
		return;
	}
	//in case the first item is being removed
	if (student->ID == id) {
		studentList = student->next;
		delete student;
		return;
	}
	//normal case
	while (student != nullptr) {
		if (student->ID == id) {
			prevStudent->next = student->next;
			delete student;
			return;
		}
		prevStudent = student;
		student = student->next;
	}

	cout << "id not found in list" << endl;
	return;
}

int main() {
	Student * studentList = nullptr;
	printList(studentList);
	removeRecord(studentList, 2);
	for (int i = 1; i < 4; ++i) {
		addRecord(studentList, i, i);
	}
	printList(studentList);
	cout << "avarage " << avarageRecord(studentList) << endl;
	removeRecord(studentList, 2);
	printList(studentList);
	removeRecord(studentList, 3);
	printList(studentList);
}