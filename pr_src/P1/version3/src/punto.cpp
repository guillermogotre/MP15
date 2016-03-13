#include <iostream>
#include <cmath> 
#include "punto.h"
using namespace std;

void EscribirPunto(const Punto &p)
{
	cout << "(" << p.x << "," << p.y << ")" << endl;
}

Punto LeerPunto()
{
	Punto p;
	char sep;
	
	cin >> sep >> p.x >> sep >> p.y >> sep;
	
	return p;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

Punto PuntoMedio(const Punto &p1, const Punto &p2)
{
	Punto p = {(p1.x + p2.x)/2,(p1.y + p2.y)/2};
	return p;
}

