/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Falin, CS 124
* Author:
*    Tyler Williams
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/
#include <cctype>
#include <iostream>
#include <fstream>
using namespace std;

void getReadFileName(char fileName[]);
void readFile(char fileName[], int board[][9]);
void getWriteFileName();
void writeFile();
void displayMenu();
void editSquare(int board[][9]);
void displayBoard(int board[][9]);
void getCoord(int &row, int &col);
void showValue(int board[][9]);
bool checkSquare(int board[][9], bool possible[], int row, int col);
void userInput(int board[][9]);

/**********************************************************************
 * This function reads in the sudoku file
 ************************************************************************/
void getReadFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
}

/**********************************************************************
 * This function reads in the sudoku file
 ************************************************************************/
void readFile(char fileName[], int board[][9])
{
   ifstream fin;
   fin.open(fileName);

   if (fin.fail())
   {
      cout << "Error!\n";
      return;
   }
   
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
         fin >> board[row][col];
   
   fin.close();
   return;
}

/**********************************************************************
 * This function asks what the file should be called
 ************************************************************************/
void getWriteFileName(char fileName[])
{
   cout << "What file would you like to write your board to: ";
   cin >> fileName;
   cin.ignore();
   
   return;
}

/**********************************************************************
 * This function saves the board
 ************************************************************************/
void writeFile(char fileName[], int board[][9])
{
   ofstream fout;
   fout.open(fileName);
   
   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
         fout << board[row][col] << ' ';
      fout << endl;
   }
      
   
   fout.close();

   cout << "Board written successfully\n";
   
   return;
}

/**********************************************************************
 * This function displays the menu
 ************************************************************************/
void displayMenu()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n";
   return;
}

/**********************************************************************
 * This function handles user option requests
 ************************************************************************/
void userInput(int board[][9])
{
   char input = 'a';
   while (toupper(input) != 'Q')
   {
      cout << "> ";
      cin >> input;
      switch (toupper(input))
      {
         case '?':
            displayMenu();
            cout << endl << endl;
            break;
         case 'E':
            editSquare(board);
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'S':
            showValue(board);
            break;
         case 'Q':
            char fileName[256];
            getWriteFileName(fileName);
            writeFile(fileName, board);
            input = 'Q';
            break;
         default:
            cout << "Bad Command!\n";
      }
   }
   return;
}

/**********************************************************************
 * This function allows the player to change the board
 ************************************************************************/
void editSquare(int board[][9])
{
   int row;
   int col;
   getCoord(row, col);
   int value = 0;

   if (board[row][col])
   {
      cout << "ERROR: Square \'" << (char)(col + 'A') << row + 1
           << "\' is filled\n\n";
      return;
   }
   else
   {
      cout << "What is the value at \'" << (char)(col + 'A')
           << row + 1 << "\': ";
      cin >> value;
   }
   
   bool possible[10] =  {true, 1, 1, 1, 1, 1, 1, 1, 1, 1};
   checkSquare(board, possible, row, col);

   if (possible[value] && value)
      board[row][col] = value;
   else
      cout << "ERROR: Value \'" << value << "\' in square \'"
           << (char)(col + 'A') << row + 1 << "\' is invalid\n";
   cout << endl;
   
   return;
}

/**********************************************************************
 * This function displays the board
 ************************************************************************/
void displayBoard(int board[][9])
{
   cout << "   A B C D E F G H I" << endl;
   for (int row = 0; row < 9; row++)  
   {
      cout << row + 1 << "  ";
      for (int col = 0; col < 9; col++)
      {
         if (board[row][col] != 0)
            cout << board[row][col];
         else 
            cout << ' ';
         
         if (col == 2 || col == 5)
            cout << '|';
         else if (col != 8)
            cout << ' ';
      }
      cout << endl;
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----" << endl;
   }
   cout << endl;

   return;
}

/**********************************************************************
 * This function shows what possible values which for a give space
 ************************************************************************/
void showValue(int board[][9])
{
   int row;
   int col;
   getCoord(row, col);
   
   bool possible[10] =  {true, 1, 1, 1, 1, 1, 1, 1, 1, 1};
   checkSquare(board, possible, row, col);
   cout << "The possible values for \'" << (char)(col + 'A')
        << row + 1 << "\' are: ";
   bool first = true;
   for (int i = 1; i < 10; i++)
   {
      if (possible[i] == true)
      {
         if (first)
            cout << i;
         else
            cout << ", " << i;
         first = false;
      }
   }
   cout << endl << endl;
   
   return;
}

/**********************************************************************
 * This function simply asks what coordinates to work with
 ************************************************************************/
void getCoord(int &row, int &col)
{
   char coord[2];
   cout << "What are the coordinates of the square: ";
   cin >> coord;
   col = coord[0] - 'A';
   row = coord[1] - '1';
   return;
}

/**********************************************************************
 * This function checks to see if the given input is valid
 ************************************************************************/
bool checkSquare(int board[][9], bool possible[], int row, int col)
{

   for (int iRow = 0; iRow < 9; iRow++)
      possible[board[iRow][col]] = false;
   for (int iCol = 0; iCol < 9; iCol++)
      possible[board[row][iCol]] = false;

   for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
      for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
         possible[board[i][j]] = false;
}

/**********************************************************************
 * Main handles all function interactions.
 ************************************************************************/
int main()
{
   char fileName[256];
   int board[9][9];
   getReadFileName(fileName);
   readFile(fileName, board);
   displayMenu();
   cout << endl;
   displayBoard(board);
   userInput(board);
   return 0;
}
