//this file defines a list data type student and povides some basic functions to manipulate it
#include<iostream>
#include<forward_list>
#include<cassert>
#include<algorithm> //for_each

using std::cout;
using std::endl;
using std::forward_list;

struct Student {
	int ID;
	int grade;
};

void addRecord(forward_list<Student> &studentList, const int ID, const int grade) {
	Student student = { ID, grade };
	studentList.push_front(student);
}

//the student grade avarege
double avarageRecord(forward_list<Student> &studentList) {
	assert(!"Empty list" || !studentList.empty());

	int numOfStudents = 0;
	int sum = 0;
	for (forward_list<Student>::iterator itr = studentList.begin(); itr != studentList.end(); ++itr) {
		sum += (*itr).grade;
		++numOfStudents;
	}

	return (double)sum / (double)numOfStudents;

}

void printList(forward_list<Student> &studentList) {
	std::for_each(studentList.begin(), studentList.end(), [](Student &student) {cout << "id: " << student.ID << " grade: " << student.grade << endl;});
}

//removes the student accoeding to its ID from the studene list
void removeRecord(forward_list<Student> &studentList, const int id) {

	studentList.remove_if([=](Student student) {return student.ID == id;});
}

int main() {
	forward_list<Student> studentList;
	cout << "\n printing empty list: " << endl;
	printList(studentList);

	cout << "\n attempting to remove element from empty list" << endl;
	removeRecord(studentList, 2);

	cout << "\n adding elements to list" << endl;
	for (int i = 1; i < 4; ++i) {
		addRecord(studentList, i, i);
	}

	cout << "\n printing list:" << endl;
	printList(studentList);

	cout << "\n finding avarege: " << endl;
	cout << "avarage " << avarageRecord(studentList) << endl;

	cout << "\n removeing records from list: " << endl;
	removeRecord(studentList, 2);
	printList(studentList);
	removeRecord(studentList, 3);
	printList(studentList);
}