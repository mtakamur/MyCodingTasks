CXX=g++
CFLAGS=-O2

OBJECTS=VirtualFunc OperatorOverload StaticMember Template ClassTemplate

all: ${OBJECTS}

VirtualFunc: VirtualFunc.h VirtualFunc.cxx
	${CXX} ${CFLAGS} VirtualFunc.cxx -o VirtualFunc
	
OperatorOverload: OperatorOverload.h OperatorOverload.cxx
	${CXX} ${CFLAGS} OperatorOverload.cxx -o OperatorOverload

StaticMember: StaticMember.h StaticMember.cxx
	${CXX} ${CFLAGS} StaticMember.cxx -o StaticMember

Template: Template.cxx
	${CXX} ${CFLAGS} Template.cxx -o Template

ClassTemplate: ClassTemplate.cxx
	${CXX} ${CFLAGS} ClassTemplate.cxx -o ClassTemplate

clean:
	rm -rf *.o ${OBJECTS}