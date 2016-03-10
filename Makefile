#makefile for project


objects=Airplane.o AirSim.o BoolSource.o Runway.o StatKeeper.o
	
AirSim: $(objects)
	g++ -o AirSim $(objects)

Airplane.o: Airplane.h
	g++ -c Airplane.cpp

AirSim.o: Queue.h
	g++ -c AirSim.cpp

BoolSource.o: BoolSource.h
	g++ -c BoolSource.cpp

Runway.o: Runway.h
	g++ -c Runway.cpp

StatKeeper.o: StatKeeper.h
	g++ -c StatKeeper.cpp

clean: 
	rm -f *.o core
