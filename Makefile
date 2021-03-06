#Makefile for compiling work
#(C) Benjamin Hugo, 2015
#You are free to modify and reuse this in your own practicals
#This file is in the public domain

CPP=g++
INCLUDES_SEARCH_PATH=./libs/
LIBRARY_LOAD_PATH=./libs/
LIBRARY_DEPENDENCIES=-lvolimage #link against libbrain_dead_factorial.so
CPPFLAGS=-std=c++11 -I $(INCLUDES_SEARCH_PATH) -L $(LIBRARY_LOAD_PATH) $(LIBRARY_DEPENDENCIES)
EXE_NAME=driver
#define a generic rule: to go from .cpp to .o files make should invoke the c++ compiler
#the syntax tells make to invoke the compiler without linking (-c), outputting a .o file reading a .cpp file, additionally specifying flags
%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)
#the next rule will tell make link together our shared library object (.so file / in windows this will be a DLL file) from the compiled objects
$(EXE_NAME): driver.o 
	$(CPP) -o $(EXE_NAME) driver.o $(CPPFLAGS)  

#Never submit binaries to your git repo or vula, so create a rule for cleaning up the binary objects just leaving your source code behind
clean:
	rm *.o driver *.raw *.data
	cd libs && make clean
# build entire project
all:
	cd libs && make
	make
#special rule to run your code... your tutor will probably love you for this!
run:
	export LD_LIBRARY_PATH=$(LIBRARY_LOAD_PATH) && ./driver $(args)
