#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED
#include <iostream>
#include<string>
#include<vector>
#include "viaje.h"
#include "viaje.cpp"
using namespace std;

class Terminal/* una lista es un puntero a un PRIMER nodo*/
{
private:
    // atributos
    string codigo,nombre,ciudad,pais;
    float superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;
    vector<Viaje> listaDeViajes;
   

public:
    
    Terminal(string _codigo,string  _nombre,string _ciudad,string _pais,float _superficie,int _cantidadTerminales,int _destinosNacionales,int _destinosInternacionales);//constructor


    string get_codigo();
    
};
#endif // TERMINAL_H_INCLUDED