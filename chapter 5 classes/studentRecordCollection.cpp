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
		using studentRecordList = studentRecordNode * ;
		studentRecordList copyList(const studentRecordList oldList); //deep copies the list passed as an argument, note returns pointer to dyanmic memory, make sure to properly dellocate
		void deleteList(studentRecordList & list); //deletes the list whos head is the argument, and changes it to a nullptr

	public:
		StudentRecordCollection();
		StudentRecordCollection(const StudentRecordCollection & original);
		StudentRecordCollection(StudentRecordCollection && original);
		~StudentRecordCollection();
		StudentRecordCollection& addRecord(const int ID,const int grade,const std::string name); //creates a new record using the paramters and adds it the list
		StudentRecordCollection& addRecord(const StudentRecord & newRecord); // copies and adds a record to the list
		StudentRecord getRecordWithId(const int id); //return the student record specified by the id, if no student is found returns throws a string error and returns a StudentRecord with illegel values;
		void removeRecordById(const int id); //removes he record specifiedby the id if it exisits 
		StudentRecordCollection& operator = (const StudentRecordCollection & rhs); //copy assignment
		StudentRecordCollection& operator = (StudentRecordCollection && rhs); //move assignment
		StudentRecordCollection getRecordsInRange(const int gradeMin, const int gradeMax) const;
};

int main() {
	StudentRecordCollection	myCollection;

	myCollection.addRecord(12, 55, "london london");

	cout << myCollection.getRecordWithId(12).getGrade() << endl;
	try {
		cout << myCollection.getRecordWithId(11).getID() << endl;
	}
	catch (char * e) {
		cout << e << endl;
	}
	
	cout << "\ntest getRecordsInRange" << endl;
	cout << "copy records in myCollection in range 0 - 80" << endl;
	StudentRecordCollection	myCollection2 = myCollection.getRecordsInRange(0, 80);
	cout << "record obtained id, grade:" << myCollection2.getRecordWithId(12).getID() << " " << myCollection2.getRecordWithId(12).getGrade();

	myCollection.removeRecordById(11);
	myCollection.removeRecordById(12);
	myCollection.removeRecordById(12);
	

}

StudentRecordCollection::StudentRecordCollection() {
	this->head = nullptr;
}

StudentRecordCollection::StudentRecordCollection(const StudentRecordCollection & original) {
	this->head = copyList(original.head);
}

StudentRecordCollection::StudentRecordCollection(StudentRecordCollection && original) {
	cout << "this is move constuction" << endl;
	this->head = original.head;
	original.head = nullptr;
}

StudentRecordCollection::~StudentRecordCollection() {
	deleteList(this->head);
}

StudentRecordCollection& StudentRecordCollection::addRecord(const int ID, const int grade, const std::string name) {
	studentRecordNode * newNode = new studentRecordNode;
	newNode->record = StudentRecord(ID, grade, name);
	newNode->next =	this->head;
	this->head = newNode;

	return *this;
}

StudentRecordCollection& StudentRecordCollection::addRecord(const StudentRecord& newRecord) {
	studentRecordNode * newNode = new studentRecordNode;
	newNode->record = newRecord;
	newNode->next = this->head;
	this->head = newNode;

	return *this;
}

StudentRecord StudentRecordCollection::getRecordWithId(const int id) {
	studentRecordNode * itr;
	itr = this->head;
	while (itr != nullptr) {
		if (itr->record.getID() == id)
			return itr->record;
		else
			itr = itr->next;
	}

	throw("Error empty list or record with given id not found");
	return StudentRecord();
} 

void StudentRecordCollection::removeRecordById(const int id) {
	studentRecordNode * itr, *next;

	//head processing
	if (this->head == nullptr)
		return;
	
	next = this->head;
	if (next->record.getID() == id) {
		this->head = next->next;
		delete next;
	}
	itr = next;
	next = itr->next;

	//list processing
	while (next != nullptr) {
		if (next->record.getID() == id) {
			itr->next = next->next;
			delete next;
			return;
		}

		itr = next;
		next = itr->next;
	}
}

StudentRecordCollection::studentRecordList StudentRecordCollection::copyList(const StudentRecordCollection::studentRecordList oldList) {
	//empty list
	if (oldList == nullptr)
		return nullptr;
	
	//head processing
	studentRecordList newList = nullptr;
	studentRecordNode * newItr, *oldItr;

	newItr = new studentRecordNode;
	newList = newItr;

	oldItr = oldList;
	newItr->record = oldItr->record;
	oldItr = oldItr->next;

	//list processing
	while (oldItr != nullptr) {
		newItr->next = new studentRecordNode;
		newItr = newItr->next;
		newItr->record = oldItr->record;

		oldItr = oldItr->next;
	}
	newItr->next = nullptr;
	return newList;
}

void StudentRecordCollection::deleteList(StudentRecordCollection::studentRecordList & head) {
	studentRecordNode * itr, *next;

	next = head;

	while (next != nullptr) {
		itr = next;
		next = itr->next;
		delete itr;
	}
	head = nullptr;
}

StudentRecordCollection& StudentRecordCollection::operator= (const StudentRecordCollection & rhs) {
	if (this == &rhs)
		return *this;

	deleteList(this->head);
	this->head = copyList(rhs.head);

	return *this;
}

StudentRecordCollection& StudentRecordCollection::operator= (StudentRecordCollection && rhs) {
	cout << "this is move assignment" << endl;
	if (this == &rhs)
		return *this;

	deleteList(this->head);
	this->head = rhs.head;
	rhs.head = nullptr;

	return *this;
}

StudentRecordCollection StudentRecordCollection::getRecordsInRange(int gradeMin = 0, int gradeMax = 100) const {
	StudentRecordCollection newCollection;
	studentRecordNode * itr;
	itr = this->head;
	while (itr != nullptr) {
		bool isValidRecordInRange = (itr->record.isValid() && itr->record.getGrade() >= gradeMin && itr->record.getGrade() <= gradeMax);
		if (isValidRecordInRange) {
			
			newCollection.addRecord(itr->record);
		}
		itr = itr->next;
	}

	return newCollection;
}