all: Soldier.exe
Soldier.exe: SoldierTest.o Soldier.o
	g++ -Wall -g -o Soldier.exe SoldierTest.o Soldier.o
SoldierTest.o: SoldierTest.cpp
	g++ -c -Wall -g SoldierTest.cpp
Soldier.o: Soldier.cpp
	g++ -c -Wall -g Soldier.cpp
