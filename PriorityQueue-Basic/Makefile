#	Created by Anil Kag (anilkagak2@gmail.com)
#	Makefile for Priorty Queue

CC	=	g++
CFLAGS	= 	-Wall

myPrg: main.o PriorityQueue.o
	$(CC) $(CFLAGS) main.o PriorityQueue.o -o myPrg

main.o: main.cpp PriorityQueue.h
	$(CC) $(CFLAGS) -c  main.cpp -o main.o

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	$(CC) $(CFLAGS) -c PriorityQueue.cpp -o PriorityQueue.o

clean:
	rm -rf myPrg *.o
