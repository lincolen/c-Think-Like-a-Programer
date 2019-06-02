int main(){}

iterativeTargetCount(const int * array, const int size, const int target) {
	count = 0;

	for (int i = 0; i < size; ++i) {
		if (array[i] == target)
			++count;
	}
	return count;
}

recursiveTargetCount(const int * array, const int size, const int target) {
	if (size == 0)
		return 0;

	return (array[size - 1] == target) ? recursiveTargetCount(array, size - 1, target) + 1 : recursiveTargetCount(array, size - 1, target);
}