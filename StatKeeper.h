//StatKeeper.h
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015

#ifndef STATKEEPER_H
#define STATKEEPER_H


class StatKeeper
{
    public:
        StatKeeper();
        ~StatKeeper();
        void leaveLandingQueue(int);   //Add plane's time in landing queue to total landing queue time
        void leaveTakeOffQueue(int);   //Add plane's time in take off queue to total take off queue time
        void planeLanded();            //Plane successfully landed
        void planeTakenOff();          //Plane successfully took off
        void planeCrash();             //Plane crashed due to running out of fuel
        void printReport(int);         //Output simulation statistics to console

    private:
        int planesLanded;
        int planesTakenOff;
        int planesCrashed;
        float totalLandingTime;
        float totalTakeOffTime;

};

#endif // STATKEEPER_H