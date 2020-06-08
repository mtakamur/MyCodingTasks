CXX=g++
CFLAGS=-O2

OBJECTS=VirtualFunc OperatorOverload StaticMember

all: ${OBJECTS}

VirtualFunc: VirtualFunc.h VirtualFunc.cxx
	${CXX} ${CFLAGS} VirtualFunc.cxx -o VirtualFunc
	
OperatorOverload: OperatorOverload.h OperatorOverload.cxx
	${CXX} ${CFLAGS} OperatorOverload.cxx -o OperatorOverload

StaticMember: StaticMember.h StaticMember.cxx
	${CXX} ${CFLAGS} StaticMember.cxx -o StaticMember

clean:
	rm -rf *.o ${OBJECTS}