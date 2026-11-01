.SUFFIXES:         # remove all the implicit rules (avoid conflicts with our own rules)
.SECONDARY:        # keep intermediate object files
.PHONY: all clean  # these targets are not files

CXXFLAGS=-Wall -Werror -g
BIN=bilbao

all: $(BIN)

$(BIN): main.o
	g++ $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(BIN) *.o *~