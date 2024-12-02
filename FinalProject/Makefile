# Compiler and flags
CXX = g++
FLAGS = -std=c++20

# List of source files
SOURCE = main.cpp wikiladder.cpp

# List of object files (derived from the source files)
OBJECTS = main.o wikiladder.o

# Target executable
TARGET = demo

# Default target (compile and link the program)
$(TARGET): $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o $(TARGET) -lcurl  

# Compile each .cpp file to .o object files
%.o: %.cpp wikiladder.h
	$(CXX) -c $(FLAGS) $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Show the source files
echo:
	echo $(SOURCE)

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)
