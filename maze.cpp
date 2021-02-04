#include "maze.h"
#include <iostream>

const int DEF_DIM = 10;

Maze::Maze(){

    int area = DEF_DIM * DEF_DIM; // The maze is a 10x10 by default.

}

Maze::Maze(int width, int height){

    int area = width * height;

}

void print(){}
