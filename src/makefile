CC = gcc
CFlags = -Wall -pedantic -std=c11

run: test
	./test

all: test.o qsolve.o
	${CC} -o test test.o qsolve.o

test.o: qsolve.h test.c
	${CC} ${CFlags} -c test.c

qsolve.o: qsolve.h qsolve.c
	${CC} ${CFlags} -c qsolve.c

build:
	cp qsolve.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp qsolve.c qsolve.h ../../deploy
