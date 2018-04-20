OBJ = main.o BrigManager.o Brig.o Cell.o Pirate.o UImanager.o random.o CArray.o  Storage.o Queue.o Dorcs.o Borcs.o Porcs.o

a1:	$(OBJ)
	g++ -g -o a4 $(OBJ)

main.o:	main.cc
	g++ -g -c main.cc

BrigManager.o:	BrigManager.cc BrigManager.h 
	g++ -g -c BrigManager.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -g -c UImanager.cc

Cell.o:	Cell.cc Cell.h defs.h
	g++ -g -c Cell.cc

Brig.o:	Brig.cc Brig.h defs.h
	g++ -g -c Brig.cc

Pirate.o:	Pirate.cc Pirate.h
	g++ -g -c Pirate.cc

CArray.o:	CArray.cc CArray.h
	g++ -g -c CArray.cc

random.o:	random.cc
	g++ -g -c random.cc

Storage.o:	Storage.cc Storage.h
	g++ -g -c Storage.cc

Queue.o:	Queue.cc Queue.h
	g++ -c Queue.cc

Dorcs.o:	Dorcs.cc Dorcs.h
	g++ -c Dorcs.cc

Borcs.o:	Borcs.cc Borcs.h
	g++ -c Borcs.cc

Porcs.o:	Porcs.cc Porcs.h
	g++ -c Porcs.cc
clean:
	rm -f *.o a4

