#include <iostream>
#include <string>

using namespace std;

struct Tiempo
{
	int horas,
		minutos,
		segundos;
};

int convertirASegundos(Tiempo tiempo){
	return tiempo.horas*3600 + tiempo.minutos*60 + tiempo.segundos;
}

Tiempo convertirATiempo(int seg){
	Tiempo tiempo;
	tiempo.horas = seg/3600;
	seg %= 3600;
	tiempo.minutos = seg/60;
	tiempo.segundos = seg%60;
	return tiempo;
}

bool esPosterior(Tiempo tiempo1, Tiempo tiempo2){
	return convertirASegundos(tiempo1) <= convertirASegundos(tiempo2);
}

Tiempo obtenerNuevoTiempo(Tiempo tiempo, int seg){
	return convertirATiempo(convertirASegundos(tiempo) + seg);
}

int main(){
	string salida;
	Tiempo
		tiempo1 = {1,1,1},
		tiempo2 = {2,2,2};

	salida = (esPosterior(tiempo1,tiempo2))?"true":"false";

	cout << salida << "\n";
	cout << convertirASegundos(tiempo1) << "\n";
	cout << convertirASegundos(obtenerNuevoTiempo(tiempo1,3601));
}
