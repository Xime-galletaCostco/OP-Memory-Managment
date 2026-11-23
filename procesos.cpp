#include <cstdlib>
#include <ctime>
#include "procesos.hpp"

Proceso procesos() {
	srand((unsigned)time(NULL));
	int tam_max_proceso = 1024;
	int cuanto_max_proceso = 10;

	Proceso p;
	p.id = 0;
	p.tam = 1 + (rand() % tam_max_proceso);
	p.cuanto = 1 + (rand() % cuanto_max_proceso);

	return p;
}
