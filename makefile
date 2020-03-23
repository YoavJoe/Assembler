
# All Targets
BIN=./bin/
SOURCE=./src/
INCLUDE=./include/

CFLAGS=-g -Wall -ansi -pedantic -c

all: myAssembler

myAssembler: util.o data.o output.o input.o main.o
	@echo "Final phase"
	@gcc -g -Wall -o myAssembler $(BIN)/util.o $(BIN)/data.o $(BIN)/output.o $(BIN)/input.o $(BIN)/main.o

main.o: $(SOURCE)/main.c
	@echo "Compilling main and stoping before linking and the output is main.o"
	@gcc $(CFLAGS) $(SOURCE)/main.c -o $(BIN)/main.o

input.o: $(SOURCE)/input.c $(INCLUDE)/input.h
	@echo "Compilling input and stoping before linking and the output is input.o"
	@gcc $(CFLAGS) $(SOURCE)/input.c -o $(BIN)/input.o

output.o: $(SOURCE)/output.c $(INCLUDE)/output.h
	@echo "Compilling output and stoping before linking and the output is output.o"
	@gcc $(CFLAGS) $(SOURCE)/output.c -o $(BIN)/output.o

data.o: $(SOURCE)/data.c $(INCLUDE)/data.h
	@echo "Compilling data and stoping before linking and the output is data.o"
	@gcc $(CFLAGS) $(SOURCE)/data.c -o $(BIN)/data.o

util.o: $(SOURCE)/util.c $(INCLUDE)/util.h
	@echo "Creating bin directory"
	@mkdir -p bin
	@echo "Compilling util and stoping before linking and the output is util.o"
	@gcc $(CFLAGS) $(SOURCE)/util.c -o $(BIN)/util.o


#tell make that "clean" is not a file name!
.PHONY: clean

clean:
	@echo "Cleaning up:"
	@rm -vf $(BIN)/* myAssembler

	
#	@echo "and removing bin directory
#	@rmdir bin #need to fix!!!
	
#run:
#	@echo "Running the Asseembly on myAssmbler.."
#	./myshell

