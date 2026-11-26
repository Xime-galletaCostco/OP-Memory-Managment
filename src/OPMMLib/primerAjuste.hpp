#pragma once
#include <list>
#include "config.hpp"
bool primerAjuste(std::list<Bloque>&memoria,Proceso process);
void liberarMemoria(std::list<Bloque>&memoria,int id);
void liberarDeVerdad(std::list<Bloque>&memoria);