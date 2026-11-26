#include <cstdlib>
#include <ctime>
#include "OPMMLib\procesos.hpp"

Proceso procesos(int tam_max_proceso, int cuanto_max_proceso) {
    static bool semilla_iniciada = false;
    if (!semilla_iniciada) {
        srand((unsigned)time(NULL));
        semilla_iniciada = true;
    }

    Proceso p;
    p.id = 0;
    p.tam = 1 + (rand() % tam_max_proceso);
    p.cuanto = 1 + (rand() % cuanto_max_proceso);

    return p;
}
