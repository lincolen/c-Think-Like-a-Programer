#include<iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
	for (int y = 1; y <= 11; y++) {
		if (abs(10 - 2 * y) == 0) continue;

		for (int x = 0; x < 10 - abs(10 - 2 * y); ++x) {
			cout << '#';
		}
		cout << '\n';
	}
}