CXX=g++
CFLAGS=-O2

OBJECTS=A_Frog1 B_Frog2

all: ${OBJECTS}

A_Frog1: A_Frog1.cxx
	${CXX} ${CFLAGS} -o A_Frog1 A_Frog1.cxx

B_Frog2: B_Frog2.cxx
	${CXX} ${CFLAGS} -o B_Frog2 B_Frog2.cxx

clean:
	rm -rf *.o ${OBJECTS}