#include <iostream>
using namespace std;

void CopyCString(const char entrada[], char salida[]);
void PrintCString(const char cadena[]);

int main(){
	char entrada[100] = "abcdefghijklm",
		salida[100];
		
	CopyCString(entrada, salida);
	cout << salida;
}

void CopyCString(const char entrada[], char salida[]){
	int i = 0;
	do{
		salida[i] = entrada[i];
	}while(entrada[i++]!='\0');
}