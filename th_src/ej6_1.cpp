#include <iostream>

using namespace std;

int MayorSecuenciaMonotona(const int entrada[], int salida[], int tamanio_e);
void CopyIntArray(const int entrada[], int salida[], int inicio, int fin);
void PrintIntArray(const int entrada[], int tamanio);

int main(){
	int	cadena1[100] = {0,1,0,1,2},
		cadena2[100],
		tamanio = 5,
		tamanio_s;

	tamanio_s = MayorSecuenciaMonotona(cadena1, cadena2, tamanio);
	PrintIntArray(cadena2,tamanio_s);
}

void PrintIntArray(const int entrada[], int tamanio){
	for(int i=0; i < tamanio; i++){
		cout << entrada[i];
	}
	cout << endl;
}

//Asume un array con un elemento al menos
int MayorSecuenciaMonotona(const int entrada[], int salida[], int tamanio){
	int	contador = 1,
		ini = 0,
		fin = 1,
		ini_t = ini;
	bool mayor;

	for(int i=1; i < tamanio; i++){
		mayor = entrada[i] >= entrada[i-1];
		if(mayor)
			contador++;
		if(!mayor || i == tamanio - 1){
			if (contador > fin-ini){
				ini = ini_t;
				fin = ini + contador;
			}
			ini_t = i;
			contador = 1;	
			
		}
	}
	CopyIntArray(entrada, salida, ini, fin);
	return fin-ini;
}

void CopyIntArray(const int entrada[], int salida[], int inicio, int fin){
	for(int i=inicio; i < fin; i++){
		salida[i-inicio] = entrada[i];	
	}
}
