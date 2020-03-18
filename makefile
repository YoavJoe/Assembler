# All Targets
BIN=./bin/
SOURCE=./src/
INCLUDE=./include/

all: myAssembler

myAssembler: input.o main.o
	gcc -g -Wall -o myAssembler $(BIN)/input.o $(BIN)/main.o

main.o: $(SOURCE)/main.c
	gcc -g -Wall -ansi -pedantic -c $(SOURCE)/main.c -o $(BIN)/main.o

input.o: $(SOURCE)/input.c $(INCLUDE)/input.h
	mkdir -p bin
	gcc -g -Wall -ansi -pedantic -c $(SOURCE)/input.c -o $(BIN)/input.o


#tell make that "clean" is not a file name!
.PHONY: clean run

clean:
	@echo "Cleaning up.."
	rm -vf $(BIN)/* myAssembler
	
#run:
#	@echo "Running the Asseembly on myAssmbler.."
#	./myshell
