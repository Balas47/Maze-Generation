#include "maze.h"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

// The maze is a 5x5 by default.
const int DEF_DIM = 5;

// Constants for indexing into the neighbors of a cell
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

// Constants for printing
const int PRINT = 3;
const int TOP = 0;
const int PSIDES = 1;
const int BOTTOM = 2;

Maze::Maze(){

    area = DEF_DIM * DEF_DIM;
    mheight = DEF_DIM;
    mwidth = DEF_DIM;
    build();
}

Maze::Maze(int width, int height){

    area = width * height;
    mheight = height;
    mwidth = width;
    build();
}

Maze::~Maze(){

    //Cell *grid = new Cell[area];
    Cell *row = start;

    // Go through each row
    while(row){

        // Go through each column
        Cell *col = row->neighbors[DOWN];
        while(col){

            // Delete the current cell and move on
            Cell *temp = col->neighbors[DOWN];
            delete col;
            col = temp;
        }
        
        // Delete the current cell and move on
        Cell *temp = row->neighbors[RIGHT];
        delete row;
        row = temp;
    }

}

void Maze::build(){

    Cell** grid = new Cell*[area]{nullptr};
    
    // Go through the grid and create all of the cells
    for(int i=0;i<mheight;i++){
        for(int j=0;j<mwidth;j++){

            Cell *curr = new Cell;
            grid[i*mwidth+j] = curr;
        }
    }

    // Go through the grid and properly link together the cells
    for(int i=0;i<mheight;i++){
        for(int j=0;j<mwidth;j++){

            // Link the appropriate neighbor to its position in the cells neighbor list
            if(i-1 >= 0) grid[i*mwidth+j]->neighbors[UP] = grid[(i-1)*mwidth+j];
            if(j-1 >= 0) grid[i*mwidth+j]->neighbors[LEFT] = grid[i*mwidth+(j-1)];
            if(i+1 < mheight) grid[i*mwidth+j]->neighbors[DOWN] = grid[(i+1)*mwidth+j];
            if(j+1 < mwidth) grid[i*mwidth+j]->neighbors[RIGHT] = grid[i*mwidth+(j+1)];
        }
    }

    start = grid[0];

    delete[] grid;
}

void Maze::print(){

    Cell *toPrint = start;

    // Go down each of the rows
    while(toPrint){

        // Each cell has 3 parts, the top, sides, and the bottom
        for(int i=0;i<PRINT;i++){
            Cell *row = toPrint;

            // Go across each row
            while(row){

                // The presence of walls determine what is printed around the cell
                if(i == TOP){
                    if(row->walls[UP] == WALL) std::cout << "&&&";
                    else std::cout << "& &";

                }else if(i == PSIDES){
                    if(row->walls[LEFT] == WALL) std::cout << "& ";
                    else std::cout << "  ";

                    if(row->walls[RIGHT] == WALL) std::cout << "&";
                    else std::cout << " ";

                }else if(i == BOTTOM){
                    if(row->walls[DOWN] == WALL) std::cout << "&&&";
                    else std::cout << "& &";
                }

                row = row->neighbors[RIGHT];

            }
            std::cout << std::endl;
        }

        toPrint = toPrint->neighbors[DOWN];
    }
}

// Using the depth first method of generating a maze
void Maze::generate(){

    std::srand(std::time(nullptr));

    // Stack is used to keep track of cells being looked at. 
    std::stack<Cell*> checked;

    checked.push(start);

    // Check all of the cells in the maze
    while(!checked.empty()){

        Cell* curr = checked.top();

        curr->seen = true;  // The current cell is marked as seen

        // Randomly select a neighbor
        int random = std::rand() % SIDES;
        bool valid = false;

        // Check to make sure the selected neighbor has not already been seen
        for(int i=0;i<SIDES;i++){
            if(curr->neighbors[(i+random)%SIDES] &&!(curr->neighbors[(i+random)%SIDES]->seen)){
                random = (random + i) % SIDES;
                valid = true;
                break;
            }
        }

        // If an unseen neighbor was found, push that neighbor onto the stack and 
        // "break" down the walls
        if(valid){

            checked.push(curr->neighbors[random]);

            // Set the appropriate walls index to indicate a path
            if(random == UP){
                curr->walls[UP] = PATH;
                curr->neighbors[UP]->walls[DOWN] = PATH;

            }else if(random == LEFT){
                curr->walls[LEFT] = PATH;
                curr->neighbors[LEFT]->walls[RIGHT] = PATH;

            }else if(random == DOWN){
                curr->walls[DOWN] = PATH;
                curr->neighbors[DOWN]->walls[UP] = PATH;

            }else if(random == RIGHT){
                curr->walls[RIGHT] = PATH;
                curr->neighbors[RIGHT]->walls[LEFT] = PATH;
            }

        // If all neighbors have been visited, pop the current cell from the stack
        }else{
            checked.pop();
        }
    }
}