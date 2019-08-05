#include <iostream>
#include "StudentRecord.cpp"
#include <unordered_map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

void printStudnets(std::unordered_map<int, StudentRecord> & students) {
	for (std::unordered_map<int, StudentRecord>::iterator itr = students.begin(); itr != students.end(); ++itr) {
		cout << (*itr).second << endl;
	}
}

int main() {
	std::unordered_map<int, StudentRecord> studentRecords;
	cout << "\ngenerate an unorderd map with student data" << endl;
	srand(1);
	for (int i = 0; i < 5; ++i) {
		int id = rand() % 30 + 1;
		studentRecords.emplace(id , StudentRecord(id, rand() % 100 + 1, "studnet" + std::to_string(i)));
	}
	printStudnets(studentRecords);

	cout << "\nsearch for non exisitant record" << endl;
	StudentRecord * st = &studentRecords[90];
	cout << *st << " is valid record?: " << st->isValid() << endl;

	cout << "\nsearch for present record" << endl;
	st = &studentRecords[23];
	cout << *st << " is valid record?: " << st->isValid() << endl;
}

