#include "config.hpp"
#include "procesos.hpp"
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