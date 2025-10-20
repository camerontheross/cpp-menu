CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

LIB_NAME = libcppmenu.a

SRC = Menu.cpp
OBJ = $(SRC:.cpp=.o)

all : $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(LIB_NAME)

.PHONY: all clean 

