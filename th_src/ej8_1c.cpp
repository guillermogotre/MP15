#include <iostream>
using namespace std;

int GetInteger(char string[]);
int StringSize(char string[]);

int main(){
	char cad1[] = "1 23",
		cad2[] = "-10",
		cad3[] = "1 ";
	int int1,
		int2,
		int3;

	int1=GetInteger(cad1);
	int2=GetInteger(cad2);
	int3=GetInteger(cad3);

	cout << int1 << " " << int2 << " " << int3 << endl;
}

//GetInteger() gets the integer value of
//a C string
int GetInteger(char string[]){
	// It doesn't consider any other character
	// than numbers and the minus symbol ('-')
	// in position 0
	int num = 0,
		size = StringSize(string),
		power = 1;
	for(int i = size-1; i >= 0; i--)
		if('0'<=string[i] && string[i] <= '9'){
			num += (string[i] - '0')*power;
			power *= 10;
		}
		else if(i==0 && string[i]=='-')
			num *= -1;
	return num; 
}

int StringSize(char string[]){
	int i;
	for(i=0; string[i] != '\0'; i++)
		;
	return i;
}