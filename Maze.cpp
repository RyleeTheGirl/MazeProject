/* 
 * File:   Maze.cpp
 * Author: Rylee Noorda and Andrew Brown
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
    if (amaze[r][c] == '.' || amaze[r][c] == 'X' || amaze[r][c] == 'S' ) { // not open
        return false;
    }
	
    if (amaze[r][c] == ' ' || amaze[r][c] == 'F' ) { // open
        return true;
    }
    // If we get here it is something unexpected so its an error.
	cout << "Error: Unexpected state found in maze: " << amaze[r][c] << endl;
    return false;
}

// Added this code, take a look and see if you have any changes or anything to add
bool Maze::solve_with_vector () { 
 	vector<int> alternativesR, alternativesC;
	alternativesR.clear();
	alternativesC.clear();
	int r = 0;
	int c = 0;
	int solutionR;
	int solutionC;
	while (r != -1 && c != -1 && r <= rows && c <= cols && amaze[r][c] != 'F')
	{
		if (amaze[r][c] == 'F')
		{
			solutionR = r;
			solutionC = c;
			return true;
		}

		amaze[r][c] = '.';

		if (check_if_open(r-1, c) == true)
		{
			alternativesR.push_back(r-1);
			alternativesC.push_back(c);
		}
		if (check_if_open(r, c + 1) == true)
		{
			alternativesR.push_back(r);
			alternativesC.push_back(c + 1);
		}
		if (check_if_open(r + 1, c) == true)
		{
			alternativesR.push_back(r + 1);
			alternativesC.push_back(c);
		}
		if (check_if_open(r, c - 1) == true)
		{
			alternativesR.push_back(r);
			alternativesC.push_back(c - 1);
		}
		if (alternativesC.empty() == true && alternativesR.empty() == true)
		{
			return false;
		}
		else
		{
			r = alternativesR.back();
			alternativesR.pop_back();
			c = alternativesC.back();
			alternativesC.pop_back();
		}
	}
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


/* Purpose: Returns whether or not the searcher is within the Maze and not on the finish
 * Parameters
 *     row int : Provides current row position of searcher
 *     col int : Provides current column position of searcher
 * Returns
 *     bool : Represents whether or not the searcher is within the Maze and not on the finish
*/
bool Maze::within_bounds(int row, int col)
{
    return ((row >= 0 && row <= rows) && (col >= 0 && col <= cols));
}