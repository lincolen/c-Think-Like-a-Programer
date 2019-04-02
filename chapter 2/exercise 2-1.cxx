#include<iostream>

using namespace std;

int main(){
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 8 - y*2; ++x){
			cout << '#';
		}
		cout << '\n';
	}
}