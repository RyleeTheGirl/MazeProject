/* 
 * File:   Maze.cpp
 * Author: Kathy
 * This file contains the Maze class implementation.
 * See Maze.h for the Maze class definition (interface).
 */

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Maze.h"

using namespace std;

// Constructor only initializes class variables.
Maze::Maze() { 
    rows = cols = 0;
    amaze = NULL;
}

// Destructor doesn't have anything to do but is left as a place holder
//      for any future features that need cleanup.
Maze::~Maze() {
    // Nothing to get rid of since we just point to the users supplied maze.
}

// Attach a users maze.  Keep track of number of rows and columns in it.
void Maze::set_maze (char ** maz, int numr, int numc) {
    rows = numr; 
    cols = numc; 
    amaze = maz;
}

// Determine if a row and column are inside the maze and 
//      not a wall nor already searched.
//
// Returns:
//      true for open inside not searched.
//      false if its outside, wall, already searched or finish.
//
bool Maze::check_if_open(int r, int c) {
    // Any row or column that is negative is outside.
    // Any row or column that is greater than the values passed to set_maze are outside.
    if (r < 0 || c < 0 || r >= rows || c >= cols ) {    // Outside
        return false;
    }
    // '.' is already searched, 'F' is the finish, 'S' is the start, 'X' is wall
	// We only check for this so we can be sure that when we get to the end we have
	// checked all valid possibilities.
    if (amaze[r][c] == '.' || amaze[r][c] == 'X' || amaze[r][c] == 'S' || amaze[r][c] == 'F') { // not open
        return false;
    }
	
    if (amaze[r][c] == ' ' ) { // open
        return true;
    }
    // If we get here it is something unexpected so its an error.
	cout << "Error: Unexpected state found in maze: " << amaze[r][c] << endl;
    return false;
}

// YOUR COMMENTS GO HERE
bool Maze::solve_with_vector () { 
    // YOUR CODE GOES HERE
    return false;
}

// Print the current state of the maze.
// Maze if made up of chars where:
//              ' ' is open, 
//              'X' is wall, 
//              'F' is finish, 
//              '.' is already searched
//
void Maze::print () {
    for (int row =0; row <rows; row++) {
        for (int col =0; col <cols; col++) {
            cout << amaze[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}    

