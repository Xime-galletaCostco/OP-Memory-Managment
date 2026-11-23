#include <iostream>
#include "procesos.hpp"

void printProcess(Proceso process){
	std::cout << "["
		<< process.id
		<< ", "
		<< process.tam
		<< ", "
		<< process.cuanto
		<< "]";
}