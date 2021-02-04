#include "maze.h"
#include <iostream>

// The maze is a 10x10 by default.
const int DEF_DIM = 5;

// Constants for indexing into the neighbors of a cell
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

Maze::Maze(){

    area = DEF_DIM * DEF_DIM;
    build(DEF_DIM, DEF_DIM);

}

Maze::Maze(int width, int height){

    area = width * height;
    build(width, height);

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

void Maze::build(int width, int height){

    Cell** grid = new Cell*[height*width];

    // Go through the grid and create all of the cells
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            Cell *curr = new Cell;
            grid[i*width+j] = curr;

        }
    }

    // Go through the grid and properly link together the cells
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            // Link the appropriate neighbor to its position in the cells neighbor list
            if(i-1 >= 0) grid[i*width+j]->neighbors[UP] = grid[(i-1)*width+j];
            if(j-1 >= 0) grid[i*width+j]->neighbors[LEFT] = grid[i*width+(j-1)];
            if(i+1 < height) grid[i*width+j]->neighbors[DOWN] = grid[(i+1)*width+j];
            if(j+1 < width) grid[i*width+j]->neighbors[RIGHT] = grid[i*width+(j+1)];

        }
    }

    start = grid[0];

    delete[] grid;
}

void Maze::print(){

    std::cout << "Testing" << std::endl;

}
