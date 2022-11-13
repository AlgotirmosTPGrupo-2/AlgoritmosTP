#include "nodo.h"
#include "terminal.h"
#include "viaje.h"
//#include "terminal.cpp"



Nodo::Nodo(Terminal t)
{
    dato = t;
    siguiente = 0;
}

void Nodo::cambiar_dato(Terminal d)
{
    dato = d;
}

void Nodo::cambiar_siguiente(Nodo* s)
{
    siguiente = s;
}

Terminal Nodo::obtener_dato()
{
    return dato;
}

Nodo* Nodo::obtener_siguiente()
{
    return siguiente;
}
