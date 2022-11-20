#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include "terminal.h"
#include "terminal.cpp"
#include "grafo.h"
#include "grafo.cpp"
#include<sstream>
#include <bits/stdc++.h>
#include "viaje.h"
#define DELIMITADOR_CAMPOS " "
#define ARCHIVO_DE_VIAJES "viajes.txt"
#define ARCHIVO_DE_TERMINALES "terminales.txt"
#define GET_CODIGO get_codigo()
#define GET_SUP get_superficie()






using namespace std;

void mostrarDatos();
void opciones(Grafo);
void agregarTerminal();
void quitarTerminal();
int convierteAInt(string i);
float convierteAFloat(string i);
void lecturaDeArchivoViajes();
void lecturaYCargoDeTerminales();
void imprimirTerminales();
void cabeceraDeTerminal();
void crearClaseTerminal(string cadena);
//ordenamiento string
void ordenar(int);
void ordenarEntre(int,int desde, int hasta);
int acomodar(int,int,int,Terminal);
void imprimirListaTerminalesOrdenada(int);
string retornar_opcionS(int,Terminal);

//ordenamiento float
void ordenarF(int);
void ordenarEntreF(int,int desde, int hasta);
int acomodarF(int,int,int,Terminal);
void imprimirListaTerminalesOrdenadaF(int);
float retornar_opcionF(int,Terminal );

string convierteAStringF(float i);
string convierteAStringInt(int i);
void imprimirViajes2();//IMPRIMIR VIAJES POR TERMINAL
vector<Viaje> listaDeViajes;// lista de todos los viajes en archivo
int numero;
int CONTADOR_INCONSISTENCIAS;
vector<Terminal> listaTerminales;





int main() {
  
    lecturaYCargoDeTerminales();
    lecturaDeArchivoViajes();
    //ordenar();

   Grafo grafo=Grafo();
   opciones(grafo);
    
    
      
    
    return 0;

};


void mostrarDatos(){ //Funcion para mostrar los datos del archivo
    string line;
   
    
    vector<string> lines; //Vector para guardar los datos del archivo
    ifstream myfile (ARCHIVO_DE_TERMINALES, ios::in);
  
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
    myfile.open(ARCHIVO_DE_TERMINALES, ios::app);
   
    string codigo, nombre, ciudad, pais,cadena;
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


    cadena=codigo+DELIMITADOR_CAMPOS+nombre+DELIMITADOR_CAMPOS+ciudad+DELIMITADOR_CAMPOS+pais+ DELIMITADOR_CAMPOS+convierteAStringF(superficie)+DELIMITADOR_CAMPOS+convierteAStringInt(cantidadTerminales)+DELIMITADOR_CAMPOS+convierteAStringInt(destinosNacionales)+DELIMITADOR_CAMPOS+convierteAStringInt(destinosInternacionales);
    crearClaseTerminal(cadena);

    
    myfile<<codigo<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidadTerminales<<" "<<destinosNacionales<<" "<<destinosInternacionales<<endl; //Se escribe en el archivo
    //cout<<codigo<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidadTerminales<<" "<<destinosNacionales<<" "<<destinosInternacionales<<endl; //Se escribe en el archivo
    myfile.close(); //Se cierra el archivo
    
    
    
}

void quitarTerminal(){
    string line,codigo;
    vector<string> lines; //Se crea un vector para guardar los datos del archivo

    ifstream myfile (ARCHIVO_DE_TERMINALES, ios::in);//Se abre el archivo en modo lectura
  
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
    //correccion
    ofstream myfile3;
    myfile3.open(ARCHIVO_DE_TERMINALES, ios::out);//Se abre el archivo en modo lectura
    int borrar;
    for(int i=0; i<lines.size(); ++i){ //Se recorre el vector para escribir los datos en el archivo nuevo
        if (i==numero-1){
            borrar=i;
            int posInicio=0;
            int posFin=lines[i].find_first_of(DELIMITADOR_CAMPOS,posInicio);
            string subcadena=lines[i].substr(posInicio,(posFin-posInicio));
             codigo=subcadena;
            for(int i=0;i<listaTerminales.size();i++){
             if(codigo==listaTerminales[i].get_codigo()){
            listaTerminales.erase((listaTerminales.begin()+i));//se borra la clase instanciada de terminal de la lista de terminales también
        }
    } 
        };
    }
    myfile3.close(); //Se cierra el archivo nuevo
    
    lines.erase(lines.begin()+(numero-1)); //Se elimina la linea del vector
    ofstream myfile2; //Se crea un archivo nuevo

    myfile2.open(ARCHIVO_DE_TERMINALES, ios::out);//Se abre el archivo en modo lectura
   
    for(int i=0; i<lines.size(); ++i){ //Se recorre el vector para escribir los datos en el archivo nuevo
        myfile2<<lines[i]<<endl;
    }
    myfile2.close(); //Se cierra el archivo nuevo
    
};

