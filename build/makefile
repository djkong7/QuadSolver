CC = gcc
CFlags = -Wall -pedantic -std=c11

all:
	${CC} ${CFlags} -o build *.o -lm

tar:
	 tar -zvcf quadSolver.tar -C ../build .

decompress: quadSolver.tar
	mkdir QuadSolver
	tar -zxvf quadSolver.tar -C ./QuadSolver

clean:
	rm -f quadSolver.tar
	rm -rf ./QuadSolver
