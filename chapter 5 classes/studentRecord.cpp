#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;


class StudentRecord{
	public:
		StudentRecord(); //empty initializer sets ID to an empty value (-1)
		StudentRecord(int ID, int grade, std::string name);
		int getID();
		void setID(int newID);
		int getGrade();
		void setGrade(int newGrade);
		std::string getName();
		void setName(std::string newName);
		std::string getLetterGrade();
		bool isValid();

	private:
		int ID;
		int grade;
		std::string name;

		bool isValidGrade(int grade);
};

	
/* tests for StudentRecord
int main() {
	StudentRecord record(11, 95, "bilbo baggins");
	cout << record.getLetterGrade() << endl;
}
*/

 
StudentRecord::StudentRecord() {
	setID(-1);
	setGrade(0);
	setName("");
}
StudentRecord::StudentRecord(int ID, int grade, std::string name) {
	setID(ID);
	try {
		setGrade(grade);
	}
	catch (std::string err) {
		cout << err << endl;
		setGrade(0);
	}
	setName(name);
}
int StudentRecord::getID() {
	return this->ID;
}
void StudentRecord::setID(int newID) {
	this->ID = newID;
}
int StudentRecord::getGrade() {
	return this->grade;
}

//sets the grade to the value of the arrgumet if it is valid otherwise throws an error
void StudentRecord::setGrade(int newGrade) {
	if (isValidGrade(newGrade))
		this->grade = newGrade;
	else
		throw("error invalid grade passed as argument");
}

std::string StudentRecord::getName() {
	return this->name;
}
void StudentRecord::setName(std::string newName) {
	this->name = newName;
}

std::string StudentRecord::getLetterGrade() {
	if (!isValidGrade(this->getGrade()))
		return "error grade is not valid";

	const int NUM_CATEGORIES = 11;
	const std::string letterGrades[NUM_CATEGORIES] = { "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A" };
	const int gradeThresholds[NUM_CATEGORIES] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };
	for (int i = 0; i < NUM_CATEGORIES; ++i) {
		if (this->getGrade() < gradeThresholds[i])
			return letterGrades[i - 1];
	}
	return letterGrades[NUM_CATEGORIES - 1];

}

bool StudentRecord::isValidGrade(int grade) {
	if (grade >= 0 && grade <= 100)
		return true;
	else
		return false;
}

bool StudentRecord::isValid() {
	return (this->getID() == -1) ? false : true;
}