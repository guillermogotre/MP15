#include <iostream>
#include <string>
#include "imagen.h"

using namespace std;

int main(){
	const int MAX_CSTR_SIZE = 100;
	const int MAX_ASCII_ART = 4500;
	Imagen imagen;
	char ascii_chars[MAX_CSTR_SIZE], 
		file_path[MAX_CSTR_SIZE],
		ascii_art[MAX_ASCII_ART];

	cout << "Introduzca la ruta del archivo:";
	cin.getline(file_path, MAX_CSTR_SIZE);

	cout << "Introduzca los caracteres de conversion:";
	cin.getline(ascii_chars, MAX_CSTR_SIZE);

	if(!imagen.leerImagen(file_path))
		cout << "Error leyendo imagen" << endl;
	
	if(imagen.aArteASCII(ascii_chars, ascii_art, MAX_ASCII_ART))
		cout << ascii_art;
	else
		cout << "Error transformando a ASCIIart" << endl;
}