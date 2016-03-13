#include <iostream>
#include <cmath> 
#include "circulo.h"
using namespace std;

void EscribirCirculo(const Circulo &p)
{
	cout << p.radio << "-";
	EscribirPunto(p.centro);
}

Circulo LeerCirculo()
{
	Circulo c;
	char sep;

	cin >> c.radio >> sep;
	c.centro = LeerPunto();
	
	return c;
}

double AreaCirculo(const Circulo &c)
{
	const double PI = 3.14;
	return PI*pow(c.radio,2);
}
