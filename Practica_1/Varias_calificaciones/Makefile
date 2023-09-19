CXX = g++
CXXFLAGS = -Wall

p01_multiple_grades: p01_multiple_grades_main.o p01_multiple_grades.o
	$(CXX) $(CXXFLAGS) p01_multiple_grades.o p01_multiple_grades_main.o -o p01_multiple_grades_main

.PHONY: clean
clean:
	rm -rf *.o p01_multiple_grades_main