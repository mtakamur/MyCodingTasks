ROOTFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)

CXX=g++
CFLAGS=-O2 ${ROOTFLAGS}

OBJECTS=Factorial

all: ${OBJECTS}

Factorial: Factorial.cxx
	${CXX} ${CFLAGS} Factorial.cxx -o Factorial ${ROOTLIBS}

clean:
	rm -rf *.o ${OBJECTS}