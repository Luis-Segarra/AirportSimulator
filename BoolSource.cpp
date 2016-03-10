//BoolSource.cpp
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015

#include "BoolSource.h"
#include <stdlib.h>
#include<iostream>
BoolSource::BoolSource(float prob)
{
    probability = (100 * prob);
}

bool BoolSource::computeProb()
{
    if(((rand()%100)+1) <= probability)
        return true;
    else
        return false;
}

