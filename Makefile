CXX := g++
CXXFLAGS := -std=c++11 -Wall
INCLUDE := -I./include

SRCDIR := src
BINDIR := bin
OBJDIR := obj

TARGET := physics_engine

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCFILES))

.PHONY: all clean

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJFILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR)

run: all
	./$(BINDIR)/$(TARGET)
