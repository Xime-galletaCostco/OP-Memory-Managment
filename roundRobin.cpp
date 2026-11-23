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
#include "procesos.hpp"	  // aqui se define el tipo de dato Proceso que es una struct
#include "printQueue.hpp" // contiene la funcion que imprime la memoria de izq a der ultimo a primer elemento respectivamente
#include "primerAjuste.hpp"
#include "peorAjuste.hpp"
#include "printList.hpp"   //imprimir la memoria
#include "SPresionada.hpp" //Para que el usuario pare la ejecución
#include "menuPrincipal.hpp"
#include "config.hpp"

void roundRobin(std::list<Bloque> &memoria, Paquete datos)
{
	// variables de round robin
	int sig_id = 0;
	int ciclo = 0;		// ciclo ;)
	bool salir = false; // Bandera para la salida

	std::queue<Proceso> mainQueue; // cola de procesos listos (se puede renombrar a readyQueue si se implementa la bloquedQueue)
	/*Alguna vez aqui habian variables y couts, ya no mas*/
	std::queue<Proceso> newQueue;
	// aqui quiten esto linea 27
	// newQueue = procesos(procesosCant); // aqui se llena la cola, se llama a la funcion de alex mandando como parametro la cantidad de procesos deseada

	do
	{
		std::cout << "---\n";

		Proceso procesoNuevo = procesos(datos.maxSize, datos.procQuantum);
		procesoNuevo.id = ++sig_id;
		newQueue.push(procesoNuevo);
		// NO MUEVAN LA LOGICA DE LOS AJUSTES CON ESO YA ESTA BIEN

		// debug, modificacion de el orden para imprimir
		if (!newQueue.empty())
		{
			std::cout << "\tEntra Proceso ";
			printProcess(newQueue.front());
			std::cout << "\nMemoria de " << datos.memSize << " KB ";
			if (datos.allocatorFlag == 1)
			{
				if (primerAjuste(memoria, newQueue.front()))
				{
					printList(memoria);
					mainQueue.push(newQueue.front());
					newQueue.pop();
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
			}
		} // cierre de condicional para colocacion, es para que no nos confundamos
		// bloque interfaz
		// debug de bloque interfaz para que cuadre la salida esperada
		if (mainQueue.empty())
		{
			break;
		} // si no hay ninguno por atender pues se sale
		std::cout << "\tAtendiendo proceso [" << mainQueue.front().id << "," << mainQueue.front().tam << "," << mainQueue.front().cuanto << "]" << std::endl;
		std::queue<Proceso> copiaRR;
		copiaRR = mainQueue;
		copiaRR.pop();
		std::cout << "\tLista RR ";
		printQueue(copiaRR);

		// bloque bucle:
		for (int i = 0; i < datos.sysQuantum; i++)
		{
			if (SPresionada())
			{ // aquí se verifica por segunda vez, en el ciclo de los bloques
				salir = true;
				break;
			}
			if (mainQueue.empty())
			{
				break;
			}
			mainQueue.front().cuanto--;
			if (mainQueue.front().cuanto > 0)
			{
				if (i == (datos.sysQuantum - 1))
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
					//printList(memoria);
				}
			}
			else
			{
				int idTerminado = mainQueue.front().id;
				// debug crear lo necesario para imprimir la salida buscada
				int tamTerminado = mainQueue.front().tam;
				mainQueue.pop();
				std::cout << "Descargando proceso[" << idTerminado << "," << tamTerminado << "," << "0]" << std::endl;
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
				std::cout << "Condensando huecos";
				std::cout << std::endl; // aqui se tiene que poner que imprima la lista doble enlazada
				printList(memoria);
				break;
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(datos.velocidad_ms));

		ciclo++;
	} while (!salir);
	if (salir)
	{
		std::cout << "Ejecucion detenida por el usuario" << std::endl;
	}
}
