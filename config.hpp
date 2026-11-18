#include <queue>
#include <list>
#include<iostream>
#pragma once
#define  SIZEONE 8192
#define  SIZETWO 4096 
#define  SIZETHREE 1024
#define  MINIMUNSIZE 32

struct Bloque{
    int id;//el cual va a ser unico
    int tamMax;
    int  qAsignado;
    int qMax;
};


