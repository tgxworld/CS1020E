all: Balls.exe
Balls.exe: Balls.o ListNode.o List.o
	g++ -Wall -g -o Balls.exe Balls.o ListNode.o List.o
Balls.o: Balls.cpp
	g++ -c -Wall -g Balls.cpp
ListNode.o: ListNode.cpp
	g++ -c -Wall -g ListNode.cpp
List.o: List.cpp
	g++ -c -Wall -g List.cpp
	
