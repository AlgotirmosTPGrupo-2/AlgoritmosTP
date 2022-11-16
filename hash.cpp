#define HashMod 30
#include<iostream>
using namespace std;

unsigned long long CharAEntero(char entrada)
{
	unsigned long long Salida;
	Salida = entrada;
	return Salida;
}
unsigned long long ObtenerNumero(string entrada)
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

int  FuncHash(string entrada)
{
	unsigned long long Amodular = ObtenerNumero(entrada);
	int Salida = Amodular%HashMod;
	return Salida;
}


main()
{
	string Tabla[30];
	for(int i = 0; i<30; i++)
	{
		Tabla[i]="null";
	}
			
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
			string Clave;
			
			cout<<"ingrese su clave: ";
			cin>>Clave;
			int Pos = FuncHash(Clave);
			cout<<"\nEl valor ascii es: "<<ObtenerNumero(Clave);
			cout<<"\nValor hash: "<<Pos;
			if(Tabla[Pos]=="null" || Tabla[Pos]==Clave)
				Tabla[Pos]=Clave;
			else
				for(int i=Pos;i<HashMod;i++)
					if(Tabla[i]=="null")
					{
						Tabla[i]=Clave;
						break;
					}
						
			
		}
		
		if(OpcMen == 2)
		{
			for(int i = 0; i<30; i++)
			{
				cout<<"Elemento #"<<i<<": "<<Tabla[i]<<"\n";
			}
		}

	cout<<"\n\n";
		
	}while(OpcMen!=0);
	
	
}
