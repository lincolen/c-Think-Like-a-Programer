#include<iostream>
#include<string>
#include"studentRecord.cpp"
#include<cassert>
#include<cstring> //strcmp

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
		typedef bool(*firstStudentPolicy)(const StudentRecord & r1,const StudentRecord & r2);
		firstStudentPolicy currentPolicy;
		//first student policies 
		static bool higherGrade(const StudentRecord & r1, const StudentRecord & r2);
		static bool lowerStudentNumber(const StudentRecord & r1, const StudentRecord & r2);
		static bool nameComesFirst(const StudentRecord & r1, const StudentRecord & r2);

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
		int averageRecord(); // returns -1 if there are no valid records
		StudentRecordCollection& operator = (StudentRecordCollection && rhs); //move assignment
		StudentRecordCollection getRecordsInRange(const int gradeMin, const int gradeMax) const;

		enum FirstStudentPolicies{ NONE, HIGHEST_GRADE,LOWEST_ID, FIRST_NAME };
		void setFirstStudentPolicy(FirstStudentPolicies policy);
		StudentRecord getFirstStudent() const;

		
		class srcIterator {
			private:
				studentRecordNode * currentNode;

			public:
				srcIterator();
				srcIterator(studentRecordNode* srNode);
				srcIterator(srcIterator & original);
				srcIterator& operator++();
				srcIterator& operator=(srcIterator & rhs);
				bool operator==(srcIterator & srNode) const;
				bool operator!=(srcIterator & srNode) const;
				StudentRecord operator*() const;
		};
		srcIterator begin() const;
		srcIterator end() const;
};

int main() {
	StudentRecordCollection	myCollection;
	cout << "average record: " << myCollection.averageRecord() << endl;

	
	myCollection.addRecord(12, 55, "london london");
	myCollection.addRecord(13, 65, "london manchester");

	cout << "average record: " << myCollection.averageRecord() << endl;
	try {
		cout << myCollection.getRecordWithId(11).getID() << endl;
	}
	catch (char * e) {
		cout << e << endl;
	}
	
	cout << "\ntest getRecordsInRange" << endl;
	cout << "copy records in myCollection in range 0 - 80" << endl;
	StudentRecordCollection	myCollection2 = myCollection.getRecordsInRange(0, 80);

	cout << "\nIterator test " << endl;
	for (StudentRecordCollection::srcIterator itr = myCollection2.begin(); itr != myCollection2.end(); ++itr) {
		cout << (*itr).getName() << endl;
	}
	
	cout << "\nfirst student policy tests" << endl;
	cout << "by grade" << endl;
	myCollection2.setFirstStudentPolicy(StudentRecordCollection::HIGHEST_GRADE);
	cout << "first Stduent: " << myCollection2.getFirstStudent().getName() << endl;
	cout << "by id" << endl;
	myCollection2.setFirstStudentPolicy(StudentRecordCollection::FirstStudentPolicies::LOWEST_ID);
	cout << "first Stduent: " << myCollection2.getFirstStudent().getName() << endl;

	cout << "\nrecord obtained id, grade:" << myCollection2.getRecordWithId(12).getID() << " " << myCollection2.getRecordWithId(12).getGrade();


	try {
		cout << myCollection.getRecordWithId(12).getGrade() << endl;
	}
	catch (...) {};
	try {
		cout << myCollection.getRecordWithId(11).getID() << endl;
	}
	catch (...) {};

	myCollection.removeRecordById(11);
	myCollection.removeRecordById(12);
	myCollection.removeRecordById(12);
	

}

StudentRecordCollection::StudentRecordCollection() {
	this->head = nullptr;
	this->setFirstStudentPolicy(StudentRecordCollection::FirstStudentPolicies::NONE);
}

StudentRecordCollection::StudentRecordCollection(const StudentRecordCollection & original) {
	this->head = copyList(original.head);
	this->setFirstStudentPolicy(StudentRecordCollection::FirstStudentPolicies::NONE);
}

