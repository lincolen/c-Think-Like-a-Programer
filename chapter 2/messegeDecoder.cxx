#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void uppercaseDecoder(const int codedNumber);
void lowercaseDecoder(const int codedNumber);
void punctuationDecoder(const int codedNumber);

enum {UPPERCASE, LOWERCASE, PUNCTUATION} decodeMode = UPPERCASE;

int main(){
	
	
	char digit = cin.get();
	int codedNumber = 0;
	while(digit != '\n'){
		if(digit == ','){
			switch(decodeMode){
				case UPPERCASE: 
					uppercaseDecoder(codedNumber);
					break;
				case LOWERCASE:
					lowercaseDecoder(codedNumber);
					break;
				case PUNCTUATION:
					punctuationDecoder(codedNumber);
					break;
			}
			codedNumber = 0;
		}else{
	    	codedNumber *= 10;
    		codedNumber += digit - '0';
		}
		digit = cin.get();
	}
}

void uppercaseDecoder(const int codedNumber){
	
	if(codedNumber % 27 == 0){
		decodeMode = LOWERCASE;
		return;
	}
	char decodedChar = 'A' - 1 + (codedNumber % 27);
	cout << decodedChar;
}

void lowercaseDecoder(const int codedNumber){
		if(codedNumber % 27 == 0){
			decodeMode = PUNCTUATION;
			return;
	}
	char decodedChar = 'a' - 1 + (codedNumber % 27);
	cout << decodedChar;
}

void punctuationDecoder(const int codedNumber){
	static const char punctuation[] = {'\0', '!', '?', ',', '.', ' ', ';', '"', '\''};
	if(codedNumber % 9 == 0){
		decodeMode = UPPERCASE;
	}
	cout << punctuation[codedNumber % 9];
	
}