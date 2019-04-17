//finds the maximum median among the sales data of three sales man in one year
#include<iostream>
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

int max(const int x, const int y) {
	return (x < y) ? y : x;
}

template<class T = int> int numricalCompare(const void * x, const void * y) {
	return  int(*(T*)x - *(T*)y);
}

//given a SORTED int array and its size, finds the median value in the array
int arrayMedian(int array[], const int& arraySize){
	if (arraySize % 2 == 0) return (array[arraySize / 2] + array[arraySize / 2 + 1]) / 2;
	else return array[arraySize + 1];
}

int main() {
	//initialize data
	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	int sales[NUM_AGENTS][NUM_MONTHS] = {
		{1856, 498,30924,87478,328,2653,387,3754,387587,2873,276,32},
		{5865,5456,3983,6464,9957,4785,3875,3838,4959,1122,7766,2534},
		{23,55,67,99,265,376,232,223,4546,564,4544,3434}
	};

	//sort every agents sale data
	for (auto &j : sales) {

		std::qsort(j, NUM_MONTHS, sizeof(j[0]), numricalCompare);

	}
	
	//find the largest median 
	int maxMedian = arrayMedian(sales[0], NUM_MONTHS);
	for (int i = 1; i < NUM_AGENTS; ++i) {
		maxMedian = max(maxMedian, arrayMedian(sales[i], NUM_MONTHS));
	}

	cout << "the max sales median is: " << maxMedian << '\n';




}