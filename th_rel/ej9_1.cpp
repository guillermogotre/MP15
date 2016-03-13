#include <iostream>
using namespace std;

void EliminaEspacios(char cadena[]);
bool IsPalindromo(char cadena[]);

int main(){
	char cadena[] = "al in ila";
	char pal = IsPalindromo(cadena)?'S':'N';
	cout << pal << endl;
}

void EliminaEspacios(char entrada[], char salida[]){
	int rd = 0,
		wrt = rd;
	do{
		if(entrada[rd] != ' '){
			salida[wrt++] = entrada[rd];
		}
	}while(entrada[rd++]!='\0');
}

bool IsPalindromo(char cadena[]){
	char limpia[100];
	int tamanio;
	bool palindromo = true;
	EliminaEspacios(cadena, limpia);
	for(tamanio=0; limpia[tamanio]!='\0'; tamanio++)
		;//Empty for
	for(int i=0; i < tamanio / 2 && palindromo; i++)
		palindromo = limpia[i] == limpia[tamanio -i -1];
	return palindromo;
}