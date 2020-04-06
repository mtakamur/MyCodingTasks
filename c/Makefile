CXX=g++
CFLAGS=-O2

OBJECTS=Struct FileOperation ReadParameter GetOption

all: ${OBJECTS}

Struct: Struct.c
	${CXX} ${CFLAGS} Struct.c -o Struct

FileOperation: FileOperation.c
	${CXX} ${CFLAGS} FileOperation.c -o FileOperation

ReadParameter: ReadParameter.c
	${CXX} ${CFLAGS} ReadParameter.c -o ReadParameter
	
GetOption: GetOption.c
	${CXX} ${CFLAGS} GetOption.c -o GetOption

clean:
	rm -rf *.o normal_file.dat binary_file.dat ${OBJECTS}