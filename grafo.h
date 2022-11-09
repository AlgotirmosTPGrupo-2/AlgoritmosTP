#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#define MEDIDA_MATRIZ 20
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
    
    Grafo(vector <Terminal> _vectorTerminales);//constructor
    void floydWarshall();
    void cargarMatrices();
    void imprimirMatrices();
    void imprimirTer();
    
};
#endif // GRAFO_H_INCLUDED