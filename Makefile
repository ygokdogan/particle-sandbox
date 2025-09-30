# Project settings
TARGET = main
SRC = $(wildcard src/*.cpp)

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Iinclude

# SFML libraries
LDFLAGS = -Llib -lsfml-graphics -lsfml-window -lsfml-system

# Default rule
all: $(TARGET)

# Build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean build files
clean:
	rm -f $(TARGET)
