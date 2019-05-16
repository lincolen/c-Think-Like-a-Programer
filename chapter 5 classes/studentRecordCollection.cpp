#include<iostream>
#include<string>
#include"studentRecord.cpp"

using std::cin;
using std::cout;
using std::endl;

class StudentRecordCollection {
	private:
		struct studentRecordNode {
			StudentRecord record;
			studentRecordNode * next;
		};
		studentRecordNode * head;

	public:
		StudentRecordCollection();
		~StudentRecordCollection();
		StudentRecordCollection& addRecord(const int ID,const int grade,const std::string name);
};

int main() {}

StudentRecordCollection::StudentRecordCollection() {
	this->head = nullptr;
}

StudentRecordCollection::~StudentRecordCollection() {
	studentRecordNode * itr, *next;
	next = this->head;
	
	while (next != nullptr) {
		itr = next;
		next = itr->next;
		delete itr;
	}
}

StudentRecordCollection& StudentRecordCollection::addRecord(const int ID, const int grade, const std::string name) {
	studentRecordNode * newNode = new studentRecordNode{StudentRecord(ID, grade, name), this->head};
	this->head = newNode;

	return *this;
}