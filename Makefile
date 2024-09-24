CXX = g++
CXXFLAGS = -std=c++17

TARGET = Bombreak
SOURCES = Bombreak.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
