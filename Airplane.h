//Airplane.h
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015

#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airplane
{

    public:
        Airplane(int, int);
        ~Airplane();
        int getStartTime();
        int getFuelTime();
        bool didICrash(int);

    private:
        int startTime;
        int fuelTime;
};

#endif // AIRPLANE_H
