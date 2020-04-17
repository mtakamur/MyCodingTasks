ROOTFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)

CXX=g++
CFLAGS=-O2 ${ROOTFLAGS}

OBJECTS=Factorial Fibonacci

all: ${OBJECTS}

Factorial: Factorial.cxx
	${CXX} ${CFLAGS} Factorial.cxx -o Factorial ${ROOTLIBS}

Fibonacci: Fibonacci.cxx
	${CXX} ${CFLAGS} Fibonacci.cxx -o Fibonacci ${ROOTLIBS}

clean:
	rm -rf *.o ${OBJECTS}