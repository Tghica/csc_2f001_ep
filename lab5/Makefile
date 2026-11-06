.SUFFIXES:
.SECONDARY:
.PHONY: all run clean

CXX ?= g++
CXXFLAGS ?= -Wall -g -std=c++20
BIN := lispEval
OBJS := main.o lispEval.o

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp lispEval.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJS) *~