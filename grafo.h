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
    
    
   

public:
    
    Grafo(vector <Terminal> _vectorTerminales);//constructor
    void Grafo :: floydWarshall();

    
};
#endif // GRAFO_H_INCLUDED