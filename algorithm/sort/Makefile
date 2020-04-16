ROOTFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)

CXX=g++
CFLAGS=-O2 ${ROOTFLAGS}

OBJECTS=EventGenerator.o Bubble Bucket Quick

all: ${OBJECTS}

EventGenerator.o: EventGenerator.cxx EventGenerator.h
	${CXX} ${CFLAGS} -c EventGenerator.cxx

Bubble: Bubble.cxx Config.h EventGenerator.o
	${CXX} ${CFLAGS} Bubble.cxx -o Bubble EventGenerator.o ${ROOTLIBS}

Bucket: Bucket.cxx Config.h EventGenerator.o
	${CXX} ${CFLAGS} Bucket.cxx -o Bucket EventGenerator.o ${ROOTLIBS}

Quick: Quick.cxx Config.h EventGenerator.o
	${CXX} ${CFLAGS} Quick.cxx -o Quick EventGenerator.o ${ROOTLIBS}

clean:
	rm -rf *.o ${OBJECTS}