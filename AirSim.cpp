//AirSim.cpp
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015
//Main

#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "StatKeeper.h"
#include "BoolSource.h"
#include "Airplane.h"
#include "Runway.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;


/******************************* Parse Function ***************************************/

void parse (char **argv, int& landTime, int& takeOffTime,  float& tempLanding, float& tempTakeOff, int& startTime, int& stopTime, int& fuelTime);


/**************************************************************************************/



int main(int argc, char **argv)
{
    srand(time(NULL));  // Seeding rand

    float tempTakeOFF, tempLanding;



    int landTime = 0, takeOffTime = 0, startTime = 0, stopTime = 0, currentTime = 0, fuelTime = 0;


    if(argc < 7)
    {
        cerr << "ERROR you are missing an argument";
        exit(EXIT_FAILURE);
    }

    parse( argv, landTime, takeOffTime,  tempLanding, tempTakeOFF, startTime, stopTime, fuelTime);



/*********************** Airport *****************************************************/

    StatKeeper stats;
    Runway MyRunway;
    Airplane *airplanePtr;
    Queue<Airplane> takeOffQueue;
    Queue<Airplane> landingQueue;

    BoolSource takeoff(tempTakeOFF);
    BoolSource landing(tempLanding);

/**************************************************************************************/



    /** Main loop **/
    for(currentTime = startTime ; currentTime > stopTime; currentTime-- )
    {

    /******************Decision Block to add planes to queues*******/

        if(landing.computeProb())
        {
            airplanePtr = new Airplane(currentTime, fuelTime);
            landingQueue.Enqueue(*airplanePtr);
        }

        if(takeoff.computeProb())
        {
            airplanePtr = new Airplane(currentTime, fuelTime);
            takeOffQueue.Enqueue(*airplanePtr);
        }
    /***************************************************************/



        if(MyRunway.isBusy() == false)                   //Checks if the runway is busy at the current time
        {

            while(landingQueue.crash(currentTime) == true && landingQueue.empty() == false )   //looks for a plane in the queue that has not crashed
            {
                landingQueue.Dequeue();
                stats.planeCrash();
            }

            if(landingQueue.empty() == false)                                   //Checks if there is a plane in the landing queue
            {
                stats.leaveLandingQueue(landingQueue.planeTime(currentTime)); //updates stats with total wait time for current plane
                stats.planeLanded();                                        // update stats adds one plane to landed count
                landingQueue.Dequeue();                                     // dequeue plane
                MyRunway.newPlane(currentTime, landTime);                   // Start landing wait period


            }

            else if(takeOffQueue.empty() == false)                              // If no one is landing and check if someone is taking off]
            {
                stats.leaveTakeOffQueue(takeOffQueue.planeTime(currentTime)); //updates stats with total wait time for current plane
                stats.planeTakenOff();
                takeOffQueue.Dequeue();                                 // dequeue plane
                MyRunway.newPlane(currentTime, takeOffTime);            //Start take off
            }

        }

        if(MyRunway.isBusy() == true)                                   // updates the runway every minute
        {
             MyRunway.updateRunway(currentTime);

        }


        while(landingQueue.crash(currentTime) == true && landingQueue.empty() == false )
            {
                landingQueue.Dequeue();
                stats.planeCrash();
            }


    }
    stats.printReport((startTime - stopTime));
}

void parse (char **argv, int& landTime, int& takeOffTime,  float& tempLanding, float& tempTakeOff, int& startTime, int& stopTime, int& fuelTime)
{
    landTime = atoi(argv[1]);
    takeOffTime = atoi(argv[2]);
    tempLanding = atof(argv[3]);
    tempTakeOff = atof(argv[4]);
    startTime = atoi(argv[5]);
    stopTime = atoi(argv[6]);
    fuelTime = atoi(argv[7]);
}
