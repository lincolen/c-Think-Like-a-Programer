#include<iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
	const int length = 8;
	for (int y = 1; y <= length/2; y++) {


		for (int x = 1; x <= length; ++x) {
			if(x <= y || x > (length - y)) cout << '#';
			else cout << ' ';
		}
		cout << '\n';
	}
}