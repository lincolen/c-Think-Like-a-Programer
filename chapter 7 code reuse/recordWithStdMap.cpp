//think like a programer exercise 7-7
//implement a student record that can have data members added to it at runtime using a std librery tool (two unorderd maps for int and string)

#include<iostream>
#include<string>
#include"StudentRecord.cpp"
#include<unordered_map>

using std::cout;
using std::endl;

class DynamicStudentRecord : public StudentRecord {
	public:
		DynamicStudentRecord();
		DynamicStudentRecord(const int id,const int grade, const std::string & name);
		void addExtraField(const std::string & key,const std::string & value);
		void addExtraField(const std::string & key,const int value);
		template<class T> T retriveField(const std::string & key) const; //declaration only
		template<> int retriveField<int>(const std::string & key) const;
		template<> std::string retriveField<std::string>(const std::string & key) const ;
		

	private:
		std::unordered_map<std::string, std::string> textFields;
		std::unordered_map<std::string, int> numricalFields;
		template<class T> void addExtraField(const std::string & key,const T value, std::unordered_map<std::string, T> & map);
		template<class T> T retriveField(std::string key,const std::unordered_map<std::string, T> & map) const;
};

int main() {
	cout << "create expended student record object" << endl;
	DynamicStudentRecord stRecrod(13, 55, "meBoy");
	cout << stRecrod << endl;
	

	cout << "add optional fields for term paper and year of enrrolement" << endl;
	stRecrod.addExtraField("term_paper_title","the yankidodole");
	stRecrod.addExtraField("year_of_enrollment", 1959);
	cout << "now read them out" << endl;
	cout << "term paper title " << stRecrod.retriveField<std::string>("term_paper_title") << endl;
	
	cout << "year of enrollment " << stRecrod.retriveField<int>("year_of_enrollment") << endl;

	cout << "try to get unset member and see that an exeption is thrown" << endl;
	try {
		cout << "is auditing class " << stRecrod.retriveField<int>("is_auditing_class") << endl;
	}
	catch (const std::out_of_range& oor) {
		cout << oor.what() << endl;
	}

	cout << "can int be implecitly converted to bool?" << endl;
	bool bl;
	bl = 5;
	cout << bl << endl;
	cout << "can bool be implecitly converted to int?" << endl;
	int i;
	i = false;
	cout << i  << endl;
	

}



DynamicStudentRecord::DynamicStudentRecord() : StudentRecord() {};
DynamicStudentRecord::DynamicStudentRecord(const int id,const int grade,const std::string & name) : StudentRecord(id, grade, name) {};
void DynamicStudentRecord::addExtraField(const std::string & key,const std::string & value) {
	addExtraField(key, value, this->textFields);
}
void DynamicStudentRecord::addExtraField(const std::string & key,const int value) {
	addExtraField(key, value, this->numricalFields);
}


template<> int DynamicStudentRecord::retriveField<int>(const std::string & key) const {
	return retriveField(key, this->numricalFields);
}

template<> std::string DynamicStudentRecord::retriveField<std::string>(const std::string & key) const {

	return retriveField(key, this->textFields);
}


template<class T> T DynamicStudentRecord::retriveField(std::string key,const std::unordered_map<std::string, T> & map) const {

	return map.at(key);
}

template<class T> void  DynamicStudentRecord::addExtraField(const std::string & key,const T value, std::unordered_map<std::string, T> & map) {

	map.emplace(key, value);

}
