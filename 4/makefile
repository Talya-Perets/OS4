# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -pthread

# Target executable
TARGET = SingletonGuard

# Source files
SRCS = SingletonGuard.cpp

# Rule to build the target
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Rule to clean the build
clean:
	rm -f $(TARGET)