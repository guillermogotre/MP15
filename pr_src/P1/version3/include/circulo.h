#ifndef _CIRCULO_H_
#define _CIRCULO_H_

#include "punto.h"

// Definición de las estructuras
struct Circulo {
    Punto centro; 
    double radio; 
};

// Prototipos de las funciones
void EscribirCirculo(const Circulo &c); 
Circulo LeerCirculo(); 
double AreaCirculo(const Circulo &c);
#endif
