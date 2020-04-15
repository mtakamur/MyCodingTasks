CXX=g++
CFLAGS=-O2

OBJECTS=Pointer Reference AddCalculation Const ConditionalOperator BitCalc

all: ${OBJECTS}

Pointer: Pointer.cxx
	${CXX} ${CFLAGS} Pointer.cxx -o Pointer

Reference: Reference.cxx
	${CXX} ${CFLAGS} Reference.cxx -o Reference

AddCalculation: AddCalculation.cxx
	${CXX} ${CFLAGS} AddCalculation.cxx -o AddCalculation

Const: Const.cxx
	${CXX} ${CFLAGS} Const.cxx -o Const

ConditionalOperator: ConditionalOperator.cxx
	${CXX} ${CFLAGS} ConditionalOperator.cxx -o ConditionalOperator

BitCalc: BitCalc.cxx
	${CXX} ${CFLAGS} BitCalc.cxx -o BitCalc

clean:
	rm -rf *.o ${OBJECTS}