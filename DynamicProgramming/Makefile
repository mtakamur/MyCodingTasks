CXX=g++
CFLAGS=-O2

OBJECTS=A_Frog1 B_Frog2 C_Vacation D_Knapsack1

all: ${OBJECTS}

A_Frog1: A_Frog1.cxx
	${CXX} ${CFLAGS} -o A_Frog1 A_Frog1.cxx

B_Frog2: B_Frog2.cxx
	${CXX} ${CFLAGS} -o B_Frog2 B_Frog2.cxx

C_Vacation: C_Vacation.cxx
	${CXX} ${CFLAGS} -o C_Vacation C_Vacation.cxx

D_Knapsack1: D_Knapsack1.cxx
	${CXX} ${CFLAGS} -o D_Knapsack1 D_Knapsack1.cxx

clean:
	rm -rf *.o ${OBJECTS}