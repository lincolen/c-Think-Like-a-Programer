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
		DynamicStudentRecord(int id, int grade, std::string name);
		void addExtraField(std::string key, std::string value);
		void addExtraField(std::string key, int value);
		template<class T> T retriveField(std::string key) ; //declaration only
		template<> int retriveField<int>(std::string key) ;
		template<> std::string retriveField<std::string>(std::string key) ;
		

	private:
		std::unordered_map<std::string, std::string> textFields;
		std::unordered_map<std::string, int> numricalFields;
		template<class T> void addExtraField(std::string key, T value, std::unordered_map<std::string, T> & map);
		template<class T> T retriveField(std::string key, std::unordered_map<std::string, T> & map) ;
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
DynamicStudentRecord::DynamicStudentRecord(int id, int grade, std::string name) : StudentRecord(id, grade, name) {};
void DynamicStudentRecord::addExtraField(std::string key, std::string value) {
	addExtraField(key, value, this->textFields);
}
void DynamicStudentRecord::addExtraField(std::string key, int value) {
	addExtraField(key, value, this->numricalFields);
}


template<> int DynamicStudentRecord::retriveField<int>(std::string key)  {
	return retriveField(key, this->numricalFields);
}

template<> std::string DynamicStudentRecord::retriveField<std::string>(std::string key) {

	return retriveField(key, this->textFields);
}


template<class T> T DynamicStudentRecord::retriveField(std::string key, std::unordered_map<std::string, T> & map) {

	return map.at(key);
}

template<class T> void  DynamicStudentRecord::addExtraField(std::string key, T value, std::unordered_map<std::string, T> & map) {

	map.emplace(key, value);

}
