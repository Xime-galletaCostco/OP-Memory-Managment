#include "config.hpp"
#include "procesos.hpp"

bool peorAjuste(std::list<Bloque>&memoria,Proceso process){
    auto peor=memoria.end();

    for(auto it=memoria.begin(); it!=memoria.end();it++){//primero se recorre toda la lista para encontrar el hueco más grande 
        if(it->estado==true&&it->size>=process.tam){//el bloque debe estar libre y tener espacio suficiente para el proceso
            if(peor==memoria.end()||it->size>peor->size){//si aun no hay bloque o este bloque es mas grande que el candidato actual
                peor=it;//este pasa a ser el nuevo bloque más grande 
            }
        }
    }

    if(peor==memoria.end()){//si nunca se encontró un bloque donde cupiera el proceso de retorna falso
        return false;
    }

    if(peor->size>process.tam){
        //aquí se parte porque sobra espacio
        Bloque sobra;
        sobra.estado=true;
        sobra.inicio=peor->inicio+process.tam;
        sobra.size=peor->size-process.tam;
        sobra.process={0,0,0};
        memoria.insert(std::next(peor),sobra);//el espacio sobrante queda como bloque libre justo despues del bloque ocupado
    }

    peor->estado=false;//el bloque elegido ahora esta ocupado
    peor->process=process;
    peor->size=process.tam;
    return true;
}
    