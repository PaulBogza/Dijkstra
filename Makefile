CXX			:= g++
CXX_FLAGS	:= -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE := --Iinclude

LIBRARIES	:= 
EXECUTABLE 	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBRARIES)

clean: 
	-rm $(BIN)/*