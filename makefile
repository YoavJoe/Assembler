# All Targets
BIN=./bin/
SOURCE=./src/
INCLUDE=./include/

all: myAssmbler

myAssmbler: 

#tell make that "clean" is not a file name!
.PHONY: clean run

#Clean the build directory	

#clean: 
#	@echo "Cleaning up.."
#	rm -vf myshell $(BIN)/*
clean:
	@echo "Cleaning up.."
	rm $(BIN)/*
	
#run:
#	@echo "Running the Asseembly on myAssmbler.."
#	./myshell

clear:
	@echo "Clearing the screan.."
	clear