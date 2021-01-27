#include <iostream>
#include <cstdlib>
#include <ctime>

void generate(char maze[], int x, int y, int maxTurns, int maxLen);

int main(){

    int xdim = 10;
    int ydim = 10;
    char closed = '1'; // 1 = wall, 0=open

    char *map = new char[xdim*ydim];

    // Fill out the map to be fully "closed"
    for(int i=0;i<ydim;i++){
        for(int j=0;j<xdim;j++){
            map[i*xdim+j] = closed;
        }
    }

    generate(map, xdim, ydim, 3, 3);
    
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

    std::cout << xloc << ", " << yloc << std::endl;

}
