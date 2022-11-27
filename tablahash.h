#ifndef TABLAHASH_H_INCLUDED
#define TABLAHASH_H_INCLUDED

#include <iostream>
#include "terminal.h"
#include<string>
#include<string.h>
#include<vector>
using namespace std;

class TablaHash
{
private:
    // atributos
    vector <Terminal> vectorTerminales;  
    Terminal *Tabla;

public:
    
    TablaHash(vector <Terminal> _vectorTerminales,Terminal *tabla);//constructor
    //void menuDeInicioHash(vector <Terminal> _vectorTerminales);
    void inicializarTabla();
    void imprimirTablaHash();
    unsigned long long CharAEntero(char entrada);
    unsigned long long ObtenerNumero(string entrada);
    int FuncHash(string entrada);
    void cargarUnElemento(Terminal laTerminal);
    void cargarMuchosElementos();
    void liberar();
};
#endif // TABLAHASH_H_INCLUDED