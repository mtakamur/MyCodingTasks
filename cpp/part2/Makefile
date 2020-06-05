CXX=g++
CFLAGS=-O2

OBJECTS=VirtualFunc OperatorOverload

all: ${OBJECTS}

VirtualFunc: VirtualFunc.h VirtualFunc.cxx
	${CXX} ${CFLAGS} VirtualFunc.cxx -o VirtualFunc
	
OperatorOverload: OperatorOverload.h OperatorOverload.cxx
	${CXX} ${CFLAGS} OperatorOverload.cxx -o OperatorOverload

clean:
	rm -rf *.o ${OBJECTS}