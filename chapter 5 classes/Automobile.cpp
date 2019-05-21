#include<iostream>
#include<string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

class Automobile {
	public:
		Automobile();
		Automobile(std::string menufacturer, std::string modelName, int modelYear);
		string getMenufacturer();
		void setMenufacturer(string menufacturer);
		string getModelName();
		void setModelName(string modelName);
		int getModelYear();
		void setModelYear(int modelYear);
		string getDescription();
		int getAge();
		
	private:
		string menufacturer;
		string modelName;
		int modelYear;

};

int main() {
	Automobile myCar("honda", "blazer", 2019);
	cout << myCar.getMenufacturer() << '\n' << myCar.getModelName() << endl << myCar.getModelYear() << endl;


	cout << myCar.getDescription() << endl;
}

Automobile::Automobile() {
	setMenufacturer("");
	setModelName("");
	setModelYear(0);
}

Automobile::Automobile(string menufacturer, string modelName, int modelYear) {
	setMenufacturer(menufacturer);
	setModelName(modelName);
	setModelYear(modelYear);
}

string Automobile::getMenufacturer() {
	return this->menufacturer;
}

void Automobile::setMenufacturer(string menufacturer) {
	this->menufacturer = menufacturer;
}

string Automobile::getModelName() {
	return this->modelName;
}

void Automobile::setModelName(string modelName) {
	this->modelName = modelName;
}

int Automobile::getModelYear() {
	return this->modelYear;
}

void Automobile::setModelYear(int modelYear) {
	this->modelYear = modelYear;
}

string Automobile::getDescription() {
	return std::to_string(getModelYear()) + " " + getMenufacturer() + " " +  getModelName();

	
}

int Automobile::getAge() {
	return 2019 - getModelYear();
}