all: Main.exe
Main.exe: Main.o List.o KListNode.o
	g++ -Wall -g -o Main.exe  KListNode.o List.o Main.o
Main.o: Main.cpp
	g++ -c -Wall -g Main.cpp
List.o: List.cpp
	g++ -c -Wall -g List.cpp
KListNode.o: KListNode.cpp
	g++ -c -Wall -g KListNode.cpp 
