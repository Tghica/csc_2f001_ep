CXX := c++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

TARGET := lab6
SOURCES := main.cpp treemap.cpp
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp treemap.hpp
treemap.o: treemap.cpp treemap.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)