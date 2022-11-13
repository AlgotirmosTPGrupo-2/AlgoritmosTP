#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include "nodo.h"
#include "terminal.h"
#include "viaje.h"
using namespace std;



class Lista/* una lista es un puntero a un PRIMER nodo*/
{
private:
    // atributos
    Nodo* primero;
    int largo;/* es el largo de la lista , para mejorar los metodos */

public:
    // constructor
    // pos: crea una cola vacia
    Lista();//constructor NO LLEVA PARAMETROS

    // pre: 0 < pos <= cantidad + 1
    // pos: inserta el dato d en la posicion pos, la 1 es la primera
    //        ademas incrementa cantidad en 1
    void alta(Terminal d, int pos);

    // pre: 0 < pos <= cantidad
    // pos: saca el elemento que esta en pos
    void baja(int pos);

    // pre: 0 < pos <= cantidad
    // pos: devuelve el elemento que esta en pos
    Terminal consulta(int pos);

    bool vacia();

    // pos: libera la memoria QUE OCUPÓ EL CONSTRUCTOR
    virtual ~Lista();//DESTRUCTOR

    int obtener_largo();
   
    void mostrar();
   
    
private:
    Nodo* obtener_nodo(int pos);
};

#endif // LISTA_H_INCLUDED
