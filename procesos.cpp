#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <queue>
#include "procesos.hpp"

using namespace std;

queue<Proceso> procesos(int cantidad) {
	queue<Proceso> mainQueue;
    srand((unsigned)time(NULL));
    int sig_id = 0;
    int tam_max_proceso = 1024;
    int cuanto_max_proceso = 10;
    int velocidad_ms = 600;
    int total_ciclos = cantidad;

    for (int ciclo = 1; ciclo <= total_ciclos; ++ciclo) {
        Proceso p;
        p.id = ++sig_id;
        p.tam = 1 + (rand() % tam_max_proceso);
        p.cuanto = 1 + (rand() % cuanto_max_proceso);

	mainQueue.push(p);
    }

	return mainQueue;
}