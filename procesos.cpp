#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

struct Proceso {
    int id;
    int tam;
    int cuanto;
};

int main() {
    srand((unsigned)time(NULL));
    int sig_id = 0;
    int tam_max_proceso = 1024;
    int cuanto_max_proceso = 10;
    int velocidad_ms = 600;
    int total_ciclos = 10;

    for (int ciclo = 1; ciclo <= total_ciclos; ++ciclo) {
        Proceso p;
        p.id = ++sig_id;
        p.tam = 1 + (rand() % tam_max_proceso);
        p.cuanto = 1 + (rand() % cuanto_max_proceso);

        cout << "Ciclo " << ciclo << " -> Proceso P" << p.id
             << " | Tamano: " << p.tam << " KB"
             << " | Cuanto: " << p.cuanto << endl;

        this_thread::sleep_for(chrono::milliseconds(velocidad_ms));
    }
}