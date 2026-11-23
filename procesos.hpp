#pragma once

typedef struct {
	int id;
	int tam;
	int cuanto;
} Proceso;

Proceso procesos(int tam_max_proceso, int cuanto_max_proceso);
