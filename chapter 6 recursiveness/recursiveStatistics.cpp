#include<cassert>

int main(){}

int recursiveArrayAverege(const int * array, const int size) {
	assert(!"non null array of non negetive size" && array != nullptr && size >= 0);
	if (size = 0)
		return 0;

	return (array[size - 1] + recursiveArrayAverege(array, size - 1) * size - 1) / size;
}

int recursiveMedian(const int * array, const int size) {
	
}