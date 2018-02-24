CC = gcc
CFlags = -Wall -pedantic -std=c11

run: test
	./test

all: test.o foutput.o
	${CC} -o test test.o foutput.o

test.o: foutput.h test.c
	${CC} ${CFlags} -c test.c

foutput.o: foutput.h foutput.c
	${CC} ${CFlags} -c foutput.c

build: clean foutput.o
	cp foutput.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp foutput.c foutput.h ../../deploy
