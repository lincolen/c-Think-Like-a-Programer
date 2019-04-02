#include<iostream>


using std::cin;
using std::cout;

int main(){
	const int maxLength = 5;
			for(int i = 1; i < 2*maxLength; i++){
				for(int j = 0; j < maxLength - abs(maxLength - i); j++){
					cout << "#";
				}
				cout << "\n";
			}
				        
				        
	}