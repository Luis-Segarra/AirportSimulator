//Runway.cpp
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015


#include "Runway.h"

Runway::Runway()
{
    startTime = 0;
    timeNeeded = 0;
    busy =  false;
}

Runway::~Runway()
{
    //dtor
}

/**
returns true if the expected time (startTime - timeNeeded) is less than the current time
**/

bool Runway::isBusy()
{
    return busy;
}

void Runway::updateRunway(int time)
{
    if((startTime - timeNeeded) <= time)
        busy = true;
     else
     {
         clearRunway();
     }

}

void Runway::newPlane(int start, int requiredTime)
{
    startTime = start;
    timeNeeded = requiredTime;
    busy = true;
}

void Runway::clearRunway()
{
    startTime = 0;
    timeNeeded = 0;
    busy = false;
}
