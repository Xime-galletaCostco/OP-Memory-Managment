CXX := g++
SRC := $(wildcard src/*.cpp)
ProjectName := $(notdir $(CURDIR))
TARGETDIR := output
TARGET := $(TARGETDIR)\$(ProjectName).exe

build:
	$(CXX) $(SRC) -o $(TARGET)

run:
	$(TARGET)

clean:
	del $(TARGET)