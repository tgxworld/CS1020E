all: findwords.exe
findwords.exe: findwords.o
	g++ -Wall -g -o findwords.exe findwords.o
findwords.o: findwords.cpp
	g++ -c -Wall -g findwords.cpp