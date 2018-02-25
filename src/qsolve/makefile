CC = gcc
CFlags = -Wall -pedantic -std=c11

all: qsolveTest.o qsolve.o
	${CC} -o test qsolveTest.o qsolve.o -lm

run: all
	./test

qsolveTest.o: qsolve.h qsolveTest.c
	${CC} ${CFlags} -c qsolveTest.c

qsolve.o: qsolve.h qsolve.c
	${CC} ${CFlags} -c qsolve.c

build:	clean qsolve.o
	cp qsolve.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp qsolve.c qsolve.h ../../deploy