void opciones(Grafo grafo){
    while (numero != 5 )
    {
    cout << "\n\nMenu de Opciones" << endl;
    cout << "1. Mostrar todas las terminales" << endl;
    cout << "2. Agregar una terminal" << endl;
    cout << "3. Eliminar una terminal" << endl;
    cout << "4. Consultar Viaje      " <<endl;// falta colocar opcion en switch(grafo)
    cout << "5. Salir" << endl;


    cout<<"Ingrese un numero entre 1 y 5 segun desee: ";
    cin>>numero;


    switch(numero){
        case 1:
            imprimirTerminales();

            //imprimirViajes2();
            
            mostrarDatos();
             break;
        case 2:
            agregarTerminal();
            cout<<"presione una tecla para continuar" <<endl;
            cin.get();
           
            break;
        case 3:
            quitarTerminal();
           
             break;
        case 4:{
           float **costo= new float*[listaTerminales.size()];
           string **recorrido= new string*[listaTerminales.size()];
            for(int i=0;i<listaTerminales.size();i++){
            
            costo[i]=new float[listaTerminales.size()];
            recorrido[i]=new string[listaTerminales.size()];
            }
           
            grafo.menuDeInicio(listaTerminales,costo,recorrido);
            grafo.liberar();
            opciones(grafo);
        }
            break;
        case 5:
            cout << "Adios!" << endl; break;    

        default:
            cout<<"Opcion incorrecta";
            opciones(grafo);
    }
}
};

 /// lectura de viajes   
void lecturaDeArchivoViajes(){ //Funcion para mostrar los datos del archivo
    string cadena,subcadena;
    string viaje_Nuevo;
    string codigo_partida,codigo_destino;
    float horas_viaje;
    int costo_viaje;
    int posInicio,posFin;
   
   
   

    ifstream viajes (ARCHIVO_DE_VIAJES, ios::in);
  //Se abre el archivo en modo lectura
    if (viajes.is_open()){ //Si el archivo se abre
        
        while(getline(viajes,cadena)){
            stringstream ss;
           
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
            
            Viaje viaje_Nuevo=Viaje(codigo_partida,codigo_destino,costo_viaje,horas_viaje);

// grabar en la lista que corresponde a la terminal
            for(int v=0; v<listaTerminales.size(); v++){ //Se recorre el vector para mostrar los datos
                  if(listaTerminales[v].esMiCodigo(codigo_partida)){
                    listaTerminales[v].addViaje(viaje_Nuevo);

                  }
                  else {
                    CONTADOR_INCONSISTENCIAS=CONTADOR_INCONSISTENCIAS+1;
                //   cout<<"punto de partida erroneo"<<endl;
                  }
              }   
             
             listaDeViajes.push_back(viaje_Nuevo);
            
        
          
        }
        viajes.close(); //al salir del ciclo se cierra el archivo
    }
    else cout<<"No se puede abrir el archivo";

    

};

void lecturaYCargoDeTerminales() {
     string cadena,subcadena;
   
    string codigo,nombre,ciudad,pais;
    float superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;
    //
    int posInicio,posFin;
   
    ifstream myfile (ARCHIVO_DE_TERMINALES, ios::in);
  
    if (myfile.is_open()){ //Si el archivo se abre
        while(getline(myfile,cadena)){ //y se pueda leer una linea
            stringstream ss;
            crearClaseTerminal(cadena);
            
        }
        myfile.close(); //al salir del ciclo se cierra el archivo
    }
    else cout<<"No se puede abrir el archivo";

  
    
    
       
     };
void crearClaseTerminal(string cadena){
     string subcadena;
   
    string codigo,nombre,ciudad,pais;
    float superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;
    //
    int posInicio,posFin;
     stringstream s;
     posInicio=0;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            codigo=subcadena;

            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            nombre=subcadena;

            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            ciudad=subcadena;

            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            pais=subcadena;

            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            superficie=convierteAFloat(subcadena);

            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            cantidadTerminales=convierteAInt(subcadena);

            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            destinosNacionales=convierteAInt(subcadena);

            posInicio=posFin+1;
            posFin=cadena.find_first_of(DELIMITADOR_CAMPOS,posInicio);
            subcadena=cadena.substr(posInicio,(posFin-posInicio));
            destinosInternacionales=convierteAInt(subcadena);

            Terminal nombreT=Terminal(codigo,nombre,ciudad,pais,superficie,cantidadTerminales, destinosNacionales,destinosInternacionales);
           
            listaTerminales.push_back(nombreT);

} ; 
void imprimirViajes2(){
     for(int v=0; v<listaTerminales.size(); v++){
       
        listaTerminales[v].imprimirViajes();
     }   

      
}   ;
    


