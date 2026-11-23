#include <cstdlib>
#include <ctime>
#include "procesos.hpp"

Proceso procesos(int tam_max_proceso, int cuanto_max_proceso) {
	srand((unsigned)time(NULL));

	Proceso p;
	p.id = 0;
	p.tam = 32 + (rand() % (tam_max_proceso - 32 + 1));
	p.cuanto = 1 + (rand() % cuanto_max_proceso);

	return p;
}
