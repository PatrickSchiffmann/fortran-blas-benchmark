.PHONY: run all

CXX=icpc
FC=ifort
LD=ifort

CXXFLAGS?=-O3 -std=c++11 -pthread -lbenchmark
FCFLAGS?= -O3 -mkl=sequential
LDFLAGS?= -O3 -pthread -lbenchmark -nofor_main -lstdc++

SRC_DIR := ./src/level1
OBJ_DIR := ./obj

CPP_SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
CPP_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.cpp.o,$(CPP_SRC_FILES))

FC_SRC_FILES := $(wildcard $(SRC_DIR)/*.f90)
FC_OBJ_FILES := $(patsubst $(SRC_DIR)/%.f90,$(OBJ_DIR)/%.f90.o,$(FC_SRC_FILES))

all: main

main: $(CPP_OBJ_FILES) $(FC_OBJ_FILES) $(OBJ_DIR)/main.o
	$(LD) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/main.o: ./src/main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.f90.o: $(SRC_DIR)/%.f90
	$(FC) $(FCFLAGS) -c -o $@ $<

run: main
	./main