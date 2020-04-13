CXX=g++
CFLAGS=-O2

OBJECTS=TestInput

all: ${OBJECTS}

TestInput: TestInput.cxx
	${CXX} ${CFLAGS} TestInput.cxx -o TestInput

clean:
	rm -rf *.o ${OBJECTS}