CC = gcc
CFlags = -Wall -pedantic -std=c11

all: foutputTest.o foutputTest2.o foutput.o wline.o
	${CC} -o foutputTest foutputTest.o foutput.o wline.o
	${CC} -o foutputTest2 foutputTest2.o

run: all
	./foutputTest | ./foutputTest2

foutputTest2.o: foutputTest2.c
	${CC} ${CFlags} -c foutputTest2.c

foutputTest.o: foutputTest.c
	${CC} ${CFlags} -c foutputTest.c

foutput.o: foutput.h foutput.c ../wline/wline.c
	${CC} ${CFlags} -c foutput.c ../wline/wline.c

build: clean foutput.o
	cp foutput.o ../../build

clean:
	rm -rf foutputTest foutputTest2 *.o core

deploy:
	cp foutput.c foutput.h ../../deploy
