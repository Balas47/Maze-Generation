#ifndef MAZE
#define MAZE

// Constants for defining where the walls for a cell in the maze are
const int WALL = 0;
const int PATH = 1;

// Each cell in the maze can have a neighbor up, left, down, and right. There may be a wall
// between the cell and a given neighbors.
struct Cell{

    Cell *neighbors;
    int *walls = {};
    bool seen = false;  // Check whether the cell has been visited

};

// Each maze will essentially be a grid of cells that can be traversed through, and each 
// cell will start with a wall between itself and all of its neighbors. These walls may 
// be removed in the maze generation process.
class Maze{

    private:
        Cell *start;  // Top left of the grid
        int area;  //How many cells are in the maze

    public:

        // Constructors
        Maze();
        Maze(int width, int height);

        void print();

};

#endif