#include "terminal.h"
#include "viaje.h"
#include <iostream>
#include<string>
#include<string.h>
using namespace std;


    vector<Viaje> listaDeMisViajes; 
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
    vector<Viaje> Terminal :: getListadeViajes(){
        return listaDeMisViajes;
    } 

    string Terminal::get_codigo(){
        return codigo;
    };
    void Terminal::addViaje(Viaje v){
         listaDeMisViajes.push_back(v);
    };
    void Terminal::imprimir(){
        string espacios;
        std::string strCod(espacios);
        strCod.insert(0, 5, ' ');
        int repNombre= 12 - (nombre.length());
        std::string strNom(espacios);
        strNom.insert(0, repNombre, ' ');

        int repCiudad= 12 - (ciudad.length());
        std::string strCiu(espacios);
        strCiu.insert(0, repCiudad, ' ');

        int repPais= 15 - (pais.length());
        std::string strPais(espacios);
        strPais.insert(0, repPais, ' ');

        cout<< codigo<<strCod<<nombre<<strNom<<ciudad<<strCiu<< pais<<strPais<< superficie<<"        " <<cantidadTerminales<<"               "<<destinosNacionales<<"            " <<destinosInternacionales<<endl;
    };
    bool Terminal::esMiCodigo(string cod){
        return codigo==cod;

    };
    void Terminal::imprimirViajes(){
        if (listaDeMisViajes.size()>0){
        cout<<"***** TERMINAL  : "<<codigo<<" ******   DESTINOS DISPONIBLES ****** "<<endl;
        for(int v=0; v<listaDeMisViajes.size(); v++){
             
            listaDeMisViajes[v].imprimir();
            cout<<endl; 

        }
    }
    };