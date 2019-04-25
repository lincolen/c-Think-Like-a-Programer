#include<iostream>
#include<cstdlib> //qsort
#include<string> //string
#include<memory> //unique_pointer

using std::cin;
using std::cout;
using std::endl;


//basic compare function for numerical values
template<class T = int> int numricalCompare(const void * x, const void * y) {
	return  int(*(T*)x - *(T*)y);
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

int * GradeArray(const Student students[], const int & numberOfStudents){
	int * grades = new int[numberOfStudents];
	for (int i = 0; i < numberOfStudents; ++i) {
		grades[i] = students[i].grade;
	}
	return grades;
}

int compare(const void * x, const void * y) {
	return  *(int*)x - *(int*)y;
}




int main() {
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

	std::unique_ptr<int[]> grades(GradeArray(studentArray, studentArraySize));

	qsort(grades.get(), studentArraySize, sizeof(grades[0]), compare);

	cout << "in order to score above the 25th precentile one must score: " << grades[studentArraySize / 4 ] << endl;
	cout << "in order to score above the 50th precentile one must score: " << grades[studentArraySize / 2 ] << endl;
	cout << "in order to score above the 75th precentile one must score: " << grades[3 * studentArraySize / 4 ] << endl;
	
}