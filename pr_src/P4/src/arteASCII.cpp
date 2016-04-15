#include <iostream>
#include <fstream>
#include <cstring>
#include <imagen.h>
#include <pgm.h>

using namespace std;

void concatTextNumFile(char * source, char * destination, int n);

int main(){
	const int MAX_CSTR_SIZE = 100;
	const int MAX_ASCII_ART = 60000;
	Imagen imagen;
	ifstream ifile;
	ofstream ofile;
	char ifile_path[MAX_CSTR_SIZE],
		ofile_path[MAX_CSTR_SIZE],
		ascii_path[MAX_CSTR_SIZE],
		ascii_chars[MAX_CSTR_SIZE],
		ascii_art[MAX_ASCII_ART];
	int n_ascii;


	cout << "Imagen de entrada: ";
	cin.getline(ifile_path, MAX_CSTR_SIZE);

	cout << "Fichero de caracteres: ";
	cin.getline(ascii_path, MAX_CSTR_SIZE);

	cout << "Fichero de salida: ";
	cin.getline(ofile_path, MAX_CSTR_SIZE);

	ifile.open(ascii_path);
	if(ifile && imagen.leerImagen(ifile_path)){

		//Descomentar para volver a escribir la imagen en formato PGM_TEXTO
		//imagen.escribirImagen(ofile_path, false); 

		char full_filename[MAX_CSTR_SIZE],
			file_sufix[] = "n.txt"; //Just up to 9 files

		ifile.ignore(100, '\n');
		ifile >> n_ascii;

		for(int i=1; i <= n_ascii; i++){

			file_sufix[0] = '0'+i; //Replace the n index
			strcpy(full_filename, ofile_path);
			strncat(full_filename, file_sufix, 10);

			ofile.open(full_filename);
			ifile >> ascii_chars;

			if(ifile && ofile){
				imagen.aArteASCII(ascii_chars,ascii_art, MAX_ASCII_ART);
				ofile << ascii_art;
				if(!ofile)
					cout << "Error escribiendo en el archivo " << ofile_path << endl;
			}
			else
				cout << "Error abriendo archivo " << ofile_path << endl;

			ofile.close();
		}
	}
	else
		cout << "Error de lectura de archivos" << endl;

}