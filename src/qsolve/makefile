CC = gcc
CFlags = -Wall -pedantic -std=c11

all: qsolveTest.o qsolve.o
	${CC} -o test qsolveTest.o qsolve.o wline.o -lm
	rm wline.o

run: all
	./test > /dev/null

qsolveTest.o: qsolve.h qsolveTest.c
	${CC} ${CFlags} -c qsolveTest.c

qsolve.o: qsolve.h qsolve.c wline.o
	${CC} ${CFlags} -c qsolve.c

wline.o: ../wline/wline.c ../wline/wline.h
	${CC} ${CFlags} -c ../wline/wline.c

build:	clean qsolve.o
	cp qsolve.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp qsolve.c qsolve.h ../../deploy
