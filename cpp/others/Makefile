ROOTFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)

CXX=g++
CFLAGS=-O2 ${ROOTFLAGS}

OBJECTS=TestInput ClockFluctuation TestVector TestIf CopyObject

all: ${OBJECTS}

TestInput: TestInput.cxx
	${CXX} ${CFLAGS} TestInput.cxx -o TestInput

ClockFluctuation: ClockFluctuation.cxx
	${CXX} ${CFLAGS} ClockFluctuation.cxx -o ClockFluctuation ${ROOTLIBS}

TestVector: TestVector.cxx
	${CXX} ${CFLAGS} TestVector.cxx -o TestVector

TestIf: TestIf.cxx
	${CXX} ${CFLAGS} TestIf.cxx -o TestIf

CopyObject: CopyObject.cxx
	${CXX} ${CFLAGS} CopyObject.cxx -o CopyObject

clean:
	rm -rf *.o ${OBJECTS}