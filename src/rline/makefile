CC = gcc
CFlags = -Wall -pedantic -std=c11

all: rlineTest.o rline.o
	${CC} -o test rlineTest.o rline.o

run: all
	./test < rlineTest.txt

rlineTest.o: rline.h rlineTest.c
	${CC} ${CFlags} -c rlineTest.c

rline.o: rline.h rline.c
	${CC} ${CFlags} -c rline.c

build:	clean rline.o
	cp rline.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp rline.c rline.h ../../deploy
