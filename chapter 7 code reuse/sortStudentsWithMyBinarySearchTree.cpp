#include <iostream>
#include "../chapter 6 recursiveness/BinaryTree.cpp"
#include "StudentRecord.cpp"
#include <cstdlib> //srand(), rand()

using std::endl;
using std::cout;
using std::cin;

bool operator <(const StudentRecord & st1,const StudentRecord & st2) {
	return st1.getID() < st2.getID();
}
bool operator >(const StudentRecord & st1, const StudentRecord & st2) {
	return st1.getID() > st2.getID();
}
bool operator ==(const StudentRecord & st1, const StudentRecord & st2) {
	return st1.getID() == st2.getID();
}



class BinaryStudentSearchTree : public BinaryTree<StudentRecord> {
	public:
		StudentRecord findElement(const int ID) const;
};

int main() {
	BinaryStudentSearchTree studentRecords;
	cout << "\ngenerate a binary search tree with student data" << endl;
	srand(1);
	for (int i = 0; i < 5; ++i) {
		studentRecords.addElement(StudentRecord(rand() % 30 + 1, rand() % 100 + 1, "studnet" + std::to_string(i)));
	}
	studentRecords.printTree();

	cout << "\nsearch for non exisitant record" << endl;
	cout << studentRecords.findElement(90) << " is valid record?: " << studentRecords.findElement(90).isValid() << endl;

	cout << "\nsearch for present record" << endl;
	cout << studentRecords.findElement(11) << " is valid record?: " << studentRecords.findElement(11).isValid() << endl;
}

StudentRecord BinaryStudentSearchTree::findElement(const int ID) const {
	BinaryStudentSearchTree::Node * itr;
	itr = this->getHead();
	while (itr != nullptr) {
		if (ID == itr->getElement().getID())
			return itr->getElement();

		if (ID < itr->getElement().getID())
			itr = itr->getLeft();
		else
			itr = itr->getRight();
	}

	return StudentRecord(-1, -1, "");
}