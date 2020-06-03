CXX=g++
CFLAGS=-O2

OBJECTS=Pointer Reference AddCalculation Const ConditionalOperator BitCalc AddressPass GetString StaticVal Scope VectorAllocate

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

AddressPass: AddressPass.cxx
	${CXX} ${CFLAGS} AddressPass.cxx -o AddressPass

GetString: GetString.cxx
	${CXX} ${CFLAGS} GetString.cxx -o GetString

StaticVal: StaticVal.cxx
	${CXX} ${CFLAGS} StaticVal.cxx -o StaticVal

Scope: Scope.cxx
	${CXX} ${CFLAGS} Scope.cxx -o Scope

VectorAllocate: VectorAllocate.cxx
	${CXX} ${CFLAGS} VectorAllocate.cxx -o VectorAllocate

clean:
	rm -rf *.o ${OBJECTS}