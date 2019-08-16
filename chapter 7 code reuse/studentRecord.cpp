#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;


class StudentRecord{
	public:
		StudentRecord(); //empty initializer sets ID to an empty value (-1)
		StudentRecord(int ID, int grade, std::string name);
		int getID() const;
		void setID(int newID);
		int getGrade() const;
		void setGrade(int newGrade);
		std::string getName() const;
		void setName(std::string newName);
		std::string getLetterGrade();
		bool isValid() const;
		void printRecord() const;



	protected:
		int ID;
		int grade;
		std::string name;
		bool isValidGrade(int grade);

};
std::ostream & operator<< (std::ostream & os, const StudentRecord & st);

	
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
int StudentRecord::getID() const{
	return this->ID;
}
void StudentRecord::setID(int newID) {
	this->ID = newID;
}
int StudentRecord::getGrade() const{
	return this->grade;
}

//sets the grade to the value of the arrgumet if it is valid otherwise throws an error
void StudentRecord::setGrade(int newGrade) {
	if (isValidGrade(newGrade))
		this->grade = newGrade;
	else
		this->grade = -1;
}

std::string StudentRecord::getName() const{
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
	if (grade >= -1 && grade <= 100)
		return true;
	else
		return false;
}

bool StudentRecord::isValid() const {
	if (this->getID() != -1)
		return true;
	return false;
}

void StudentRecord::printRecord() const{
	cout << "id: " << getID() << " grade: " << getGrade() << " name: " << getName();
}

std::ostream & operator<< (std::ostream & os, const StudentRecord & st) {
	st.printRecord();
	return os;
}