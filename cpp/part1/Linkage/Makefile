CXX=g++

OBJECTS=Function.o Main.o Main

all: ${OBJECTS}

Function.o: Function.cxx Function.h
	${CXX} -c Function.cxx

Main.o: Function.o Function.h Main.cxx
	${CXX} -c Main.cxx

Main: Function.o Main.o
	${CXX} -o Main Function.o Main.o

clean:
	rm -rf ${OBJECTS}