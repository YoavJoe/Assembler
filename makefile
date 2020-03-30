
# All Targets
BIN=./bin/
SOURCE=./src/
INCLUDE=./include/

CFLAGS=-g -Wall -ansi -pedantic -c
C=-g -Wall -o

all: myAssembler

myAssembler: hashtable.o util.o data.o output.o input.o main.o
	@gcc $(C) myAssembler $(BIN)/hashtable.o $(BIN)/util.o $(BIN)/data.o $(BIN)/output.o $(BIN)/input.o $(BIN)/main.o

main.o: $(SOURCE)/main.c
	@gcc $(CFLAGS) $(SOURCE)/main.c -o $(BIN)/main.o

input.o: $(SOURCE)/input.c $(INCLUDE)/input.h
	@gcc $(CFLAGS) $(SOURCE)/input.c -o $(BIN)/input.o

output.o: $(SOURCE)/output.c $(INCLUDE)/output.h
	@gcc $(CFLAGS) $(SOURCE)/output.c -o $(BIN)/output.o

data.o: $(SOURCE)/data.c $(INCLUDE)/data.h
	@gcc $(CFLAGS) $(SOURCE)/data.c -o $(BIN)/data.o

util.o: $(SOURCE)/util.c $(INCLUDE)/util.h
	@gcc $(CFLAGS) $(SOURCE)/util.c -o $(BIN)/util.o

hashtable.o: $(SOURCE)/hashtable.c $(INCLUDE)/hashtable.h
	@mkdir -p bin
	@gcc $(CFLAGS) $(SOURCE)/hashtable.c -o $(BIN)/hashtable.o


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

