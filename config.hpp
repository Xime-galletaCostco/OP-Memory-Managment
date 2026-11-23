#pragma once
#include <queue>
#include <list>
#include<iostream>
#include "procesos.hpp"
#define  SIZEONE 8192
#define  SIZETWO 4096 
#define  SIZETHREE 1024
#define  MINIMUNSIZE 32

struct Bloque{
    Proceso process={0,0,0};
    int inicio=0;
    int size=0;
    bool estado=true;
};

void printProcess(Proceso);