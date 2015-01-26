all: Measurement.exe
Measurement.exe: Measurement.o Person.o
	g++ -Wall -g -o Measurement.exe Measurement.o Person.o
Measurement.o: Measurement.cpp
	g++ -c -Wall -g Measurement.cpp
Person.o: Person.cpp
	g++ -c -Wall -g Person.cpp