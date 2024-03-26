CXX:=g++
CXXFLAGS:=-std=c++14 -g -Wall -Wextra

SRC_DIR:=.
BUILD_DIR:=./build
BIN_DIR:=./bin

EXEC:=$(BIN_DIR)/main

SRCS:=$(wildcard $(SRC_DIR)/*.cpp)
OBJS:=$(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
$(BUILD_DIR)/%.o: $(SRC_DIR)/*.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(EXEC)

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)

.PHONY: all clean
