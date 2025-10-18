CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
TARGET = libcppmenu.a

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR) $(TARGET)

.PHONY: all clean
