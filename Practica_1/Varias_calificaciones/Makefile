CXX = g++
CXXFLAGS = -Wall

p01_multiple_grades: p01_multiple_grades_main.cc p01_multiple_grades.cc
	$(CXX) $(CXXFLAGS) p01_multiple_grades.cc p01_multiple_grades_main.cc -o p01_multiple_grades_main

.PHONY: clean
clean:
	rm -rf *.o p01_multiple_grades_main
	rm -rf a.out 