CXX=g++
CFLAGS=-O2

OBJECTS=Struct FileOperation ReadParameter GetOption DefineMacro ProcessTime_function ProcessTime_macro MemoryAllocate

all: ${OBJECTS}

Struct: Struct.c
	${CXX} ${CFLAGS} Struct.c -o Struct

FileOperation: FileOperation.c
	${CXX} ${CFLAGS} FileOperation.c -o FileOperation

ReadParameter: ReadParameter.c
	${CXX} ${CFLAGS} ReadParameter.c -o ReadParameter
	
GetOption: GetOption.c
	${CXX} ${CFLAGS} GetOption.c -o GetOption
	
DefineMacro: DefineMacro.c
	${CXX} ${CFLAGS} DefineMacro.c -o DefineMacro
	
ProcessTime_function: ProcessTime_function.c
	${CXX} ${CFLAGS} ProcessTime_function.c -o ProcessTime_function

ProcessTime_macro: ProcessTime_macro.c
	${CXX} ${CFLAGS} ProcessTime_macro.c -o ProcessTime_macro

MemoryAllocate: MemoryAllocate.c
	${CXX} ${CFLAGS} MemoryAllocate.c -o MemoryAllocate

clean:
	rm -rf *.o normal_file.dat binary_file.dat ${OBJECTS}