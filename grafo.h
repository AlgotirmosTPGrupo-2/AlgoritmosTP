#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#define MEDIDA_MATRIZ 5
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
    float costo[MEDIDA_MATRIZ][MEDIDA_MATRIZ];
    string recorrido[MEDIDA_MATRIZ][MEDIDA_MATRIZ];
    
    
   

public:
    
    Grafo(vector <Terminal>);//constructor
    void floydWarshall();
    void inicializarMatrices();
    void cargarMatrices2(int);
    void imprimirMatrices(int);
    void imprimirTer();
    int  cantDigitos( float );
    void costoViaje( string , string,int );  
    void consultaRecorridoPorCosto(string,string);
    int  dev_Posicion(string);
    void menuDeInicio();
    void solicitarDatosAUsuario();
    void liberar();
};
#endif // GRAFO_H_INCLUDED