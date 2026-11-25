#include <iostream>
#include <list>
#include "OPMMLib\roundRobin.hpp"
#include "OPMMLib\config.hpp"
#include "OPMMLib\menuPrincipal.hpp"

using namespace std;
int main()
{
    bool salir = false; // Bandera para la salida
    int opc = 0;

    list<Bloque> memoria;
    Bloque inicial;

    Paquete datos;

    cout << "Bienvenido estimado usuario" << endl;
    do
    {
        cout << "1) Iniciar simulacion\t2) Salir" << endl;
        std::cout << "Su respuesta: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            datos = menuPrincipal();

            inicial.size = datos.memSize;
            memoria.push_front(inicial);

            roundRobin(memoria, datos);
            break;
        case 2:
            break;
        default:
            cout << "Intente de nuevo\n";
            break;
        }
    } while (opc != 2);

    /*
    int opc = 0;
    int numQ = 0;
    int velocidad_ms = 0;
    int ajuste = 0;

    # Esta fue la primera version de menu principal
    Fue movida a una funcion independiente por facilidad de lectura #

    cout << "Bienvenido estimado usuario" << endl;

    //do
    //{
        switch (opc)
        {
        case 1:
            inicial.size = 1024;
            break;
        case 2:
            inicial.size = 4096;
            break;
        case 3:
            inicial.size = 8192;
            break;

        default:
            cout << "Para la memoria se tienen tres tam,eliga la opcion que le sea conveninente: " << endl;
            cout << "1)1024 KB\t2)4096 KB\t3)8192 KB\n";
            cout << "Su respuesta: ";
            cin >> opc;
            break;
        }

        cout << "Quantum del sistema: ";
        cin >> numQ;

        switch (ajuste)
        {
        case 1:
            break;
        // pues nada porque si esta bien ; Zachenleth: ah sos re troll XD
        case 2:
            break;
        // otra vez pues nada;
        default:
            cout << "Elija el metodo de colocacion de memoria:\n1) Primer Ajuste\t2)Peor ajuste" << endl;
            cout << "Su respuesta: ";
            cin >> ajuste;
            break;
        }

        switch (velocidad_ms)
        {
        case 1:
            velocidad_ms = 1000;
            break;
        case 2:
            velocidad_ms = 600;
            break;
        case 3:
            velocidad_ms = 300;
            break;
        default:
            cout << "Elija la velocidad de ejecucion:\n1) Lenta\t2) Normal\t3) Rapida" << endl;
            cout << "Su respuesta: ";
            cin >> velocidad_ms;
            break;
        }

        cout << "\nNota: Para terminar la ejecucion presione s" << endl;
        // metemos el bloque inicial a la memoria
        memoria.push_front(inicial);
        roundRobin(memoria, numQ, ajuste, velocidad_ms);

    //} while (opc != 9);
    return 0;
    */
}