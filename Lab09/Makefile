program: main.o Executive.o Task.o NotFoundException.o InvalidSetEntryRequest.o
	g++ -std=c++11 -g -Wall main.o Executive.o Task.o NotFoundException.o InvalidSetEntryRequest.o -o program

main.o: main.cpp Executive.h Executive.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp NotFoundException.h NotFoundException.cpp InvalidSetEntryRequest.h InvalidSetEntryRequest.cpp Task.h Task.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
	
Executive.o: Executive.h Executive.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp NotFoundException.h NotFoundException.cpp InvalidSetEntryRequest.h InvalidSetEntryRequest.cpp Task.h Task.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
	
BinarySearchTree.o: main.o Executive.o Task.o NotFoundException.o InvalidSetEntryRequest.o
	g++ -std=c++11 -g -Wall main.o Executive.o Task.o NotFoundException.o InvalidSetEntryRequest.o -o BinarySearchTree.cpp

NotFoundException.o: Executive.h Executive.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp NotFoundException.h NotFoundException.cpp InvalidSetEntryRequest.h InvalidSetEntryRequest.cpp Task.h Task.cpp
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp

InvalidSetEntryRequest.o:	Executive.h Executive.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp NotFoundException.h NotFoundException.cpp InvalidSetEntryRequest.h InvalidSetEntryRequest.cpp Task.h Task.cpp
	g++ -std=c++11 -g -Wall -c InvalidSetEntryRequest.cpp
		
clean:
	rm *.o program