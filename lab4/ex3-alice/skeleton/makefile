all: Flipper.exe
Flipper.exe: Main.o Main.o Pancake.o
	g++ -Wall -g -o Flipper.exe Main.o Pancake.o
Main.o: Main.cpp
	g++ -c -Wall -g Main.cpp
Pancake.o: Pancake.cpp
	g++ -c -Wall -g Pancake.cpp
