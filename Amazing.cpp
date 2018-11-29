/* 
 * File:   AmazeMain.cpp
 * Author: Rylee Noorda and Andrew Brown
 *
 * Create and solve a maze.
 *      Can use a stack or queue implementation.
 */

//#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "Maze.h"
using namespace std;

int main(int argc, char* argv[])
{
#define OPEN ' '
#define WALL 'X'
#define FINISH 'F'
    
   const int rows1 = 10;
   const int cols1 = 10;
   char maze1 [rows1][cols1] = {
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN, FINISH},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL}
   };
  
   
   //////////////////////////////////////////////////////////////////////////////

   // Very clumsy way to allow for variable rows and columns, for now.
   char *b1[cols1];
   for (int r=0; r<rows1; r++)
        b1[r] = maze1[r];

   Maze game;  

   try
   {  
   game.set_maze(b1, rows1, cols1);
   }
   catch(const char* msg)
   {
     cout << msg << endl;
   }

   game.print();                    // Make sure its right.
   
   bool solved = game.solve_with_vector();
   if (solved == true) cout << "YEAH! solved with vector!\n";
   else cout << "BOO! can't solve with vector!\n";
   game.print();

   
 //////////////////////////////////////////////////////////////////////////////
 
   // Another solvable maze alternative to the starter version
   const int rows2 = 16;
   const int cols2 = 20;
   char maze2 [rows2][cols2] = {
       {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN},
       {OPEN, WALL, WALL, WALL, WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL, WALL, WALL, WALL, OPEN},
       {OPEN, WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, WALL, WALL, WALL, WALL, OPEN, WALL, WALL, WALL, WALL, OPEN, WALL, OPEN, WALL, OPEN},
       {OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, WALL, WALL, FINISH, WALL, WALL, OPEN, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, WALL, WALL, WALL, WALL, OPEN, OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, WALL, WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL, OPEN, WALL, OPEN},
       {OPEN, WALL, WALL, WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, WALL, WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL, OPEN},
       {OPEN, WALL, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, WALL, OPEN},
       {OPEN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, OPEN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, OPEN},
       {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN}

   };

 //////////////////////////////////////////////////////////////////////////////
 
   // Very clumsy way to allow for variable rows and columns, for now.
   char *b2[cols2];
   for (int r=0; r<rows2; r++)
        b2[r] = maze2[r];

   Maze game2;    // Do another solvable different size
   
   try
   {
     game2.set_maze(b2, rows2, cols2);
   }
   catch(const char* msg)
   {
     cout << msg << endl;
   }

   game2.print();
   
   solved = game2.solve_with_vector();
   if (solved == true) cout << "YEAH! solved with vector!\n";
   else cout << "BOO! can't solve with vector!\n";
   
   game2.print();
   
 //////////////////////////////////////////////////////////////////////////////
 
// This maze does not contain a finish so is unsolveable.
// Use to test whether you are actually traversing the whole maze.
// Output should be the maze with all open spaces changed to . (dots)

   const int rows3 = 10;
   const int cols3 = 10;
   char maze3 [rows3][cols3] = {
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, OPEN, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, OPEN, OPEN, WALL, OPEN, WALL},
       {OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL}
   };
 
 //////////////////////////////////////////////////////////////////////////////
 
   // Very clumsy way to allow for variable rows and columns, for now.
   char *b3[cols3];
   for (int r=0; r<rows3; r++)
        b3[r] = maze3[r];

   Maze game3;    // Do an unsolvable
   
   try
   {
    game3.set_maze(b3, rows3, cols3);
   }
   catch(const char* msg)
   {
     cout << msg << endl;
   }

   game3.print();
   
   solved = game3.solve_with_vector();
   if (solved == true) cout << "YEAH! solved with vector!\n";
   else cout << "BOO! can't solve with vector!\n";
   
   game3.print();
   
  //Test try-catch blocks.
  try
   {
    game3.set_maze(nullptr, 7, 7);
   }
   catch(const char* msg)
   {
     cout << msg << endl;
   }

  try
   {
    game3.set_maze(b3, -7, 7);
   }
   catch(const char* msg)
   {
     cout << msg << endl;
   }

  try
   {
    game3.set_maze(b3, 7, -7);
   }
   catch(const char* msg)
   {
     cout << msg << endl;
   }

  char *testp = nullptr;
   try
   {
    game3.set_maze(&testp, 7, 7);
   }
   catch(const char* msg)
   {
     cout << msg << endl;
   }

   return 0;
}
