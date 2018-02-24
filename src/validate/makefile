CC = gcc
CFlags = -Wall -pedantic -std=c11

run: test
	./test

all: test.o validate.o
	${CC} -o test test.o validate.o

test.o: validate.h test.c
	${CC} ${CFlags} -c test.c

validate.o: validate.h validate.c
	${CC} ${CFlags} -c validate.c

build: clean validate.o
	cp validate.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp validate.c validate.h ../../deploy
