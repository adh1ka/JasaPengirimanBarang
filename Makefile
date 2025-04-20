# Compiler dan flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Direktori dan file
SRC_DIR = src
OBJ_DIR = build
BIN = $(OBJ_DIR)/main

# Semua file cpp di src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target default
all: $(BIN)

# Link semua object file ke binary
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile setiap .cpp ke .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR)/*

.PHONY: all clean
