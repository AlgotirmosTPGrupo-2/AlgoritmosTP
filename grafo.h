#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include "terminal.h"
#include<string>
#include<string.h>
#include<vector>
using namespace std;

class Grafo
{
private:
    // atributos
    vector <Terminal> vectorTerminales;
    float **costo;
    string **recorrido;
    
    
   

public:
    
    Grafo();//constructor
    void floydWarshall();
    void inicializarMatrices();
    void cargarMatrices2(int);
    void imprimirMatrices(int);
    void imprimirTer();
    int  cantDigitos( float );
    void costoViaje( string , string,int );  
    void consultaRecorridoPorCosto(string,string,string);
    int  dev_Posicion(string);
    void menuDeInicio(vector <Terminal> _vectorTerminales,float **_costo,string **_recorrido);
    void solicitarDatosAUsuario();
    void liberar();
   
};
#endif // GRAFO_H_INCLUDED