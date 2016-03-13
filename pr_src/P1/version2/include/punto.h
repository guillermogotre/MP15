#ifndef _PUNTO_H_
#define _PUNTO_H_
// Definición de las estructuras
struct Punto {
    double x; 
    double y; 
};

//Prototipo
void EscribirPunto(const Punto &p); 
Punto LeerPunto(); 
double DistanciaPuntos(const Punto &p1, const Punto &p2);
Punto PuntoMedio(const Punto &p1, const Punto &p2);
#endif
