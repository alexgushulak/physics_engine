# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# Directories
SRCDIR := src
BINDIR := bin
OBJDIR := obj
ASMDIR := asm  # Directory to store assembly files

# Target executable
TARGET := physics_engine

# Source files
SRCFILES := src/main.cpp src/ball.cpp

# Object files
OBJFILES := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCFILES))

# Assembly files
ASMFILES := $(patsubst $(SRCDIR)/%.cpp, $(ASMDIR)/%.s, $(SRCFILES))

# Phony targets
.PHONY: all clean asm

# Default target
all: $(BINDIR)/$(TARGET)

# Rule to build the executable
$(BINDIR)/$(TARGET): $(OBJFILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to generate assembly files
asm: $(ASMFILES)

$(ASMDIR)/%.s: $(SRCDIR)/%.cpp
	@mkdir -p $(ASMDIR)
	$(CXX) $(CXXFLAGS) -S -o $@ $<

# Rule to clean generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR) $(ASMDIR)

# Rule to run the executable
run: all
	./$(BINDIR)/$(TARGET)
