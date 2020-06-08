CXX=g++
CFLAGS=-O2

OBJECTS=Formatter

all: ${OBJECTS}

Formatter: Formatter.h Formatter.cxx
	${CXX} ${CFLAGS} -o Formatter Formatter.cxx

clean:
	rm -rf ${OBJECTS}