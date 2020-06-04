CXX=g++
CFLAGS=-O2

OBJECTS=Class.o Main.o Main

all: ${OBJECTS}

Class.o: Class.h Class.cxx
	${CXX} ${CFLAGS} -c Class.cxx

Main.o: Main.cxx
	${CXX} ${CFLAGS} -c Main.cxx

Main: Class.o Main.o
	${CXX} ${CFLAGS} -o Main Class.o Main.o

clean:
	rm -rf *.o ${OBJECTS}