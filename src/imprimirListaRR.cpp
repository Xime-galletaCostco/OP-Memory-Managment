#include <iostream>
#include <queue>
#include "OPMMLib\procesos.hpp"
#include "OPMMLib\printQueue.hpp"
void imprimirListaRR(std::queue<Proceso>copiamain){
    std::cout<<"Lista RR:"<<std::endl;
    if(!copiamain.empty()){
        printQueue(copiamain);
        std::cout<<std::endl;
    }
}