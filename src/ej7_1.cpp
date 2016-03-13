#include <iostream>
using namespace std;

void LeerChars(char vector_char[]);
void ConteoCaracteres(const char vector_char[], int vector_int[]);

int main(){
	char vector_char[100];
	int n_letras = 'z'-'a'+1,
		vector_int[n_letras] = {};
		
	LeerChars(vector_char);
	ConteoCaracteres(vector_char, vector_int);
	
	for(int i = 0; i < n_letras; i++){
		cout << vector_int[i] << " ";
	}
}

void LeerChars(char vector_char[]){
	int i = 0;
	do{
		cin >> vector_char[i];
	}while(vector_char[i++]!='#');
}

void ConteoCaracteres(const char vector_char[], int vector_int[]){
	int i = 0;
	while(vector_char[i]!='#'){
		vector_int[tolower(vector_char[i++])-'a']++;
	}
}