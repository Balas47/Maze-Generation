#include "maze.h"
#include <iostream>

// The maze is a 10x10 by default.
const int DEF_DIM = 10;

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

void build(int width, int height){

    Cell* grid[width*height];

    // Go through the grid and create all of the cells
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            Cell *curr = new Cell;
            grid[i*width+height] = curr;

        }
    }

    // Go through the grid linking together all of the members properly

}

void print(){}
