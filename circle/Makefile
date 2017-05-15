CXX := g++
CXXFLAGS := -std=c++11 -Wall -Werror
LDFLAGS := -lGL -lGLU -lglut
TARGET := main

SOURCES := ${wildcard *.cpp}
OBJECTS := ${SOURCES:.cpp=.o}
HEADERS := ${wildcard *.h}

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	-rm -f $(TARGET)
	-rm -f $(OBJECTS)
