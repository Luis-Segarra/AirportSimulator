//Runway.h
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015



#ifndef RUNWAY_H
#define RUNWAY_H


class Runway
{
    public:
        Runway();
        ~Runway();
        bool isBusy();
        void updateRunway(int);
        void newPlane(int start, int requiredTime);

        void clearRunway();

    private:
        int startTime;
        int timeNeeded;
        bool busy;
};

#endif // RUNWAY_H
