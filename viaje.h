#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
#include <iostream>
#include<string>
#include<string.h>
using namespace std;

class Viaje/* una lista es un puntero a un PRIMER nodo*/
{
private:
    // atributos
    string codigo_partida,codigo_destino;
    int costo_viaje;
    float horas_viaje;
   

public:
    
    Viaje(string _codigo_partida,string  _codigo_destino,int _costo_viaje,float _horas_viaje);//constructor


    string get_codigo_partida ();
    string get_codigo_destino ();
    int get_costo_viaje ();
    float get_horas_viaje();
    void imprimir();
};
#endif // VIAJE_H_INCLUDED