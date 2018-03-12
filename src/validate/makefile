CC = gcc
CFlags = -Wall -pedantic -std=c11

all: validateTest.o validate.o
	${CC} -o test validateTest.o validate.o

run: all
	./test > validateResult.txt
	diff validateResult.txt testOutcome.txt

validateTest.o: validate.h validateTest.c
	${CC} ${CFlags} -c validateTest.c

validate.o: validate.h validate.c
	${CC} ${CFlags} -c validate.c

build: clean validate.o
	cp validate.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp validate.c validate.h ../../deploy
