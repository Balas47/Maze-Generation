#include <iostream>
#include <cstdlib>
#include <ctime>

const int DIRECTION = 4; // Number of directions to go (up, down, left, right)
const int MOVE[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Actual movement
const int X = 0; // X index
const int Y = 1; // Y index

const char CLOSED = '1';
const char OPEN = '0';

void generate(char maze[], int x, int y, int maxTurns, int maxLen);

int main(){

    int xdim, ydim, turns, len;

    // Ask the user for all of the inputs to the random walk algorithm
    do{
        std::cout << "Width of the Maze: ";
    }while(!(std::cin>>xdim));

    do{
        std::cout << "Height of the Maze: ";
    }while(!(std::cin>>ydim));

    do{
        std::cout << "Max number of turns the algorithm can make: ";
    }while(!(std::cin>>turns));

    do{
        std::cout << "Max length of a given walk: ";
    }while(!(std::cin>>len));

    char *map = new char[xdim*ydim];

    // Fill out the map to be fully "closed"
    for(int i=0;i<ydim;i++){
        for(int j=0;j<xdim;j++){
            map[i*xdim+j] = CLOSED;
        }
    }

    generate(map, xdim, ydim, turns, len);
    
    // Print out the generated map
    for(int i=0;i<ydim;i++){
        for(int j=0;j<xdim;j++){
            std::cout << map[i*xdim+j] << " ";
        }
        std::cout << std::endl;
    }

    delete[] map;

    return 0;
}


/* This function will generate a maze based on the dimensions (x, y), maximum number
of turns, and maximum length of a tunnel. It expects that the maze it is given is filled
out with 1's so that the random walk algorithm can "carve" a random path
*/
void generate(char maze[], int x, int y, int maxTurns, int maxLen){

    // Seed the random number generator
    std::srand(std::time(NULL));

    int xloc = std::rand() % x;
    int yloc = std::rand() % y;

    while(maxTurns > 0){

        // Choose a random length, and direction to walk
        int length = std::rand() % maxLen + 1;
        int dir = std::rand() % DIRECTION;

        // While the algorithm is able to walk
        while((xloc >= 0 && xloc < x) && (yloc >= 0 && yloc < y) && length > 0){

            // Place an opening
            maze[yloc*x+xloc] = OPEN;

            // Update the current location
            xloc += MOVE[dir][X];
            yloc += MOVE[dir][Y];

            length--;
        }

        maxTurns--;
    }
}
