CXX = g++
CXXFLAGS = -Wall

p01_single_grades: p01_single_grades_main.o p01_single_grades.o
	$(CXX) $(CXXFLAGS) p01_single_grades.o p01_single_grades_main.o -o p01_single_grades_main

.PHONY: clean
clean:
	rm -rf *.o p01_single_grades_main 
	rm -rf a.out  
