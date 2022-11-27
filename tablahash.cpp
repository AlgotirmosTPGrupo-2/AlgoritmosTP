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
    
TablaHash::TablaHash(vector <Terminal> _vectorTerminales,Terminal *tabla){
        
		vectorTerminales=_vectorTerminales;
		Tabla=tabla;
		
        

    };//constructor



void TablaHash:: cargarUnElemento(Terminal laTerminal){
	string Clave=laTerminal.get_codigo();
			
                int Pos = FuncHash(Clave);
                cout<<"\nEl valor ascii es: "<<ObtenerNumero(Clave);
                cout<<"\nValor hash: "<<Pos;
                
               
				if(((Tabla[Pos].get_codigo().compare("vacio")) == 0) || Tabla[Pos].get_codigo()==Clave)
                    Tabla[Pos]= laTerminal;
                else
                    for(int i=Pos;i<TABLA_TAMANIO;i++)
                        if((Tabla[Pos].get_codigo().compare("vacio")) == 0 )
                        {
                            Tabla[i]=laTerminal;
                            break;
                        }

};

void TablaHash:: cargarMuchosElementos(){
	
	
	for(int i=0;i<TERMINALES_CANTIDAD;i++){

				string Clave=vectorTerminales[i].get_codigo();
			
                int Pos = FuncHash(Clave);
                cout<<"\nEl valor ascii es: "<<ObtenerNumero(Clave);
                cout<<"\nValor hash: "<<Pos<<endl;
              
                if(((Tabla[Pos].get_codigo().compare("vacio")) == 0)|| (Tabla[Pos].get_codigo()==Clave))
                    {
						Tabla[Pos]= vectorTerminales[i];
					}
                else
					{
					bool cont=false;
					int inicio=Pos;	
					while (!cont){	
                    for(int j=inicio;j<TABLA_TAMANIO;j++){
                        if ((Tabla[j].get_codigo().compare("vacio")) == 0)
                        {
                            Tabla[j]=vectorTerminales[i];
							cont=true;
                            break;
                        }
						
				     }
					 inicio=0;
					 }
}}
};



void TablaHash:: imprimirTablaHash(){
    for (int primero = 0; primero < TABLA_TAMANIO ;primero++)	{		
     
			cout<<"Elemento #"<<primero<<": "<<Tabla[primero].get_codigo()<<"\n";
	
    }   
};

unsigned long long TablaHash:: CharAEntero(char entrada) 
{
	unsigned long long Salida;
	Salida = entrada;
	return Salida;
};
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


