INC_DIR = PrologInterpreter
Target = o

all: compiler

compiler:
	g++ -std=gnu++0x -c *.cpp
ifeq (${OS}, Windows_NT)
	g++ -o $(Target) *.o -lgtest
else
	g++ -o $(Target) *.o -lgtest -lpthread
endif

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o $(Target)
endif