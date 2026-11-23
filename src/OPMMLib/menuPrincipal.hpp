#pragma once

/*Paquete: una estructura que colecciona todos los datos necesarios
para la ejecucion y que se deben definir para el usuario, servira para
crear el menu principal*/
typedef struct {
    int memSize;    // opc
    int sysQuantum; // numQ
    int velocidad_ms;   // velocidad_ms
    int allocatorFlag;  // ajuste
    int maxSize;    // tam_max
    int procQuantum; // cuanto_max
} Paquete;

Paquete menuPrincipal();