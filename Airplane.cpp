//Airplane.cpp
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015

#include "Airplane.h"
#include <stdlib.h>

Airplane::Airplane(int currentTime, int maxFuel)
{
    fuelTime = rand()%maxFuel+5;
    startTime = currentTime;
}

Airplane::~Airplane()
{

}

int Airplane::getStartTime()
{
    return startTime;
}

int Airplane::getFuelTime()
{
    return fuelTime;
}

bool Airplane::didICrash(int currentTime)
{
        if((startTime - currentTime) >= fuelTime )
            return true;
        else
            return false;

}
