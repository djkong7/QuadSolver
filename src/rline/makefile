CC = gcc
CFlags = -Wall -pedantic -std=c11

all: rlineTest.o rline.o
	${CC} -o rlineTest rlineTest.o rline.o

run: rlineTest
	./rlineTest < rlineTest.txt

test.o: rline.h rlineTest.c
	${CC} ${CFlags} -c rlineTest.c

rline.o: rline.h rline.c
	${CC} ${CFlags} -c rline.c

build:	clean rline.o
	cp rline.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp rline.c rline.h ../../deploy
