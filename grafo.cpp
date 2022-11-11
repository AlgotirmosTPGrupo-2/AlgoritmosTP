
#include <iostream>
#include "terminal.h"

#include "grafo.h"
#include <stdio.h>
#include <math.h>

#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#define MEDIDA_primero 5 
#define INFINITO 999999
using namespace std;



vector <Terminal> vectorTerminales;
int costo[MEDIDA_primero][MEDIDA_primero];
string recorrido[MEDIDA_primero][MEDIDA_primero];
  


    
Grafo::Grafo(vector <Terminal> _vectorTerminales){
        vectorTerminales=_vectorTerminales;
    };//constructor

void Grafo :: imprimirTer(){ 
for(int v=0; v<vectorTerminales.size(); v++){ //Se recorre el vector para mostrar los datos
         vectorTerminales[v].imprimir();
     }
     cout<<endl;
}

void Grafo::cargarMatrices(){
    int v=vectorTerminales.size();
    cout<<v<<endl;
    bool coincidencia=false;

    string cod_a_buscar;
    int valor_a_asignar;
    for (int primero = 0; primero < v;primero++)	{		
       
	  for (int segundo=0; segundo< v;segundo++){
            costo[segundo][primero] =INFINITO;
        
            recorrido[segundo][primero]=vectorTerminales[primero].get_codigo();
        }
    }
    cargarMatrices2();
}  
void Grafo::cargarMatrices2(){
    int v=vectorTerminales.size();
    cout<<v<<endl;
    string cod_a_buscar;
    int valor_a_asignar;
    for (int primero = 0; primero < v;primero++)	{		
       
	  for (int segundo=0; segundo< v;segundo++){
         
		    for (int tercero=0; tercero< v;tercero++){	
            
                if (  (segundo<vectorTerminales[primero].getListadeViajes().size()) &&(vectorTerminales[primero].getListadeViajes()[segundo].get_codigo_destino()==vectorTerminales[tercero].get_codigo()))	{	
                           
                        
                            costo[primero][tercero]=vectorTerminales[primero].getListadeViajes()[segundo].get_costo_viaje();
                } 
            
                   }    
           
        
    }
    }
}
          

void Grafo::imprimirMatrices(){
    int v=vectorTerminales.size();
    string espacios;
    int resultado;
  
    for (size_t i = 0; i < v; i++)
    {
        for (size_t j = 0; j < v; j++)
        {
        resultado =  cantDigitos(costo[i][j]);  
        int repCosto= 6 - resultado;
        std::string strCos(espacios);
        strCos.insert(0, repCosto, ' ');     
        cout<<strCos<<costo[i][j]<<" ";
        }
        cout<<endl;
    }
      for (size_t i = 0; i < v; i++)
    {
        for (size_t j = 0; j < v; j++)
        {

           cout<<recorrido[i][j]<<" ";
        }
        cout<<endl;
    }
    
    

};


void Grafo :: floydWarshall(){
    int v=vectorTerminales.size();
  
 
for(int i = 0; i < v; i++){ //n: cantidad de nodos
        costo[i][i] = 0;
        for(int k = 0; k < v; k++)
            for(int i = 0; i < v; i++){
             for(int j = 0; j <v; j++){
                int dt = costo[i][k] + costo[k][j];
                if(dt < costo[i][j]){
                    costo[i][j] = dt; 
                    recorrido[i][j]=vectorTerminales[k].get_codigo();//VERIFICAR
                    }
//return distancias;
}}}}

int Grafo :: cantDigitos( int numero){
    int cifras=1;
    while (numero>=10){
        numero=numero/10;
        cifras++;
    }
    return cifras;
}

int Grafo :: costoViaje(string origen, string destino){
        int posicionOrigen;
        int posicionDestino;
        string origenAControlar;
        string destinoAControlar;
        for (int i = 0; i < vectorTerminales.size(); i++)
        {
            origenAControlar=vectorTerminales[i].get_codigo();
            destinoAControlar=vectorTerminales[i].get_codigo();
           if(origen == origenAControlar){
               posicionOrigen=i;
           }
           if(destino == destinoAControlar){
               posicionDestino=i;
           }
        }
        cout<<posicionOrigen<<endl;
        cout<<posicionDestino<<endl;
        return costo[posicionOrigen][posicionDestino];
}
