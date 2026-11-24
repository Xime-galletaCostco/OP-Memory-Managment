#include <iostream>
#include <list>
#include "OPMMLib\config.hpp"

// funcion para poder imprimir la lista con los procesos en memoria
void printList(const std::list<Bloque> &memoria)
{ // como solo imprimimos no lo pasamos por referencia
    for (auto it = memoria.begin(); it != memoria.end(); it++)
    {
        std::cout << "[";
        std::cout << it->process.id << ",";
        std::cout << it->size << ",";
        std::cout << it->process.cuanto << "]";
    }
    // la Salida esperada si tenemos dos bloques seria [1,300,2][0,200,0]
    return;
}