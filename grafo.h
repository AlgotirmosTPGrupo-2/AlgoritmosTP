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
    int costo[MEDIDA_MATRIZ][MEDIDA_MATRIZ];
    string recorrido[MEDIDA_MATRIZ][MEDIDA_MATRIZ];
    
    
   

public:
    
    Grafo(vector <Terminal>);//constructor
    void floydWarshall();
    void inicializarMatrices();
    void cargarMatrices2();
    void imprimirMatrices();
    void imprimirTer();
    int  cantDigitos( int );
    void costoViaje( string , string );  
    void consultaRecorridoPorcosto(string,string);
    void consultaRecorridoPorCosto2(string,string);
    int  dev_Posicion(string);
    void menuDeInicio();
    void solicitarDatosAUsuario();
    void inicializarMatricesHoras();
    void cargarMatrices3();
    void imprimirMatricesHoras();
    void floydWarshallHoras();
};
#endif // GRAFO_H_INCLUDED