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
#include "OPMMLib\procesos.hpp"	  // aqui se define el tipo de dato Proceso que es una struct
#include "OPMMLib\printQueue.hpp" // contiene la funcion que imprime la memoria de izq a der ultimo a primer elemento respectivamente
#include "OPMMLib\primerAjuste.hpp"
#include "OPMMLib\peorAjuste.hpp"
#include "OPMMLib\printList.hpp"   //imprimir la memoria
#include "OPMMLib\SPresionada.hpp" //Para que el usuario pare la ejecución
#include "OPMMLib\menuPrincipal.hpp"
#include "OPMMLib\config.hpp"
#include "OPMMLib\imprimirListaRR.hpp"
void roundRobin(std::list<Bloque> &memoria, Paquete datos)
{
	// variables de round robin
	int sig_id = 0;
	int ciclo = 0;		// ciclo ;)
	bool salir = false; // Bandera para la salida
	Proceso procesoNuevo;

	std::queue<Proceso> mainQueue; // cola de procesos listos (se puede renombrar a readyQueue si se implementa la bloquedQueue)
	/*Alguna vez aqui habian variables y couts, ya no mas*/
	std::queue<Proceso> newQueue;
	// aqui quiten esto linea 27
	// newQueue = procesos(procesosCant); // aqui se llena la cola, se llama a la funcion de alex mandando como parametro la cantidad de procesos deseada

	do
	{
		std::cout << "\n--- Ciclo: " << ciclo << ", Ajuste: ";
		if (datos.allocatorFlag == 1)
		{
			std::cout << "Primer Ajuste ---";
		}
		else if (datos.allocatorFlag == 2)
		{
			std::cout << "Peor Ajuste ---";
		}
		ciclo++;

		procesoNuevo = procesos(datos.maxSize, datos.procQuantum);
		procesoNuevo.id = ++sig_id;
		newQueue.push(procesoNuevo);
		// NO MUEVAN LA LOGICA DE LOS AJUSTES CON ESO YA ESTA BIEN (Solo se movio la impresion)

		// debug, modificacion de el orden para imprimir
		if (!newQueue.empty())
		{
			std::cout << "\nEntra Proceso: ";
			printProcess(newQueue.front());
			std::cout << "\nMemoria: ";
			if (datos.allocatorFlag == 1)
			{
				if (primerAjuste(memoria, newQueue.front()))
				{
					printList(memoria);
					mainQueue.push(newQueue.front());
					newQueue.pop();
				}
				else
				{
					printList(memoria);
				}
			}
			else if (datos.allocatorFlag == 2)
			{
				if (peorAjuste(memoria, newQueue.front()))
				{
					printList(memoria);
					mainQueue.push(newQueue.front());
					newQueue.pop();
				}
				else
				{
					printList(memoria);
				}
			}
		} // cierre de condicional para colocacion, es para que no nos confundamos
		// bloque interfaz
		// debug de bloque interfaz para que cuadre la salida esperada
		if (mainQueue.empty())
		{
			break;
		} // si no hay ninguno por atender pues se sale
		std::cout << "\n> Atendiendo proceso: [" << mainQueue.front().id << "," << mainQueue.front().tam << "," << mainQueue.front().cuanto << "]" << std::endl;

		// bloque bucle(se fue el bucle, ahora solo resta el cuanto):
		mainQueue.front().cuanto -= datos.sysQuantum; // aqui se le resta el quantum al proceso que esta en la cabeza de la cola

		if (mainQueue.front().cuanto > 0)
		{
			if (mainQueue.front().cuanto == (datos.sysQuantum - 1))
			{
				Proceso temp = mainQueue.front();
				mainQueue.pop();
				mainQueue.push(temp);

				// Debug sincronizar cuanto en la lista e imprimir
				for (auto &b : memoria)
				{
					if (!b.estado && b.process.id == temp.id)
					{
						b.process.cuanto = temp.cuanto;
						break;
					}
				}
				imprimirListaRR(mainQueue);
			}
		}
		else
		{
			int idTerminado = mainQueue.front().id;
			// debug crear lo necesario para imprimir la salida buscada
			int tamTerminado = mainQueue.front().tam;
			mainQueue.pop();

			imprimirListaRR(mainQueue);
			std::cout << "\nDescargando proceso: [" << idTerminado << "," << tamTerminado << "," << "0]" << std::endl;
			for (const auto &b : memoria)
			{
				if (!b.estado && b.process.id == idTerminado)
				{
					std::cout << "[0," << b.size << ",0]";
				}
				else
				{
					std::cout << "[" << b.process.id << "," << b.size << "," << b.process.cuanto << "]";
				}
			}
			std::cout << std::endl;
			liberarMemoria(memoria, idTerminado); // aqui ya sacamos ese proceso de la cola de listos y de ram
			std::cout << "Condensando huecos: ";
			printList(memoria);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(datos.velocidad_ms));

		std::cout << std::endl;
		if (SPresionada())
		{ // aquí se verifica por segunda vez, en el ciclo de los bloques
			salir = true;
			break;
		}
	} while (!salir);
	if (salir)
	{
		std::cout << "\nEjecucion detenida por el usuario\n" << std::endl;
	}
}
