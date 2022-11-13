#ifndef NODO_H_INCLUDED/*si no está definido nodo h definilo de esta manera para esto se crea el archivo(para eso se crea el archivo)*/
#define NODO_H_INCLUDED
#include "terminal.h"
#include "viaje.h"



class Nodo
{
private:
    // atributos
    Terminal dato;
    Nodo* siguiente;

public:
    // metodos
    // constructor
    // PRE:
    // POS: crea un nodo con dato = d y siguiente = 0
    Nodo(Terminal d);

    void cambiar_dato(Terminal d);/*set de dato*/

    void cambiar_siguiente(Nodo* s);/* set de suiguiente*/

    Terminal obtener_dato();/*getter de datos*/

    Nodo* obtener_siguiente();/*getter de siguiente*/
};

#endif // NODO_H_INCLUDED
