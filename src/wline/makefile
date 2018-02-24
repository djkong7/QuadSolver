CC = gcc
CFlags = -Wall -pedantic -std=c11

all: test.o wline.o
	${CC} -o test test.o wline.o

run: test
	./test > testResults.txt
	diff wlineTest.txt testResults.txt

test.o: wline.h wlineTest.c
	${CC} ${CFlags} -c wlineTest.c

wline.o: wline.h wline.c
	${CC} ${CFlags} -c wline.c

build:
	(make clean; make wline.o)
	cp wline.o ../../build

clean:
	rm -rf test *.o core

deploy:
	cp wline.c wline.h ../../deploy
