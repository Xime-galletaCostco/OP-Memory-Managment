#include "OPMMLib\config.hpp"
#include "OPMMLib\procesos.hpp"
#include <iostream>
using namespace std;
//funcion programada por XimenaR
bool primerAjuste(std::list<Bloque>&memoria,Proceso process){
    for(auto it=memoria.begin(); it!=memoria.end();it++){//se hace un ciclo for each porque manejamos con
        if(it->estado==true&&it->size>=process.tam){//aqui preguntamos si el nodo esta libre y si hay espacio suficiente para el proceso
            if(it->size>process.tam){
                //aqui se parte porque sobra espacio
                Bloque sobra;
                sobra.estado=true;
                sobra.inicio=it->inicio+process.tam;
                sobra.size=it->size-process.tam;
                sobra.process={0,0,0};
                memoria.insert(std::next(it),sobra);//aqui estamos metiendo a nuestro proceso en la lista
            }

            it->estado=false;
            it->process=process;
            it->size=process.tam;
            return true;
        }
    }
    return false;
}
void liberarMemoria(std::list<Bloque>& memoria, int id) {
    for (auto it = memoria.begin(); it != memoria.end(); ++it) {
        if (it->estado == false && it->process.id == id) { //aqui ya encontro el iterador
            it->estado = true;//vamos cambiando el bloque 
            it->process = {0, 0, 0};
            auto sig = std::next(it);
            if (sig != memoria.end() && sig->estado == true) {//es decir que esta libre siguiente
                it->size += sig->size; 
                memoria.erase(sig);   //borramos nodo siguiente ya que ya sse combino
            }
            if (it != memoria.begin()) {
                auto ant = std::prev(it);//checamos el nodo previo
                if (ant->estado == true) {
                    ant->size += it->size; //se suma a todo
                    memoria.erase(it);    //se borra iterador porque el inicio es de previo
                }
            }
            break;
        }
    }
}