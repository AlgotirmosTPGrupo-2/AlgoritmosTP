#include "terminal.h"
#include "viaje.h"
#include <iostream>
#include<string>
#include<string.h>
using namespace std;


    Terminal::Terminal(string _codigo,string _nombre,string _ciudad,string _pais,float _superficie,int _cantidadTerminales,int _destinosNacionales,int _destinosInternacionales){
        codigo=_codigo;
        nombre=_nombre;
        ciudad=_ciudad;
        pais=_pais;
        superficie=_superficie;
        cantidadTerminales=_cantidadTerminales;
        destinosNacionales=_destinosNacionales;
        destinosInternacionales=_destinosInternacionales;

    };//constructor


    string Terminal::get_codigo(){
        return codigo;
    };
    void Terminal::addViaje(Viaje v){
         listaDeMisViajes.push_back(v);
    };