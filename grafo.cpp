
#include <iostream>
#include "terminal.h"

#include "grafo.h"


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
       // cout<<"ingresa a primer for"<<primero<<endl;	
	  for (int segundo=0; segundo< v;segundo++){

            costo[segundo][primero] =INFINITO;
        
            recorrido[segundo][primero]=vectorTerminales[primero].get_codigo();
                  
                   
        
    }
    }
}  
void Grafo::cargarMatrices2(){
    int v=vectorTerminales.size();
    cout<<v<<endl;
    bool coincidencia=false;

    string cod_a_buscar;
    int valor_a_asignar;
    for (int primero = 0; primero < v;primero++)	{		
       
	  for (int segundo=0; segundo< v;segundo++){
         
		    for (int tercero=0; tercero< v;tercero++){	
                 	
                
              
              
                if ( !coincidencia && (segundo<vectorTerminales[primero].getListadeViajes().size()) &&(vectorTerminales[primero].getListadeViajes()[segundo].get_codigo_destino()==vectorTerminales[tercero].get_codigo()))	{	
                           
                            coincidencia=true;
                            costo[primero][tercero]=vectorTerminales[primero].getListadeViajes()[segundo].get_costo_viaje();
                } 
                       
                //cout<<  costo[primero][tercero]<<primero<<segundo<<tercero<<" "; 
                   }    
            
            coincidencia=false;
            //cout<<endl;
           
                    
                   
        
    }
    }
}
          

void Grafo::imprimirMatrices(){
    int v=vectorTerminales.size();
  
    for (size_t i = 0; i < v; i++)
    {
        for (size_t j = 0; j < v; j++)
        {
           cout<<costo[i][j]<<" ";
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
