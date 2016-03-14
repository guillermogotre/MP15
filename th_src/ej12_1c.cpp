#include <iostream>
#include <cmath>
using namespace std;

void GetMorseCode(int n, char string[]);
void AppendToString(char origin[], char to_add[]);
void StringInsert(char origin[], char to_add[], int pos);
int StringSize(char string[]);
void IntToList(int n, int list[]);

int main(){
	char string[100] = "",
		white_space[] = " ",
		morse[6];
	int n,
		list[10],
		i = 0;
	
	do{
		cout << "Numero: ";
		cin >> n;
	}while(n < 0);

	IntToList(n, list);
	while(list[i]!=-1){
		GetMorseCode(list[i++],morse);
		AppendToString(string,morse);
		AppendToString(string,white_space);
	}
	cout << string << endl;
}

void IntToList(int n, int list[]){
	int size = int(log10(n)+1),
		divi;
	for(int i=0; i < size; i++){
		divi = pow(10,size-i-1);
		list[i] = n / divi;
		n %= divi;
	}
	list[size]=-1;
}

void GetMorseCode(int n, char string[]){
	char base[] = ".....";
	if(n<5)
		for(int i=4; i>=n; i--)
			base[i] = '-';
	else if(n>5)
		for(int i=0; i<n-5; i++)
			base[i] = '-';
	for(int i=0; i < 5; i++)
		string[i] = base[i];
	string[5]='\0';
}

void AppendToString(char origin[], char to_add[]){
	StringInsert(origin, to_add, StringSize(origin));
}

void StringInsert(char origin[], char to_add[], int pos){
	int origin_size = StringSize(origin),
		to_add_size = StringSize(to_add);
	
	pos = (pos<0)? 0:pos;
	pos = (pos>origin_size)? origin_size:pos;

	for(int i = origin_size-1; i >= pos; i--)
		origin[i + to_add_size] = origin[i];
	
	for(int i = 0; i < to_add_size; i++)
		origin[i + pos] = to_add[i];

	origin[origin_size + to_add_size] = '\0';
}

int StringSize(char string[]){
	int i;
	for(i=0; string[i] != '\0'; i++)
		;
	return i;
}