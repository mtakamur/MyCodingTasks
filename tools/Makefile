CXX=g++
CFLAGS=-O2

OBJECTS=Format.o Main.o Formatter

all: ${OBJECTS}

Format.o: Format.h Format.cxx
	${CXX} ${CFLAGS} -c Format.cxx

Main.o: Main.cxx
	${CXX} ${CFLAGS} -c Main.cxx

Formatter: Format.o Main.o
	${CXX} ${CFLAGS} -o Formatter Format.o Main.o

clean:
	rm -rf ${OBJECTS}