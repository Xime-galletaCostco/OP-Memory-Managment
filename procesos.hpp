#pragma once
#include <queue>

typedef struct {
	int id;
	int tam;
	int cuanto;
} Proceso;

std::queue<Proceso> procesos(int);