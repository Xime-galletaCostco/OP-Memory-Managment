/*
funcion round robin por Zachenleth

a diferencia del codigo de alex, aqui no utilice la linea "using namespace std;" por costumbre.
en su lugar use std::--- antes de cada sentencia como queue, stack o cout para llamarlas individualmente (si se requiere cambiar no hay problema)
*/

#include <iostream>
// Cabeceras para el delay (las tome del codigo de alexander)
#include <chrono>
#include <thread>
// Cabeceras propias
#include "procesos.hpp" // aqui se define el tipo de dato Proceso que es una struct
#include "printQueue.hpp" // contiene la funcion que imprime la memoria de izq a der ultimo a primer elemento respectivamente

// cambien la funcion main por void roundRobin("parametro"). Si necesitan una salida cambien el void por el tipo de dato.
int main() {
	//variables de round robin
	int cuantoSys = 4; // esta variable debe cambiar en ejecucion
	int procesosCant = 4; // esta tambien
	int ciclo = 0; // ciclo ;)

	int velocidad_ms = 600; // para el delay

	std::queue<Proceso> mainQueue; // cola de procesos listos (se puede renombrar a readyQueue si se implementa la bloquedQueue)
	std::queue<Proceso>newQueue;
	newQueue = procesos(procesosCant); // aqui se llena la cola, se llama a la funcion de alex mandando como parametro la cantidad de procesos deseada

	do {
// bloque interfaz
		std::cout << "---\n";

		std::cout << "Ciclo: " << ciclo << "\t";

		std::cout << "Memoria: ";
		printQueue(mainQueue);

		std::cout << "Proceso en Ejecucion: ";
		std::cout << "["
		<< mainQueue.front().id
		<< ", "
		<< mainQueue.front().tam
		<< ", "
		<< mainQueue.front().cuanto
		<< "]\n ";

// bloque bucle: 
		for (int i = 0; i < cuantoSys; i++) {
			if (mainQueue.empty()) {
				break;
			}

			std::cout << "Quantum: " << i << "\t";
			std::cout << "["
			<< mainQueue.front().id
			<< ", "
			<< mainQueue.front().tam
			<< ", "
			<< mainQueue.front().cuanto
			<< "]\n ";

			mainQueue.front().cuanto--;

			if (mainQueue.front().cuanto > 0) {
				if (i == (cuantoSys-1)) {
					Proceso temp = mainQueue.front();
					mainQueue.pop();
					mainQueue.push(temp);
				}
			} else {
				mainQueue.pop();
				break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(velocidad_ms));
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(velocidad_ms));

		ciclo++;
	} while (!mainQueue.empty());

	return 0;
}