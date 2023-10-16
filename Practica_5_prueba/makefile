CC=g++ 
CXXFLAGS=-std=c++11 -g 
PROGNAME=p05_nfa

OBJS=$(patsubst %.cc,%.o,$(wildcard *.cc)) 
all: ${OBJS} 
		$(CC) $(CXXFLAGS) -o $(PROGNAME) ${OBJS} 
  
clean: 
		rm -rf *.o $(PROGNAME)