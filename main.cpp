#pragma once
#include <iostream>
#include <list>
#include "roundRobin.hpp"
#include "config.hpp"

using namespace std;
int main(){
    cout<<"Bienvenido estimado usuario"<<endl;
    cout<<"Para la memoria se tienen tres tam,eliga la opcion que le sea conveninente: "<<endl ;
    cout<<"1)1024 GB"<<endl;
    cout<<"2)4096 GB"<<endl;
    cout<<"3)8192 GB "<<endl;
    cout<<"Su respuesta:";
    int opc;
    cin>>opc;
    list <Bloque>memoria;
    Bloque inicial;
    switch (opc)
    {
    case 1:
        inicial.size=1024;
        break;
        case 2:
        inicial.size=4096;
        break;
        case 3:
        inicial.size=8192;
        break;

    default:
        break;
    }
    cout<<"Elija el tiempo de duracion de cuantum"<<endl;
    int numQ,numProceso;
    cin>>numQ;
    cout<<"Elija el numero de procesos"<<endl;
    cin>>numProceso;
    roundRobin(memoria,numQ,numProceso);
}