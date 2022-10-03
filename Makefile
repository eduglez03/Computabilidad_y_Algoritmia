CXX = g++
CXXFLAGS = -Wall

alfabetos_main: alfabetos_main.o alfabeto.o
	$(CXX) $(CXXFLAGS) alfabeto.o alfabetos_main.o -o alfabetos_main

.PHONY: clean
clean:
	rm -rf *.o alfabetos_main