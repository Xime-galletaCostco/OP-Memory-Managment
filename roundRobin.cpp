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
#include "primerAjuste.hpp"
#include "peorAjuste.hpp"
#include "printList.hpp"//imprimir la memoria
#include "SPresionada.hpp"//Para que el usuario pare la ejecución
// cambien la funcion main por void roundRobin("parametro"). Si necesitan una salida cambien el void por el tipo de dato.
void roundRobin(std::list <Bloque>&memoria,int cuaaan,int numProce,int ajuste) {
	//variables de round robin
 int sig_id = 0;
	int cuantoSys = cuaaan; // esta variable debe cambiar en ejecucion
	int procesosCant = numProce; // esta tambien
	int ciclo = 0; // ciclo ;)
	bool salir = false;//Bandera para la salida
	int velocidad_ms = 600; // para el delay

	std::queue<Proceso> mainQueue; // cola de procesos listos (se puede renombrar a readyQueue si se implementa la bloquedQueue)
	std::queue<Proceso>newQueue;
	//aqui quiten esto linea 27
	//newQueue = procesos(procesosCant); // aqui se llena la cola, se llama a la funcion de alex mandando como parametro la cantidad de procesos deseada

	do {
		if (SPresionada()) { //se verifica por primera vez que no se haya presionado la S
			salir = true;
			break;
		}
		Proceso procesoNuevo = procesos();
  procesoNuevo.id = ++sig_id;
  newQueue.push(procesoNuevo);
		//NO MUEVAN LA LOGICA DE LOS AJUSTES CON ESO YA ESTA BIEN

		//debug, modificacion de el orden para imprimir
		if(!newQueue.empty()){
		if(ajuste==1){
		if(primerAjuste(memoria,newQueue.front())){
			std::cout<<"Entra Proceso ["<<newQueue.front().id<<","
			<<newQueue.front().tam<<","<<newQueue.front().cuanto<<"]"<<std::endl;
			printList(memoria);
			mainQueue.push(newQueue.front());
			newQueue.pop();
		}}
		else if(ajuste==2){
			if(peorAjuste(memoria,newQueue.front())){
				std::cout<<"Entra Proceso ["<<newQueue.front().id<<","
			<<newQueue.front().tam<<","<<newQueue.front().cuanto<<"]"<<std::endl;
			printList(memoria);
			mainQueue.push(newQueue.front());
			newQueue.pop();
			}
		}
	}//cierre de condicional para colocacion, es para que no nos confundamos
// bloque interfaz
		//debug de bloque interfaz para que cuadre la salida esperada
		if(mainQueue.empty()){break;}//si no hay ninguno por atender pues se sale
		std::cout<<"Atendiendo proceso ["<<mainQueue.front().id<<","<<mainQueue.front().tam<<","<<mainQueue.front().cuanto<<"]"<<std::endl;
		std::queue<Proceso>copiaRR;
		copiaRR=mainQueue;
		copiaRR.pop();
		std::cout<<"Lista RR ";
		printQueue(copiaRR);



// bloque bucle: 
		for (int i = 0; i < cuantoSys; i++) {
			if (SPresionada()) { //aquí se verifica por segunda vez, en el ciclo de los bloques
				salir = true;
				break;
			}
			if (mainQueue.empty()) {
				break;
			}
			mainQueue.front().cuanto--;
			if (mainQueue.front().cuanto > 0) {
				if (i == (cuantoSys-1)) {
					Proceso temp = mainQueue.front();
					mainQueue.pop();
					mainQueue.push(temp);

					//Debug sincronizar cuanto en la lista e imprimir
					for(auto&b:memoria){
						if(!b.estado&&b.process.id==temp.id){
							b.process.cuanto=temp.cuanto;
							break;
						}
					}
					printList(memoria);
				}
			} else {
				int idTerminado=mainQueue.front().id;
				//debug crear lo necesario para imprimir la salida buscada
				int tamTerminado=mainQueue.front().tam;
				mainQueue.pop();
				std::cout<<"Descargando proceso["<<idTerminado<<","<<tamTerminado<<","<<"0]"<<std::endl;
				for(const auto&b:memoria){
					if(!b.estado&&b.process.id==idTerminado){
							std::cout<<"[0,"<<b.size<<",0]";
					}
					else{
						std::cout<<"["<<b.process.id<<","<<b.size<<","<<b.process.cuanto<<"]";
					}		
				}
				std::cout<<std::endl;
				liberarMemoria(memoria,idTerminado);//aqui ya sacamos ese proceso de la cola de listos y de ram
				std::cout<<"Condensando huecos";
				std::cout<<std::endl;//aqui se tiene que poner que imprima la lista doble enlazada
				printList(memoria);
				break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(velocidad_ms));
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(velocidad_ms));

		ciclo++;
	} while (!mainQueue.empty()||!newQueue.empty() && !salir);
	
}
