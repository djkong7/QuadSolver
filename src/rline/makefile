CC = gcc
CFlags = -Wall -pedantic -std=c11

run: test
	./test

all: test.o rline.o
	${CC} -o test test.o rline.o

test.o: rline.h test.c
	${CC} ${CFlags} -c test.c

rline.o: rline.h rline.c
	${CC} ${CFlags} -c rline.c

build:
	cp rline.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp rline.c rline.h ../../deploy
