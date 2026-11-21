CXX = g++
SRC = main.cpp peorAjuste.cpp primerAjuste.cpp printList.cpp printQueue.cpp procesos.cpp roundRobin.cpp
TARGET = TestFinal.exe

build:
	$(CXX) $(SRC) -o $(TARGET)

clean:
	rm TestFinal.exe