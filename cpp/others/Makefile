ROOTFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)

CXX=g++
CFLAGS=-O2 ${ROOTFLAGS}

OBJECTS=TestInput ClockFluctuation

all: ${OBJECTS}

TestInput: TestInput.cxx
	${CXX} ${CFLAGS} TestInput.cxx -o TestInput

ClockFluctuation: ClockFluctuation.cxx
	${CXX} ${CFLAGS} ClockFluctuation.cxx -o ClockFluctuation ${ROOTLIBS}

clean:
	rm -rf *.o ${OBJECTS}