/* 
 * File:   Maze.h
 * Author: Kathy
 * This file contains the Maze class definition (interface).
 * See Maze.cpp for the Maze class implementation.
 */

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

using namespace std;

class Maze {
private:
    char ** amaze;            // The maze
    int rows;                 // Number of rows in the maze
    int cols;                 // Number of cols in the maze
    bool check_if_open(int row, int col); 
			      // Check if open (not wall, not outside, not already searched, not a finish ...)
    bool finished(int row, int col);
public:
    Maze();                   // constructor
    ~Maze();                  // destructor
    void set_maze (char ** maz, int numr, int numc);
    bool solve_with_vector(); // solves maze, alternate possible routes are saved in a vector        
    void print ();            // prints current state of maze,
    // ' ' is open, 'X' is wall, 'F' is finish, '.' is searched
};
#endif /* MAZE_H */
