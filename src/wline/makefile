CC = gcc
CFlags = -Wall -pedantic -std=c11

run: test
	./test > testResults.txt
	diff wlineTest.txt testResults.txt

all: test.o wline.o
	${CC} -o test test.o wline.o

test.o: wline.h test.c
	${CC} ${CFlags} -c test.c

wline.o: wline.h wline.c
	${CC} ${CFlags} -c wline.c

build:
	(make clean; make wline.o)
	cp wline.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp wline.c wline.h ../../deploy
