CXX = g++
CXXFLAGS = -std=c++17

TARGET = bombreak
SOURCES = bombreak.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
