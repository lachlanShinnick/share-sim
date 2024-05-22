# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Executable name
EXEC = stock_simulation

# Source files
SRCS = main.cpp Broker.cpp Company.cpp Crypto.cpp DataHandler.cpp Exchange.cpp Game.cpp Individual.cpp Investor.cpp Market.cpp Menu.cpp Partnership.cpp Portfolio.cpp Stock.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: clean $(EXEC)

# Rule to link the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC) high_score.txt

# Phony targets
.PHONY: all clean
