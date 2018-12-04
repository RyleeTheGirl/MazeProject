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
	
	if (maz == nullptr)
	{
		throw "Error: Maz is a Nullptr.";
	}
	if (*maz == nullptr)
	{
		throw "Error: *maz is a nullptr.";
	}
	if (rows < 0)
	{
		throw "Error: Number of rows is negative. Please enter valid number of rows.";
	}
	if (cols < 0)
	{
		throw "Error: Number of columns is negative. Please enter valid number of columns.";
	}

    for(int i1 = 0; i1 < rows; i1++)
    {
        for(int i2 = 0; i2 < cols; i2++)
        {
            if(amaze[i1][i2] != ' ' && amaze[i1][i2] != 'X' && amaze[i1][i2] != 'F')
                throw "Error: Invalid Character in maze location";
        }
    }
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


//  Solves maze given using vectors to search each spot
//      and keep track of locations already searched/alternate routes
//
// Returns:
//      true if F is found at current location, meaning maze is solvable using vectors
//      false if there is no occurance of 'F' in the maze, meaning the maze is unsolvable using vectors
//
bool Maze::solve_with_vector () { 
	//Creates two vectors to individually keep track or the row and column coordinates of alternate tacks
 	vector<int> alternativesR, alternativesC;
	//Clears both vectors to begin
	alternativesR.clear();
	alternativesC.clear();
	//Sets current location in maze to (0,0)
	int r = 0;
	int c = 0;

	//Makes sure that the current location is always within the bounds of the rows and columns
	while (within_bounds(r, c))
	{
		//Checks to see if current location is the finish, and if it is, returns true
		if (amaze[r][c] == 'F') 
		{
			return true;
		}
		//If not the finish, set current location to . meaning location has been searched
		amaze[r][c] = '.';
		
		//Checks if position above current location is open
		if (check_if_open(r-1, c))
		{
			//If it is open, add the coordinates of the above position to the alternate route vectors
			alternativesR.push_back(r-1);
			alternativesC.push_back(c);
		}
		//Check if position to the right is open
		if (check_if_open(r, c + 1))
		{
			//If it is open, add the coordinates of the position to the right to the alternate route vectors
			alternativesR.push_back(r);
			alternativesC.push_back(c + 1);
		}
		//Check if position below current location is open
		if (check_if_open(r + 1, c))
		{
			//If it is open, add the coordinate of the position below to the alternate route vectors
			alternativesR.push_back(r + 1);
			alternativesC.push_back(c);
		}
		//Check if the position to the left is open
		if (check_if_open(r, c - 1))
		{
			//If it is open, add the coordinates of the position to the left to the alternate route vectors
			alternativesR.push_back(r);
			alternativesC.push_back(c - 1);
		}
		//Check if the alternate route vectors are empty
		if (alternativesC.empty() && alternativesR.empty())
		{
			//If they are empty, return false, meaning it is not possible to solve this maze with vectors
			return false;
		}
		//Otherwise, if the alternate route vectors are not empty
		else
		{
			//Set the current location to the last saved coordinates in the alternate route vectors
			r = alternativesR.back();
			alternativesR.pop_back();
			c = alternativesC.back();
			alternativesC.pop_back();
		}
	}
	//If reach the end without findind finish, return false, meaning it is not possible to solve maze with vectors
	return false;
}

//  Solves maze given using vectors to search each spot
//      and keep track of locations already searched/alternate routes
//
// Returns:
//      true if F is found at current location, meaning maze is solvable using vectors
//      false if there is no occurance of 'F' in the maze, meaning the maze is unsolvable using vectors
//
bool Maze::solve_with_vector_2 () { 
	//Creates two vectors to individually keep track or the row and column coordinates of alternate tacks
 	vector<int> alternativesR, alternativesC;
	//Clears both vectors to begin
	alternativesR.clear();
	alternativesC.clear();
	//Sets current location in maze to (0,0)
	int r = 0;
	int c = 0;

	//Makes sure that the current location is always within the bounds of the rows and columns
	while (within_bounds(r, c))
	{
		//Checks to see if current location is the finish, and if it is, returns true
		if (amaze[r][c] == 'F') 
		{
			return true;
		}
		//If not the finish, set current location to . meaning location has been searched
		amaze[r][c] = '.';
		
		//Checks if position above current location is open
		if (check_if_open(r-1, c))
		{
			//If it is open, add the coordinates of the above position to the alternate route vectors
			alternativesR.push_back(r-1);
			alternativesC.push_back(c);
		}
		//Check if position to the right is open
		if (check_if_open(r, c + 1))
		{
			//If it is open, add the coordinates of the position to the right to the alternate route vectors
			alternativesR.push_back(r);
			alternativesC.push_back(c + 1);
		}
		//Check if position below current location is open
		if (check_if_open(r + 1, c))
		{
			//If it is open, add the coordinate of the position below to the alternate route vectors
			alternativesR.push_back(r + 1);
			alternativesC.push_back(c);
		}
		//Check if the position to the left is open
		if (check_if_open(r, c - 1))
		{
			//If it is open, add the coordinates of the position to the left to the alternate route vectors
			alternativesR.push_back(r);
			alternativesC.push_back(c - 1);
		}
		//Check if the alternate route vectors are empty
		if (alternativesC.empty() && alternativesR.empty())
		{
			//If they are empty, return false, meaning it is not possible to solve this maze with vectors
			return false;
		}
		//Otherwise, if the alternate route vectors are not empty
		else
		{
			//Set the current location to the last saved coordinates in the alternate route vectors
			r = alternativesR.back();
			alternativesR.pop_back();
			c = alternativesC.back();
			alternativesC.pop_back();
		}
	}
	//If reach the end without findind finish, return false, meaning it is not possible to solve maze with vectors
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
 * Parameters:
 *     row int : Provides current row position of searcher
 *     col int : Provides current column position of searcher
 * Returns:
 *     bool : Represents whether or not the searcher is within the Maze and not on the finish
*/
bool Maze::within_bounds(int row, int col)
{
    return ((row >= 0 && row < rows) && (col >= 0 && col < cols));
}

