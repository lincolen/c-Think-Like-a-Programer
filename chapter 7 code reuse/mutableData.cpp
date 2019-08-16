//define a mutable data class template and creates a child class of student record that incorparets it 
#include<iostream>
#include"studentRecord.cpp"
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template<class T> class Mutable{
	public:
		Mutable();
		Mutable(T origin);
		void setHasValue(bool value);
		void setValue(T value);
		bool hasValue() const;
		T getValue() const; //throws an exeption if objet has no value
		void reset();

	private:
		T value;
		bool _hasValue;
};

class ExpendedStudentRecord : public StudentRecord {
public:
	ExpendedStudentRecord() : StudentRecord() {};
	ExpendedStudentRecord(int ID, int grade, string name) : StudentRecord(ID, grade, name) {};
		void setTermPaperTitle(const string str);
		string getTermPaperTitle() const;
		void setYearOfEnrollement(const int year);
		int getYearOfEnrollement() const;
		void setIsAuditingClass(const bool value);
		bool getIsAuditingClass() const;

	private:
		Mutable<string> termPaperTitle;
		Mutable<int> yearOfEnrollement;
		Mutable<bool> isAuditingClass;
};

int main() {
	cout << "create expended student record object" << endl;
	ExpendedStudentRecord stRecrod(13, 55, "meBoy");
	cout << stRecrod << endl;

	cout << "add optional fields for term paper and year of enrrolement" << endl;
	stRecrod.setTermPaperTitle("the yankidodole");
	stRecrod.setYearOfEnrollement(1959);
	cout << "term paper title " << stRecrod.getTermPaperTitle() << endl;
	cout << "year of enrollment " << stRecrod.getYearOfEnrollement() << endl;

	cout << "try to get unset member and see that an exeption is thrown" << endl;
	try {
		cout << "is auditing class " << stRecrod.getIsAuditingClass() << endl;
	}
	catch (string str) {
		cout << str << endl;
	}

};

template<class T> Mutable<T>::Mutable() {
	_hasValue = false;
}
template<class T> Mutable<T>::Mutable(T origin) {
	_hasValue = true;
	setValue(origin);
}
template<class T> void Mutable<T>::setHasValue(bool value) {
	_hasValue = value;
}
template<class T> void Mutable<T>::setValue(T value) {
	this->value = value;
	_hasValue = true;
}
template<class T> bool Mutable<T>::hasValue() const{
	return _hasValue;
}
template<class T> T Mutable<T>::getValue() const{
	if (this->hasValue()) {
		return this->value;
	}
	throw string("object has no value");
}

template<class T> void Mutable<T>::reset() {
	_hasValue = false;
}

void ExpendedStudentRecord::setTermPaperTitle(const string str) {
	this->termPaperTitle.setValue(str);
}
string ExpendedStudentRecord::getTermPaperTitle() const {
	return this->termPaperTitle.getValue();
}
void ExpendedStudentRecord::setYearOfEnrollement(const int year) {
	this->yearOfEnrollement.setValue(year);
}
int ExpendedStudentRecord::getYearOfEnrollement() const {
	return this->yearOfEnrollement.getValue();
}
void ExpendedStudentRecord::setIsAuditingClass(const bool value) {
	this->isAuditingClass.setValue(value);
}
bool ExpendedStudentRecord::getIsAuditingClass() const {
	return this->isAuditingClass.getValue();
}




