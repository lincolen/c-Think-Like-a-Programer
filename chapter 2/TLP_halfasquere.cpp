#include <iostream> //cin, cout
using std::cin;
using std::cout;

void draw(const int length){
	if(length == 0) return;
	
	for(int i =0; i<length; i++){
		cout << "#";
	}
	cout << "\n";
	draw(length - 1);
}

int main(){
	int startLength;
	cout << "enter the start length: ";
	cin >> startLength;
	draw(startLength);
}