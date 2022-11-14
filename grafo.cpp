#include <iostream>
#include "terminal.h"
#include<iomanip>
#include "grafo.h"
#include <stdio.h>
#include <math.h>

#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#define MEDIDA_primero 5 
#define INFINITO 999999,9

#define TERMINALES_CANTIDAD vectorTerminales.size()
using namespace std;



vector <Terminal> vectorTerminales;
float costo[MEDIDA_primero][MEDIDA_primero];
string recorrido[MEDIDA_primero][MEDIDA_primero];
  


    
Grafo::Grafo(vector <Terminal> _vectorTerminales){
        vectorTerminales=_vectorTerminales;
    };//constructor


void Grafo:: menuDeInicio(){
    inicializarMatrices();
    
    solicitarDatosAUsuario();

   



}
void Grafo :: imprimirTer(){ 
for(int v=0; v<TERMINALES_CANTIDAD; v++){ //Se recorre el vector para mostrar los datos
        cout<<v+1<<". ";
        vectorTerminales[v].imprimir();
     }
     cout<<endl;
}

void Grafo::inicializarMatrices(){
    int v=TERMINALES_CANTIDAD;
  
    for (int primero = 0; primero < v;primero++)	{		
       
	  for (int segundo=0; segundo< v;segundo++){
            costo[segundo][primero] =INFINITO;
        
            recorrido[segundo][primero]=vectorTerminales[primero].get_codigo();
        }
    }
   
}  
void Grafo::cargarMatrices2(int eleccion){// carga los costos de inicio
   
    string cod_a_buscar;
   // int valor_a_asignar;
    if (eleccion==1){
        for (int primero = 0; primero < TERMINALES_CANTIDAD;primero++)	{		
            for (int segundo=0; segundo<TERMINALES_CANTIDAD;segundo++){
                    for (int tercero=0; tercero< TERMINALES_CANTIDAD;tercero++){	
                        if (  (segundo<vectorTerminales[primero].getListadeViajes().size()) &&(vectorTerminales[primero].getListadeViajes()[segundo].get_codigo_destino()==vectorTerminales[tercero].get_codigo()))	{	
                                
                                costo[primero][tercero]=vectorTerminales[primero].getListadeViajes()[segundo].get_costo_viaje();
                    }   }}}  }
    else{
        for (int primero = 0; primero < TERMINALES_CANTIDAD;primero++)	{		
            for (int segundo=0; segundo<TERMINALES_CANTIDAD;segundo++){
                    for (int tercero=0; tercero< TERMINALES_CANTIDAD;tercero++){	
                        if (  (segundo<vectorTerminales[primero].getListadeViajes().size()) &&(vectorTerminales[primero].getListadeViajes()[segundo].get_codigo_destino()==vectorTerminales[tercero].get_codigo()))	{	
                                
                                costo[primero][tercero]=vectorTerminales[primero].getListadeViajes()[segundo].get_horas_viaje();
                    }   }}}  }

  }                
    

          

void Grafo::imprimirMatrices(int opcion){
    
    string espacios;
    int resultado;
    int precision;
    if(opcion==1){precision=0;}
    else{precision=2;}
    
    for (size_t i = 0; i < TERMINALES_CANTIDAD; i++)
    {
        for (size_t j = 0; j < TERMINALES_CANTIDAD; j++)
        {
        
        resultado =  cantDigitos(costo[i][j]);  
        int repCosto= 6 - resultado;
        std::string strCos(espacios);
        strCos.insert(0, repCosto, ' ');     
        cout<<strCos<<fixed<<setprecision(precision)<<costo[i][j]<<" ";
        }

        cout<<endl;
    }

      for (size_t i = 0; i <TERMINALES_CANTIDAD; i++)
    {
        for (size_t j = 0; j < TERMINALES_CANTIDAD; j++)
        {

           cout<<recorrido[i][j]<<" ";
        }
        cout<<endl;
    }
    
    

};


void Grafo :: floydWarshall(){
    int v=TERMINALES_CANTIDAD;
  
 
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

int Grafo :: cantDigitos( float numero){// para que la impresion salga prol
    int cifras=1;
    while (numero>=10){
        numero=numero/10;
        cifras++;
    }
    return cifras;
}
void Grafo :: solicitarDatosAUsuario(){
    int origenT,destinoT,eleccion;
   
    cout<< "\nTERMINALES DISPONIBLES, ELIJA ORIGEN Y DESTINO DEL VIAJE A CONSULTAR   "<<endl;

    imprimirTer();

    cout<<"INGRESE NUMERO DE TERMINAL DE ** ORIGEN **\n ";
    cin>>origenT;
    cout<<"INGRESE NUMERO DE TERMINAL DE ** DESTINO ** \n";
    cin>>destinoT;
    cout<<"INGRESE TIPO DE CONSULTA \n 1. por Costo \n 2. por Tiempo de Viaje \n";
    cin>>eleccion;

   
    cargarMatrices2(eleccion);
    //imprimirMatrices(eleccion);
    floydWarshall();
   
    costoViaje(vectorTerminales[origenT-1].get_codigo(), vectorTerminales[destinoT-1].get_codigo(),eleccion);
    cout<<"MATRICES CONSULTADAS"<<endl; 
    imprimirMatrices(eleccion);

}

void Grafo :: costoViaje(string origen, string destino,int eleccion){
        
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
    cout<<"\nEL COSTO DEL VIAJE DE :"<< origen<<" HASTA "<<destino<<" ES DE $ "<<costo[posicionOrigen][posicionDestino]<<endl;
      consultaRecorridoPorCosto(origen,destino);
       
}

void Grafo:: consultaRecorridoPorCosto(string origen,string destino) {
    
    string detalle_de_viaje="";
    int posOrigen=dev_Posicion(origen);
    int posDestino=dev_Posicion(destino);
    int aux=posDestino;
    string auxDest=destino;
    while (recorrido[posOrigen][posDestino] !=destino){
        destino=recorrido[posOrigen][posDestino];//string
        
        posDestino=dev_Posicion(recorrido[posOrigen][posDestino]);//entero
        detalle_de_viaje="\n [ $  "+to_string(costo[posDestino][aux])+ " en el tramo "+destino+"-"+auxDest+"]"+detalle_de_viaje;
        aux=posDestino;
        auxDest=vectorTerminales[aux].get_codigo();
        


    }
    detalle_de_viaje="\n [ $  "+to_string(costo[dev_Posicion(origen)][aux])+ " en el tramo "+origen+"-"+auxDest+"]"+detalle_de_viaje;
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
