# mail: danielcohen1717@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Source files
DEMO_SOURCES = Catan.cpp Player.cpp Board.cpp Tile.cpp Edge.cpp Vertex.cpp DevelopmentCard.cpp Demo.cpp
TEST_SOURCES = Catan.cpp Player.cpp Board.cpp Tile.cpp Edge.cpp Vertex.cpp DevelopmentCard.cpp Test.cpp

# Object files
DEMO_OBJECTS = $(DEMO_SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Executables
TEST_EXECUTABLE = test
DEMO_EXECUTABLE = demo

# Default target
all: $(TEST_EXECUTABLE) $(DEMO_EXECUTABLE)

# Build test executable
$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJECTS)

# Build demo executable
$(DEMO_EXECUTABLE): $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(DEMO_OBJECTS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Valgrind check for test executable
valgrind-test: $(TEST_EXECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TEST_EXECUTABLE)

# Valgrind check for demo executable
valgrind-demo: $(DEMO_EXECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(DEMO_EXECUTABLE)

# Clean up build files
clean:
	rm -f $(DEMO_OBJECTS) $(TEST_OBJECTS) $(TEST_EXECUTABLE) $(DEMO_EXECUTABLE)
