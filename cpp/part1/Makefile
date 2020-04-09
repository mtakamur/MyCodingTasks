CXX=g++
CFLAGS=-O2

OBJECTS=Pointer Reference AddCalculation

all: ${OBJECTS}

Pointer: Pointer.cxx
	${CXX} ${CFLAGS} Pointer.cxx -o Pointer

Reference: Reference.cxx
	${CXX} ${CFLAGS} Reference.cxx -o Reference

AddCalculation: AddCalculation.cxx
	${CXX} ${CFLAGS} AddCalculation.cxx -o AddCalculation

clean:
	rm -rf *.o ${OBJECTS}