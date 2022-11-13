
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


void Grafo:: menuDeInicio(){
    inicializarMatrices();
    imprimirMatrices();
    floydWarshall();
    imprimirMatrices();
    solicitarDatosAUsuario();



}
void Grafo :: imprimirTer(){ 
for(int v=0; v<vectorTerminales.size(); v++){ //Se recorre el vector para mostrar los datos
        cout<<v+1<<". ";
        vectorTerminales[v].imprimir();
     }
     cout<<endl;
}

void Grafo::inicializarMatrices(){
    int v=vectorTerminales.size();
  
    for (int primero = 0; primero < v;primero++)	{		
       
	  for (int segundo=0; segundo< v;segundo++){
            costo[segundo][primero] =INFINITO;
        
            recorrido[segundo][primero]=vectorTerminales[primero].get_codigo();
        }
    }
    cargarMatrices2();
}  
void Grafo::cargarMatrices2(){// carga los costos de inicio
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

int Grafo :: cantDigitos( int numero){// para que la impresion salga prol
    int cifras=1;
    while (numero>=10){
        numero=numero/10;
        cifras++;
    }
    return cifras;
}
void Grafo :: solicitarDatosAUsuario(){
    int origenT,destinoT;
   
    cout<< "\nTERMINALES DISPONIBLES, ELIJA ORIGEN Y DESTINO DEL VIAJE A CONSULTAR   "<<endl;

    imprimirTer();

    cout<<"INGRESE NUMERO DE TERMINAL DE ** ORIGEN ** ";
    cin>>origenT;
    cout<<"INGRESE NUMERO DE TERMINAL DE ** DESTINO ** ";
    cin>>destinoT;

    costoViaje(vectorTerminales[origenT-1].get_codigo(), vectorTerminales[destinoT-1].get_codigo());

}

void Grafo :: costoViaje(string origen, string destino){
        int posicionOrigen;
        int posicionDestino;
        string origenACoincidir;
        string destinoACoincidir;
        for (int i = 0; i < vectorTerminales.size(); i++)
        {
            origenACoincidir=vectorTerminales[i].get_codigo();
            destinoACoincidir=vectorTerminales[i].get_codigo();
           if(origen == origenACoincidir){
               posicionOrigen=i;
           }
           if(destino == destinoACoincidir){
               posicionDestino=i;
           }
        }
      //  if (posicionOrigen==undefined ||posicionDestino==NULL){cout<<"ingreso de terminal inexistente "}
    cout<<"\n EL COSTO DEL VIAJE DE :"<< origen<<" HASTA "<<destino<<" ES DE $ "<<costo[posicionOrigen][posicionDestino]<<endl;
        consultaRecorridoPorcosto(origen,destino);
       
}

void Grafo:: consultaRecorridoPorcosto(string origen,string destino) {
    
    string detalle_de_viaje=""+destino;
    int posOrigen=dev_Posicion(origen);
    int posDestino=dev_Posicion(destino);
    int nuevoDestino=0;
    while (recorrido[posOrigen][posDestino] !=destino){
        destino=recorrido[posOrigen][posDestino];
        detalle_de_viaje=destino+" , "+detalle_de_viaje;
        posDestino=dev_Posicion(recorrido[posOrigen][posDestino]);

        


    }
    detalle_de_viaje=origen+" , "+detalle_de_viaje;
    cout<<"Siendo su recorrido el siguiente :   " <<detalle_de_viaje<<"\n"<<endl;




}
int  Grafo:: dev_Posicion(string codigo){
    int respuesta =99;
    for (int i = 0; i < vectorTerminales.size(); i++)
        {
          if(vectorTerminales[i].get_codigo()==codigo){
            respuesta=i;
          } 
}
return respuesta;
}
