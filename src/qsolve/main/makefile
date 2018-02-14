CC = gcc
CFlags = -Wall -pedantic -std=c11

run: test
	./test

all: test.o main.o
	${CC} -o test test.o main.o

main.o: main.h test.c
	${CC} ${CFlags} -c test.c

main.o: main.h main.c
	${CC} ${CFlags} -c main.c

build:
	cp main.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp main.c main.h ../../deploy
