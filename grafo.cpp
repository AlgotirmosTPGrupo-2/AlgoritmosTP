
#include <iostream>
#include "terminal.h"
#include "grafo.h"
#include<string>
#include<string.h>
#include<vector>
#define MEDIDA_MATRIZ 4 
using namespace std;



    vector <Terminal> vectorTerminales;
    
    
   


    
    Grafo::Grafo(vector <Terminal> _vectorTerminales){
        vectorTerminales=_vectorTerminales;
    };//constructor

    



void Grafo :: floydWarshall(){
  
   
  int costo[MEDIDA_MATRIZ][MEDIDA_MATRIZ];
  string recorrido[medida][medida];
    

vector  <vector <int> distancias = this->ady;
for(int i = 0; i < n; i++) //n: cantidad de nodos
        distancias[i][i] = 0;
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++){
                int dt = distancias[i][k] + distancias[k][j];
                if(dt < distancias[i][j])
                    distancias[i][j] = dt; 
                    }
return distancias;}
