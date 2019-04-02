#include<iostream> 
#include<assert.h>

using std::cout;
using std::cin;
using std::endl;

int doubleDigit(const int digit){
	assert(digit >= 0 && digit <= 9);
	
	if(digit < 5) return digit;
	return (1 + (2*digit)%10);
}

bool checksumValid(const int sum)
{
	return (sum % 10 == 0);
}
	
int main(){
	int oddSum(0), evenSum(0);
	int digits = 0;
	
	
	char  dig = cin.get();
	while(dig != '\n'){
		
	
	int digit =(int) dig - '0';
	
	if(digits % 2 == 0){
		evenSum += doubleDigit(digit);
		oddSum += digit;
	
	}else {
		evenSum += digit;
		oddSum += doubleDigit(digit);
	}
		digits++;
		dig = cin.get();
		cout << dig <<  std::endl;
	}
	
	int sum;
	if(digits % 2 == 0){
		sum = evenSum;
	}else{
		sum = oddSum;
	}
	
	cout << "the sum is " << sum << endl;
	if(checksumValid(sum)) cout << "the number is valid" << endl;
	else cout << "the number is not valid" << endl;
	
}