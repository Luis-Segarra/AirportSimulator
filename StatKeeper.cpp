//StatKeeper.cpp
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015

#include "StatKeeper.h"
#include <stdio.h>

StatKeeper::StatKeeper()
{
    planesLanded = 0;
    planesTakenOff = 0;
    planesCrashed = 0;
    totalLandingTime = 0;
    totalTakeOffTime = 0;
}

StatKeeper::~StatKeeper()
{
    //dtor
}
void StatKeeper::leaveLandingQueue(int time)
{
	totalLandingTime += time;
}
void StatKeeper::leaveTakeOffQueue(int time)
{
	totalTakeOffTime += time;
}
void StatKeeper::planeLanded()
{
	planesLanded++;
}
void StatKeeper::planeTakenOff()
{
	planesTakenOff++;
}
void StatKeeper::planeCrash()
{
	planesCrashed++;
}
void StatKeeper::printReport(int time)
{
	float avgTakeOff = (float)totalTakeOffTime/(float)planesTakenOff;
	float avgLanding = (float)totalLandingTime/(float)planesLanded;
	printf("\nTotal Simulation Time: %d \n", time);
	printf("Total Number of Planes Taken Off: %d \n",planesTakenOff );
	printf("Total Number of Planes Landed: %d \n", planesLanded);
	printf("Total Number of Planes Crashed: %d \n", planesCrashed);
	printf("Average Time Spent in Take Off Queue: %.3f \n", avgTakeOff);
	printf("Average Time Spent in Landing Queue: %.3f \n", avgLanding);
}
