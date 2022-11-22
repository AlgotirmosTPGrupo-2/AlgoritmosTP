#include <iostream>
#include "terminal.h"
#include<iomanip>
#include "grafo.h"
#include "tablahash.h"
#include <stdio.h>
#include <math.h>

#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>

#define TERMINALES_CANTIDAD vectorTerminales.size()
#define TABLA_TAMANIO int(vectorTerminales.size()/0.8)
using namespace std;

//vector <Terminal> vectorTerminales;
Terminal *Tabla;
    
TablaHash::TablaHash(){
        //vectorTerminales=_vectorTerminales;
        // float **costo=new float*[TERMINALES_CANTIDAD];
        // string **recorrido=new string*[TERMINALES_CANTIDAD];
        // for(int i=0;i<TERMINALES_CANTIDAD;i++){
        //     costo[i]=new float[TERMINALES_CANTIDAD];
        //     recorrido[i]=new string[TERMINALES_CANTIDAD];
        // }
    };//constructor


void TablaHash:: menuDeInicioHash(vector <Terminal> _vectorTerminales){
    
    vectorTerminales=_vectorTerminales;
    
    //tablaHash=_tablaHash;
    
    inicializarTabla();
       
    imprimirTablaHash();    
    
    
    // solicitarDatosAUsuario();
};

void TablaHash:: inicializarTabla(){
   
	int OpcMen=0;
	do
	{
		cout<<"---Menu hash---\n";
		cout<<"1. insertar clave\n";
		cout<<"2. ver elementos clave\n";
		cout<<"Ingrese su opcion: ";
		
		cin>>OpcMen;
		
		if(OpcMen == 1)
		{
            for(int i=0;i<TERMINALES_CANTIDAD;i++){
                string Clave=vectorTerminales[i].get_codigo();
			
                int Pos = FuncHash(Clave);
                cout<<"\nEl valor ascii es: "<<ObtenerNumero(Clave);
                cout<<"\nValor hash: "<<Pos;
                
                if(sizeof(Tabla[Pos])==0 || Tabla[Pos].get_codigo()==Clave)
                    Tabla[Pos]=vectorTerminales[i];
                else
                    for(int i=Pos;i<TABLA_TAMANIO;i++)
                        if(sizeof(Tabla[i])==0 )
                        {
                            Tabla[i]=vectorTerminales[i];
                            break;
                        }
		}
        }
		if(OpcMen == 2)
		{
			for(int i = 0; i<TABLA_TAMANIO; i++)
			{
				cout<<"Elemento #"<<i<<": "<<Tabla[i].get_codigo()<<"\n";
			}
		}

	cout<<"\n\n";
		
	}while(OpcMen!=0);
}  

void TablaHash:: imprimirTablaHash(){
    for (int primero = 0; primero < TABLA_TAMANIO ;primero++)	{		
        if(sizeof(Tabla[primero])!=0){
        Tabla[primero].imprimir();     
    }
    }   
}

unsigned long long TablaHash:: CharAEntero(char entrada) 
{
	unsigned long long Salida;
	Salida = entrada;
	return Salida;
}
unsigned long long TablaHash:: ObtenerNumero(string entrada)
{
	unsigned long long Salida=0;
	for(int i=0;entrada[i] != '\0';i++)
	{
		if(entrada[1+i] == '\0' && i==0)
			Salida+=CharAEntero(entrada[i]);
		else
		{
			if(i==0)
			{
				Salida += CharAEntero(entrada[i]);
				continue;
			}
			else
			{
				
				int miChar = CharAEntero(entrada[i]);
				if(miChar>99)
				{
					Salida*=1000;
				}
				else if(miChar>9)
				{
					Salida*=100;
				}
				
				Salida += miChar;
			}
				
			
		}
	}
	return Salida;
}

int TablaHash:: FuncHash(string entrada)
{
	unsigned long long Amodular = ObtenerNumero(entrada);
	int Salida = Amodular%TABLA_TAMANIO;
	return Salida;
}


