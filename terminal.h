#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED
#include <iostream>
#include<string>
#include<vector>
#include "viaje.h"
#include "viaje.cpp"
#include<string.h>
using namespace std;

class Terminal
{
private:
    // atributos
    string codigo,nombre,ciudad,pais;
    float superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;
    vector<Viaje> listaDeMisViajes;
   

public:
    
    Terminal(string _codigo,string _nombre,string _ciudad,string _pais,float _superficie,int _cantidadTerminales,int _destinosNacionales,int _destinosInternacionales);//constructor


    string get_codigo();
    string get_nombre();
    string get_ciudad();
    string get_pais();
    float get_superficie();
    int get_cantidadTerminales();
    int get_destinosNacionales(); 
    int get_destinosInternacionales();
    void addViaje(Viaje);
    void imprimir();
    bool esMiCodigo(string);
    void imprimirViajes();
    vector<Viaje> getListadeViajes();
    
};
#endif // TERMINAL_H_INCLUDED