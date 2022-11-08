#include "viaje.h"
#include <iostream>
#include<string>
#include<string.h>
using namespace std;



    Viaje::Viaje(string _codigo_partida,string  _codigo_destino,int _costo_viaje,float _horas_viaje){
        codigo_partida=_codigo_partida;
        codigo_destino=_codigo_destino;
        horas_viaje=_horas_viaje;
        costo_viaje= _costo_viaje;

    };//constructor


    string Viaje::get_codigo_partida (){
        return codigo_partida;

    };
    string Viaje::get_codigo_destino (){
        return codigo_destino;
    };
    int Viaje:: get_costo_viaje (){
        return costo_viaje;
    };
    float Viaje::get_horas_viaje(){
        return horas_viaje;
    };
    void Viaje::imprimir(){
        cout<<"origen :"<<codigo_partida<< " destino :"<< codigo_destino<<"costo : "<<costo_viaje<<"horas de viaje : "<< horas_viaje<<endl;
    };

