#include <queue>
#include <list>
#include<iostream>
#include "procesos.hpp"
#pragma once
#define  SIZEONE 8192
#define  SIZETWO 4096 
#define  SIZETHREE 1024
#define  MINIMUNSIZE 32

struct Bloque{
    Proceso process;
    int inicio;
    int size;
    bool estado;
};


