CC = gcc
CFlags = -Wall -pedantic -std=c11

run: foutputTest
	./foutputTest

all: foutputTest.o foutput.o
	${CC} -o foutputTest foutputTest.o foutput.o

foutputTest.o: foutput.h foutputTest.c
	${CC} ${CFlags} -c foutputTest.c

foutput.o: foutput.h foutput.c ../wline/wline.c
	${CC} ${CFlags} -c foutput.c ../wline/wline.c

build: clean foutput.o
	cp foutput.o ../../build

clean:
	rm -rf foutputTest *.o core

deploy:
	cp foutput.c foutput.h ../../deploy
