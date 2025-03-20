CXX = g++
CXXFLAGS = -std=c++17 -I.
LDFLAGS = -lpthread

SRC = Server.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = server_project

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)
