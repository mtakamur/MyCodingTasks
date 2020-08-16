K=kotlinc
KFLAGS=-include-runtime

OBJECTS=001_DataTypes 002_Expression 003_Array 004_Map 005_Pair 006_When

all: ${OBJECTS}

001_DataTypes: 001_DataTypes.kt
	${K} $^ ${KFLAGS} -d $@.jar

002_Expression: 002_Expression.kt
	${K} $^ ${KFLAGS} -d $@.jar

003_Array: 003_Array.kt
	${K} $^ ${KFLAGS} -d $@.jar

004_Map: 004_Map.kt
	${K} $^ ${KFLAGS} -d $@.jar

005_Pair: 005_Pair.kt
	${K} $^ ${KFLAGS} -d $@.jar

006_When: 006_When.kt
	${K} $^ ${KFLAGS} -d $@.jar

clean:
	rm -rf *.class *.jar META-INF
