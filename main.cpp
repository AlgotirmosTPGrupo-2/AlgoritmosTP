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
#include "tablahash.h"
#include "tablahash.cpp"
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
void opciones();
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
int contadorTerminales();
void crearTablaHash();





int main() {
    lecturaDeArchivoViajes();
    lecturaYCargoDeTerminales();
    
    
    //ordenar();

    
    opciones();
   
    
    return 0;

};
int contadorTerminales(){
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
    return lines.size();

}


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
    int opcion;
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
    cout<<"Esta Seguro que desea borrar la terminal ? \n 1. Si\n 2. No\n ";
    cin>>opcion;
    //correccion
    if(opcion==1){
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
    }
    else{cout<<"cancelada la eliminacion\n";}
};

void opciones(){
    while (numero != 6 )
    {
    cout << "\n\nMenu de Opciones" << endl;
    cout << "1. Mostrar todas las terminales" << endl;
    cout << "2. Agregar una terminal" << endl;
    cout << "3. Eliminar una terminal" << endl;
    cout << "4. Consultar Viaje      " <<endl;// falta colocar opcion en switch(grafo)
    cout << "5. Ver Tabla Hash de Terminales    " <<endl;
    cout << "6. Salir" << endl;


    cout<<"Ingrese un numero entre 1 y 6 segun desee: ";
    cin>>numero;


    switch(numero){
        case 1:
            imprimirTerminales();

             break;
        case 2:
            agregarTerminal();
            cout<<"presione una tecla para continuar" <<endl;
            cin.get();
            opciones();
           
            break;
        case 3:
            quitarTerminal();
            opciones();
            
           
             break;
        case 4:{
           float **costo= new float*[listaTerminales.size()];
           string **recorrido= new string*[listaTerminales.size()];
            for(int i=0;i<listaTerminales.size();i++){
            
            costo[i]=new float[listaTerminales.size()];
            recorrido[i]=new string[listaTerminales.size()];
            }
            Grafo grafo=Grafo();
            grafo.menuDeInicio(listaTerminales,costo,recorrido);
            grafo.liberar();
            opciones();
        }
            break;
        case 5:  
               
               crearTablaHash();
               break;
                
        case 6:
            cout << "Adios!" << endl; break;    

        default:
            cout<<"Opcion incorrecta";
            opciones();
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
            // for(int v=0; v<listaTerminales.size(); v++){ //Se recorre el vector para mostrar los datos
            //       if(listaTerminales[v].esMiCodigo(codigo_partida)){
            //         listaTerminales[v].addViaje(viaje_Nuevo);

            //       }
            //       else {
            //         CONTADOR_INCONSISTENCIAS=CONTADOR_INCONSISTENCIAS+1;
              
            //       }
            //   }   
             
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
            
            
            for(int v=0; v<listaDeViajes.size(); v++)
            { //Se recorre el vector para mostrar los datos
                   if(listaDeViajes[v].get_codigo_partida()==nombreT.get_codigo())
                   {
                    nombreT.addViaje(listaDeViajes[v]);
                    } 
            }        
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
      cout<< "   codigo  nombre      ciudad      pais           sup   cantTerm      cantDestNac    cantDestInter" <<endl;
};
void imprimirTerminales(){
    int op_orden;
   
    cout<< "\nSELECCIONE LA OPCION DE ORDENAMIENTO PARA LA VISUALIZACION DE TERMINALES   "<<endl;

    cout<<"INGRESE TIPO DE CONSULTA \n 1. CODIGO \n 2. NOMBRE \n 3. CIUDAD  \n 4. PAIS  \n ";
    //cout<<"INGRESE TIPO DE CONSULTA \n 1. CODIGO \n 2. NOMBRE \n 3. CIUDAD  \n 4. PAIS  \n 5. SUPERFICIE  \n 6. CANTIDAD DE TERMINALES  \n 7. DESTINOS NACIONALES  \n 8. DESTINOS INTERNACIONALES\n";
    cin>>op_orden;
    
    cout<< "\n\n\t ** MOSTRANDO LA LISTA DE TERMINALES SIN ORDENAR ** "<<endl;    
    imprimirListaTerminalesOrdenada(op_orden);    
    ordenar(op_orden);
    cout<< " \n\n\t** MOSTRANDO LA LISTA DE TERMINALES ORDENADA ** "<<endl;
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
        case 5:
             return convierteAStringF(t.get_superficie());     
        case 6:
             return convierteAStringInt(t.get_cantidadTerminales());  
        case 7:
             return convierteAStringInt(t.get_destinosNacionales());  
        case 8:
             return convierteAStringInt(t.get_destinosInternacionales());                    
        
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

    
    cabeceraDeTerminal();
    for(int i=0; i< listaTerminales.size();i++){
        cout<<i+1<<" * " ;
        listaTerminales[i].imprimir();
    }
};

//COMIENZA TABLA HASH
void crearTablaHash(){
    int opcion,pos;
    string eleccion;
    int tamanioTabla=int(contadorTerminales()/.8);
   
    Terminal *tabla =new Terminal[tamanioTabla];
    for (int i = 0; i < tamanioTabla; i++)
		{

          
			Terminal nombre=Terminal("vacio","A","A","A",float(1.00),1, 1,1);
			tabla[i]=nombre;
			
			//cout<<i<<endl;
        }
    TablaHash tablaHash=TablaHash(listaTerminales,tabla);   
    tablaHash.cargarMuchosElementos();
    cout<<"\nELEGIR \n 1. MOSTRAR TABLA \n 2. BUSCAR ELEMENTO \n 3. ELIMINAR ELEMENTO DE LA TABLA \n 4. SALIR DE MENU HASH \n";
    cin>>opcion; 
    while (opcion !=4)
    {
        if (opcion==1){tablaHash.imprimirTablaHash();}
        if(opcion==2){
            cout<<"INGRESAR CODIGO DE TERMINAL A BUSCAR \n";
            cin>>eleccion; 
            pos=tablaHash.buscarElemento(eleccion);}
        if(opcion==3){
            cout<<"INGRESAR CODIGO DE TERMINAL A ELIMINAR \n";
            cin>>eleccion; 
            tablaHash.eliminarElementoDeTabla(eleccion);
            tablaHash.imprimirTablaHash();
            } 
        cout<<"\nELEGIR \n 1. MOSTRAR TABLA \n 2. BUSCAR ELEMENTO \n 3. ELIMINAR ELEMENTO DE LA TABLA \n 4. SALIR DE MENU HASH \n";
        cin>>opcion;        /* code */
    }
    

    
    

}



