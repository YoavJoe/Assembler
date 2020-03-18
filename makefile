# All Targets
BIN=./bin/
SOURCE=./src/
INCLUDE=./include/

all: myAssembler

myAssembler: output.o input.o main.o
	@echo "Making myAssembler an exe file"
	@gcc -g -Wall -o myAssembler $(BIN)/input.o $(BIN)/output.o $(BIN)/main.o

main.o: $(SOURCE)/main.c
	@echo "Compilling main and stoping before linking and the output is main.o"
	@gcc -g -Wall -ansi -pedantic -c $(SOURCE)/main.c -o $(BIN)/main.o

input.o: $(SOURCE)/input.c $(INCLUDE)/input.h
	@echo "Compilling input and stoping before linking and the output is input.o"
	@gcc -g -Wall -ansi -pedantic -c $(SOURCE)/input.c -o $(BIN)/input.o

output.o: $(SOURCE)/output.c $(INCLUDE)/output.h
	@echo "Creating bin directory"
	@mkdir -p bin
	@echo "Compilling output and stoping before linking and the output is output.o"
	@gcc -g -Wall -ansi -pedantic -c $(SOURCE)/output.c -o $(BIN)/output.o


#tell make that "clean" is not a file name!
.PHONY: clean run

clean:
	@echo "Cleaning up:"
	@rm -vf $(BIN)/* myAssembler
	@echo "and removing bin directory
	@rmdir bin #need to fix!!!
#run:
#	@echo "Running the Asseembly on myAssmbler.."
#	./myshell

