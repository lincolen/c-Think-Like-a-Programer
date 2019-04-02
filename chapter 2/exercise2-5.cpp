#include<iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
	
	for (int y = 1; y <= 7; y++) {


		for (int x = 1; x <= 7; ++x) {
			if (y == 4 && x == 4) cout << ' ';
			else if(x <= abs(4 - y) || x > 7 - abs(4 - y)) cout << ' ';
			//else if(x <= 7 - abs(4 - y))  cout << '#';
			else cout << '#';
		}
		cout << '\n';
	}
}