StudentRecordCollection::StudentRecordCollection(StudentRecordCollection && original) {
	cout << "this is move constuction" << endl;
	this->head = original.head;
	original.head = nullptr;
	this->setFirstStudentPolicy(StudentRecordCollection::FirstStudentPolicies::NONE);
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

int StudentRecordCollection::averageRecord() {
	//check empty list
	if (this->head == nullptr) {
	std::cerr << "error empty list" << endl;
		return -1;
	}


	studentRecordNode * recordNode  = this->head;
	int gradeSum = 0;
	int numOfStudents = 0;
	while (recordNode != nullptr) {
		if (recordNode->record.isValid()) {
			gradeSum += recordNode->record.getGrade();
			++numOfStudents;
		}
		recordNode = recordNode->next;
	}
	
	if (numOfStudents == 0) {
		std::cerr << "No valid student records" << endl;
		return -1;
	}

	return gradeSum / numOfStudents;
	
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

bool StudentRecordCollection::higherGrade(const StudentRecord & r1, const StudentRecord & r2) {
	assert("invalid studnet records passed as arguments" && r1.isValid() && r2.isValid());
	return r1.getGrade() > r2.getGrade();
}
bool StudentRecordCollection::lowerStudentNumber(const StudentRecord & r1, const StudentRecord & r2) {
	assert("invalid studnet records passed as arguments" && r1.isValid() && r2.isValid());
	return  r1.getID() < r2.getID();
}
bool StudentRecordCollection::nameComesFirst(const StudentRecord & r1, const StudentRecord & r2) {
	assert("invalid studnet records passed as arguments" && r1.isValid() && r2.isValid());
	return  strcmp(r1.getName().c_str(), r2.getName().c_str()) < 0;
}

void StudentRecordCollection::setFirstStudentPolicy(StudentRecordCollection::FirstStudentPolicies policy) {
	switch (policy) {
		case StudentRecordCollection::FirstStudentPolicies::FIRST_NAME:
			this->currentPolicy = this->nameComesFirst;
			break;
		case StudentRecordCollection::FirstStudentPolicies::HIGHEST_GRADE:
			this->currentPolicy = this->higherGrade;
			break;
		case StudentRecordCollection::FirstStudentPolicies::LOWEST_ID:
			this->currentPolicy = this->lowerStudentNumber;
			break;
		default:
			this->currentPolicy = nullptr;
	}
	
	
}
StudentRecord StudentRecordCollection::getFirstStudent() const {
	assert("empty collection" && this->head != nullptr && this->currentPolicy != nullptr);
	studentRecordNode * itr = this->head;
	StudentRecord firstStudent = (itr->record);
	
	while (itr != nullptr) {
		firstStudent = (this->currentPolicy(itr->record, firstStudent)) ? itr->record : firstStudent;
		itr = itr->next;
	}
	return firstStudent;
}



StudentRecordCollection::srcIterator::srcIterator() {
	this->currentNode = nullptr;
}
StudentRecordCollection::srcIterator::srcIterator(studentRecordNode* srNode) {
	this->currentNode = srNode;
}
StudentRecordCollection::srcIterator::srcIterator(srcIterator & original) {
	this->currentNode = original.currentNode;
}
StudentRecordCollection::srcIterator & StudentRecordCollection::srcIterator::operator++() {
	if (this->currentNode != nullptr) {
		this->currentNode = this->currentNode->next;
	}

	return *this;
}
StudentRecordCollection::srcIterator & StudentRecordCollection::srcIterator::operator=(srcIterator & rhs) {
	this->currentNode = rhs.currentNode;
	return *this;
}
bool StudentRecordCollection::srcIterator::operator==(srcIterator & rhs) const{
	return this->currentNode == rhs.currentNode;
}

bool StudentRecordCollection::srcIterator::operator!=(srcIterator & rhs) const {
	return !(*this == rhs);
}

StudentRecord StudentRecordCollection::srcIterator::operator*() const {
	assert(this->currentNode != nullptr);

	return this->currentNode->record;
}

StudentRecordCollection::srcIterator StudentRecordCollection::begin() const {
	srcIterator itr(this->head);
	return itr;
}
StudentRecordCollection::srcIterator StudentRecordCollection::end() const {
	srcIterator itr(nullptr);
	return itr;
}