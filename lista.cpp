#include "lista.h"
//#include"nodo.cpp"
#include "terminal.h"
#include "viaje.h"
#include "nodo.h"
//#include "terminal.cpp"
//#include "stdlib.h"


Lista::Lista()
{
    primero = 0;
    largo = 0;
}

bool Lista::vacia()
{
    return (largo == 0);
}

void Lista::alta(Terminal d, int pos)
{
    Nodo* nuevo = new Nodo(d);
    if (pos == 1)
    {
        nuevo->cambiar_siguiente(primero);//cambia el siguiente del primero al nuevo
        primero = nuevo;//
    }
    else
    {
        Nodo* anterior = obtener_nodo(pos - 1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

Nodo* Lista::obtener_nodo(int pos)
{
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

Terminal Lista::consulta(int pos)
{
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();// la flechita se utiliza cuando desreferencia un puntero, trasnforma a un objeto y puedo llamar a una funcion 
}

void Lista::baja(int pos)
{
    Nodo* borrar;
    if (pos == 1)
    {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else
    {
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;//siempre tiene que haber un borrar, para liberar la memoria
    largo--;
}

Lista::~Lista()//destructor de la lista
{
    while (! vacia())
        baja(1);
}
/*OBTENER LARGO*/
int Lista::obtener_largo()
{
    return largo;
}

void Lista::mostrar()
{
      cout<<"[";

      if(!vacia())
      {
          for (int i = 1; i < largo; i++){
           this->consulta(i).imprimir();
             //cout<<this->consulta(largo);
       //     cout<<this->consulta(i)<<",";
       // cout<<this->consulta(largo);
          }
      }

      cout<<"]"<<endl;
}
 


 

