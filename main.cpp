#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>

#include<sstream>
#include "viaje.cpp"
#include "viaje.h"
#define DELIMITADOR_CAMPOS " "
#define ARCHIVO_DE_VIAJES "Viajes.txt"



using namespace std;

void mostrarDatos();
void opciones();
void agregarTerminal();
void quitarTerminal();
int convierteAInt(string i);
float convierteAFloat(string i);
void lecturaDeArchivoViajes();
int numero;
int main() {
    lecturaDeArchivoViajes();
    opciones();
    return 0;

}

void mostrarDatos(){ //Funcion para mostrar los datos del archivo
    string line;
    vector<string> lines; //Vector para guardar los datos del archivo
    ifstream myfile ("terminales.txt", ios::in);
  //  ifstream myfile ("C:/Users/Administrador/CLionProjects/untitled/terminales.txt", ios::in); //Se abre el archivo en modo lectura
    if (myfile.is_open()){ //Si el archivo se abre
        while(getline(myfile,line)){ //y se pueda leer una linea
            lines.push_back(line); //Se guarda en el vector
        }
        myfile.close(); //al salir del ciclo se cierra el archivo
    }
    else cout<<"No se puede abrir el archivo";

    for(int i=0; i<lines.size(); ++i){ //Se recorre el vector para mostrar los datos
        cout<<lines[i]<<'\n';
    }
}

void agregarTerminal(){
    ofstream myfile;
    myfile.open("terminales.txt", ios::app);
   // myfile.open("C:/Users/Administrador/CLionProjects/untitled/terminales.txt", ios::app); //Se abre el archivo en modo append
    string codigo, nombre, ciudad, pais;
    float superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;
    cout<<"Ingrese el codigo de la terminal: ";
    cin>>codigo;cout<<endl;
    cout<<"Ingrese el nombre de la terminal: ";
    cin>>nombre;cout<<endl;
    cout<<"Ingrese la ciudad de la terminal: ";
    cin>>ciudad;cout<<endl;
    cout<<"Ingrese el pais de la terminal: ";
    cin>>pais;cout<<endl;
    cout<<"Ingrese la superficie de la terminal: ";
    cin>>superficie;cout<<endl;
    cout<<"Ingrese la cantidad de terminales de la terminal: ";
    cin>>cantidadTerminales;cout<<endl;
    cout<<"Ingrese la cantidad de destinos nacionales de la terminal: ";
    cin>>destinosNacionales;cout<<endl;
    cout<<"Ingrese la cantidad de destinos internacionales de la terminal: ";
    cin>>destinosInternacionales;cout<<endl;
    myfile<<codigo<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidadTerminales<<" "<<destinosNacionales<<" "<<destinosInternacionales<<endl; //Se escribe en el archivo
    myfile.close(); //Se cierra el archivo
}

void quitarTerminal(){
    string line;
    vector<string> lines; //Se crea un vector para guardar los datos del archivo

    ifstream myfile ("terminales.txt", ios::in);
   // ifstream myfile ("C:/Users/Administrador/CLionProjects/untitled/terminales.txt", ios::in);  //Se abre el archivo en modo lectura
    if (myfile.is_open()){ //Si el archivo se abre
        while(getline(myfile,line)){ //y se pueda leer una linea
            lines.push_back(line); //Se guarda en el vector
        }
        myfile.close();
    }
    else cout<<"No se puede abrir el archivo";

    for(int i=0; i<lines.size(); ++i){ //Se recorre el vector para mostrar los datos
        cout<<i+1<<") "<<lines[i]<<'\n'; //Se muestra el numero de la linea y los datos
    }
    cout<<"Ingrese el numero de la terminal que desea eliminar: "; //Se pide el numero de la linea que se desea eliminar
    cin>>numero;
    lines.erase(lines.begin()+numero-1); //Se elimina la linea del vector
    ofstream myfile2; //Se crea un archivo nuevo

    myfile2.open("terminales.txt", ios::out);
   // myfile2.open("C:/Users/Administrador/CLionProjects/untitled/terminales.txt", ios::out); //Se abre el archivo nuevo en modo escritura
    for(int i=0; i<lines.size(); ++i){ //Se recorre el vector para escribir los datos en el archivo nuevo
        myfile2<<lines[i]<<endl;
    }
    myfile2.close(); //Se cierra el archivo nuevo
}

void opciones(){
    while (numero != 4 )
    {
    cout << "\n\nMenu de Opciones" << endl;
    cout << "1. Mostrar todas las terminales" << endl;
    cout << "2. Agregar una terminal" << endl;
    cout << "3. Eliminar una terminal" << endl;
    cout << "4. Salir" << endl;


    cout<<"Ingrese un numero entre 1 y 4 segun desee: ";
    cin>>numero;


    switch(numero){
        case 1:
            mostrarDatos(); break;
        case 2:
            agregarTerminal(); break;
        case 3:
            quitarTerminal(); break;
        case 4:
            cout << "Adios!" << endl; break;

        default:
            cout<<"Opcion incorrecta";
            opciones();
    }
}
}

 /// lectura de viajes   
void lecturaDeArchivoViajes(){ //Funcion para mostrar los datos del archivo
    string cadena,subcadena;
    string nombre;
    string codigo_partida,codigo_destino;
    float horas_viaje;
    int costo_viaje;
    int posInicio,posFin;
   
    vector<Viaje> listaDeViajes;// lista de todos los viajes en archivo
    int posLista=0;
    //vector<string> lines; //Vector para guardar los datos del archivo

    ifstream viajes (ARCHIVO_DE_VIAJES, ios::in);
  //Se abre el archivo en modo lectura
    if (viajes.is_open()){ //Si el archivo se abre
        
        while(getline(viajes,cadena)){
            stringstream ss;
            cout<<"registro Leido"<<cadena<<endl ;//y se pueda leer una linea
            posInicio=0;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            
            codigo_partida=subcadena;
            posInicio=posFin+1;
            
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            
            codigo_destino=subcadena;
            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            
            costo_viaje=convierteAInt(subcadena);
            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
           
            horas_viaje=convierteAFloat(subcadena);
            
            Viaje nombre=Viaje(codigo_partida,codigo_destino,costo_viaje,horas_viaje);
           
             listaDeViajes.push_back(nombre);
            
             
             posLista+=1;


             
           // lines.push_back(line); 
            

            //Se guarda en el vector
            // stringstream ss;
        }
        viajes.close(); //al salir del ciclo se cierra el archivo
    }
    else cout<<"No se puede abrir el archivo";

     for(int v=0; v<listaDeViajes.size(); v++){ //Se recorre el vector para mostrar los datos
         listaDeViajes[v].imprimir();
       
     }

}
int convierteAInt(string i){
    stringstream ss;
    int num;
    ss<<i;
    ss>>num;
    return num;
};
float convierteAFloat(string i){
    stringstream ss;
    float num;
    ss<<i;
    ss>>num;
    return num;
};


