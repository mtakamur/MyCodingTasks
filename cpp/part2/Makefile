CXX=g++
CFLAGS=-O2

OBJECTS=VirtualFunc

all: ${OBJECTS}

VirtualFunc: VirtualFunc.h VirtualFunc.cxx
	${CXX} ${CFLAGS} VirtualFunc.cxx -o VirtualFunc

clean:
	rm -rf *.o ${OBJECTS}