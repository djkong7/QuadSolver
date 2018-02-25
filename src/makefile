CC = gcc
CFlags = -Wall -pedantic -std=c11

all:
	${CC} ${CFlags} main/main.c rline/rline.c validate/validate.c qsolve/qsolve.c wline/wline.c foutput/foutput.c -o quadSolver -lm

build:
	(cd rline; make build)
	(cd foutput; make build)
	(cd main; make build)
	(cd qsolve; make build)
	(cd wline; make build)
	(cd validate; make build)
	(cd ../build; make)

test:
	(cd foutput; make run)
	(cd rline; make run)
	(cd qsolve; make run)
	(cd wline; make run)
	(cd validate; make run)

clean:
	rm -rf quadSolver *.o core

cleanAll:
	(make clean)
	(cd rline; make clean)
	(cd qsolve; make clean)
	(cd wline; make clean)
	(cd validate; make clean)
	(cd foutput; make clean)
	(cd main; make clean)
