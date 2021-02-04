CXX = c++

FLAGS = -Wall -O3 -g

maze.out: generator.cpp maze.o
	$(CXX) $(FLAGS) maze.o generator.cpp -o maze.out

maze.o: maze.cpp maze.h
	$(CXX) $(FLAGS) -c maze.cpp