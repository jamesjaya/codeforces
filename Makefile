# Compiler and flags
CXX      = g++
CXXFLAGS = -O3 -std=c++23

# Find all .cpp files in the current directory
SRCS     = $(wildcard *.cpp)

# Convert e.g. file1.cpp -> file1, file2.cpp -> file2
EXES     = $(SRCS:.cpp=)


# Default target: build all executables
all: $(EXES)

compile-%: %.cpp
	rm -f $@
	$(CXX) $(CXXFLAGS) -o $* $<

%: compile-%
	@echo "Running ./$@..."
	./$@

clean:
	rm -f $(EXES)