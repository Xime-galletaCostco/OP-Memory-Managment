#include <iostream>
#include "menuPrincipal.hpp"

Paquete menuPrincipal()
{
    Paquete datos;
    int opc = 0;

    std::cout << "Bienvenido estimado usuario" << std::endl;
    do
    {
        std::cout << "Para la memoria se tienen tres tam,eliga la opcion que le sea conveninente: " << std::endl;
        std::cout << "1)1024 KB\t2)4096 KB\t3)8192 KB\n";
        std::cout << "Su respuesta: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1:
            datos.memSize = 1024;
            break;
        case 2:
            datos.memSize = 4096;
            break;
        case 3:
            datos.memSize = 8192;
            break;
        default:
            std::cout << "Intente de nuevo\n";
            break;
        }
    } while (opc < 1 || opc > 3);

    opc = 0;
    std::cout << "---\n";

    do
    {
        std::cout << "Elija el metodo de colocacion de memoria:\n1) Primer Ajuste\t2)Peor ajuste" << std::endl;
        std::cout << "Su respuesta: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1:
            datos.allocatorFlag = 1;
            break;
        case 2:
            datos.allocatorFlag = 2;
            break;
        default:
            std::cout << "Intente de nuevo\n";
            break;
        }
    } while (opc < 1 || opc > 2);
    
    opc = 0;
    std::cout << "---\n";

    do
    {
        std::cout << "Elija la velocidad de ejecucion:\n1) Lenta\t2) Normal\t3) Rapida" << std::endl;
        std::cout << "Su respuesta: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1:
            datos.velocidad_ms = 1500;
            break;
        case 2:
            datos.velocidad_ms = 100;
            break;
        case 3:
            datos.velocidad_ms = 500;
            break;
        default:
            std::cout << "Intente de nuevo\n";
            break;
        }
    } while (opc < 1 || opc > 3);

    std::cout << "---\n";
    std::cout << "Quantum del Sistema: ";
    std::cin >> datos.sysQuantum;
    std::cout << "---\n";
    std::cout << "Tamano maximo (minimo 32): ";
    std::cin >> datos.maxSize;
    std::cout << "---\n";
    std::cout << "Cuanto maximo: ";
    std::cin >> datos.procQuantum;

    return datos;
}
