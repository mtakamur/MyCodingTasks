CXX=g++
CFLAGS=-O2

OBJECTS=Struct FileOperation

all: ${OBJECTS}

Struct: Struct.c
	${CXX} ${CFLAGS} Struct.c -o Struct

FileOperation: FileOperation.c
	${CXX} ${CFLAGS} FileOperation.c -o FileOperation

clean:
	rm -rf *.o test.dat ${OBJECTS}