CXX = c++

FLAGS = -Wall -O3 -g

maze.out: generator.cpp
	$(CXX) $(FLAGS) generator.cpp -o maze.out