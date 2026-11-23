#include <iostream>
#include <list>
#include "roundRobin.hpp"
#include "config.hpp"

using namespace std;
int main(){
    cout<<"Bienvenido estimado usuario"<<endl;
    cout<<"Para la memoria se tienen tres tam,eliga la opcion que le sea conveninente: "<<endl ;
    cout<<"1)1024 KB"<<endl;
    cout<<"2)4096 KB"<<endl;
    cout<<"3)8192 KB "<<endl;
    cout<<"Su respuesta: ";
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
    cout<<"Para la memoria se tienen tres tam,eliga la opcion que le sea conveninente: "<<endl ;
    cout<<"1)1024 KB"<<endl;
    cout<<"2)4096 KB"<<endl;
    cout<<"3)8192 KB "<<endl;
    cout<<"Su respuesta: ";
    cin>>opc;
        break;
    }
    cout<<"Elija el tiempo de duracion de quantum del sistema: ";
    int numQ,numProceso;
    cin>>numQ;
    cout<<"Elija el metodo para colocacion de memoria: 1) Primer Ajuste       2)Peor ajuste"<<endl;
    int ajuste;
    cin>>ajuste;
    switch (ajuste)
    {
    case  1:
    break;
        //pues nada porque si esta bien
        case 2:
        break;
        //otra vez pues nada;
        default:
        cout<<"Elija dentro de las opciones disponibles, por favor:"<<endl;
        cout<<" 1) Primer Ajuste       2)Peor ajuste"<<endl;
        cin>>ajuste;
        break;
    }
    cout<<"Presione Ctrl+C para parar el programa"<<endl;
    //cout<<"Elija el numero de procesos: ";
    //cin>>numProceso;
    numProceso=50;
	// metemos el bloque inicial a la memoria
	memoria.push_front(inicial);
    roundRobin(memoria,numQ,numProceso,ajuste);
	return 0;
}