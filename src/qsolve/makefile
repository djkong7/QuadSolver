CC = gcc
CFlags = -Wall -pedantic -std=c11

all: test.o qsolve.o
	${CC} -o test test.o qsolve.o

run: test
	./test

test.o: qsolve.h qsolveTest.c
	${CC} ${CFlags} -c qsolveTest.c

qsolve.o: qsolve.h qsolve.c
	${CC} ${CFlags} -c qsolve.c

build:	clean qsolve.o
	cp qsolve.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp qsolve.c qsolve.h ../../deploy