void cabeceraDeTerminal(){
      cout<<endl;


      cout<< "****    ****    ****    ****    ****    ****    ****    ****    ****    ****    ****    ****" <<endl;
      cout<< "codigo  nombre      ciudad      pais           sup   cantTerm      cantDestNac    cantDestInter" <<endl;
};
void imprimirTerminales(){
    int op_orden;
   
    cout<< "\nSELECCIONE LA OPCION DE ORDENAMIENTO PARA LA VISUALIZACION DE TERMINALES   "<<endl;

   
    cout<<"INGRESE TIPO DE CONSULTA \n 1. CODIGO \n 2. NOMBRE \n 3. CIUDAD  \n 4. PAIS  \n ";
    cin>>op_orden;
    // //if(op_orden==5){
    //     ordenarF(op_orden);
    
    //     imprimirListaTerminalesOrdenadaF(op_orden);

    // }else {
    ordenar(op_orden);
    
    imprimirListaTerminalesOrdenada(op_orden);
    
    
     cout<<endl;
 } ;




int convierteAInt(string i){
    stringstream ss;
    int num;
    ss<<i;
    ss>>num;
    return num;
};
string convierteAStringF(float i){
    stringstream ss;
    ss<<i;
    string str=ss.str();
    return str;

} ;
string convierteAStringInt(int i){
    stringstream ss;
    ss<<i;
    string str=ss.str();
    return str;

} 

float convierteAFloat(string i){
    stringstream ss;
    float num;
    ss<<i;
    ss>>num;
    return num;
};
/// COMIENZA CODIGO DE ORDENAMIENTO     
void ordenar (int op_orden){
     ordenarEntre(op_orden,0, listaTerminales.size()-1);
};

void ordenarEntre (int op_orden,int desde, int hasta){
    if (desde<hasta){
        Terminal p = listaTerminales[desde];  //p es el pivot, un elemento cualquiera del vector
        int medio = acomodar(op_orden,desde, hasta , p);  
        swap(listaTerminales[desde],listaTerminales[medio]);
        ordenarEntre( op_orden,desde, medio-1);
        ordenarEntre(op_orden,medio+1,hasta);
    }
};
 float retornar_float(int op_orden ,Terminal t){
    return t.GET_SUP;
 };

string retornar_opcionS(int op_orden ,Terminal t){
 
    
    switch(op_orden){
          case 1:
             return t.get_codigo();
            
              break;
          case 2:
               return t.get_nombre();
           
            break;
        case 3:
             return t.get_ciudad();
           
             break;
        case 4:
             return t.get_pais();
        
        default:
            cout<<"   otra Opcion incorrecta";
           // opciones(grafo);
    }
}


int acomodar(int op_orden,int desde, int hasta, Terminal p){
 
    int i = desde, j = hasta;
    while(i<j){

        while(retornar_opcionS(op_orden,listaTerminales[i])<=retornar_opcionS(op_orden,p )&& i<j)
            {i++;}
        while(retornar_opcionS(op_orden,listaTerminales[j])>retornar_opcionS(op_orden,p) && i<j)
            {j--;}
        if(i<j)
            {swap(listaTerminales[i],listaTerminales[j]);}
    }
   // imprimirListaTerminalesOrdenada();
    return (retornar_opcionS(op_orden,listaTerminales[i]) < retornar_opcionS(op_orden,p) ? i: i-1 );
};

void imprimirListaTerminalesOrdenada(int op_orden){

    cout<< " ** MOSTRANDO LA LISTA DE TERMINALES ORDENADA ** "<<endl;
    for(int i=0; i< listaTerminales.size();i++){
        cout<<i+1<<" * " <<listaTerminales[i].get_codigo()<<" - "<<retornar_opcionS(op_orden,listaTerminales[i])<<endl;
    }
}


//// para float


// int acomodarF(int op_orden,int desde, int hasta, Terminal p){
 
//     int i = desde, j = hasta;
//     while(i<j){

//         while(retornar_opcionF(op_orden,listaTerminales[i])<=retornar_opcionF(op_orden,p )&& i<j)
//             {i++;}
//         while(retornar_opcionF(op_orden,listaTerminales[j])>retornar_opcionF(op_orden,p) && i<j)
//             {j--;}
//         if(i<j)
//             {swap(listaTerminales[i],listaTerminales[j]);}
//     }
//    // imprimirListaTerminalesOrdenada();
//     return (retornar_opcionF(op_orden,listaTerminales[i]) < retornar_opcionF(op_orden,p) ? i: i-1 );
// };

// void imprimirListaTerminalesOrdenadaF(int op_orden){

//     cout<< " ** MOSTRANDO LA LISTA DE TERMINALES ORDENADA ** "<<endl;
//     for(int i=0; i< listaTerminales.size();i++){
//         cout<<i+1<<" * " <<listaTerminales[i].get_codigo()<<" - "<<retornar_opcionF(op_orden,listaTerminales[i])<<endl;
//     }
// }
// void ordenarF (int op_orden){
//      ordenarEntreF(op_orden,0, listaTerminales.size()-1);
// };

// void ordenarEntreF (int op_orden,int desde, int hasta){
//     if (desde<hasta){
//         Terminal p = listaTerminales[desde];  //p es el pivot, un elemento cualquiera del vector
//         int medio = acomodarF(op_orden,desde, hasta , p);  
//         swap(listaTerminales[desde],listaTerminales[medio]);
//         ordenarEntreF( op_orden,desde, medio-1);
//         ordenarEntreF(op_orden,medio+1,hasta);
//     }
// };
