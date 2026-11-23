#include <iostream>
#include "OPMMLib\procesos.hpp"

void printProcess(Proceso process){
	std::cout << "["
		<< process.id
		<< ", "
		<< process.tam
		<< ", "
		<< process.cuanto
		<< "]";
}