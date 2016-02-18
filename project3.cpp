/***********************************************************************
* Program:
*    Project 10, Mad Libs
*    Brother Falin, CS124
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

#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char fileName[]);
void run();
void display(char story[][32], int size);
void parseWord(char story[][32], int size);
int readFile(char fileName[], char story[][32]);

/**********************************************************************
 * All main does is call the run function
 ***********************************************************************/
int main()
{
   run();
   return 0;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   return;
}

/**********************************************************************
 * The run function calls for the functions to do the work of reading the
 * file, reading through it, replacing words, and promping to repeat.
 ***********************************************************************/
void run()
{
   char fileName[256];
   char story[256][32];
   bool playAgain = true;
   char letter;
   while (playAgain)
      
   {
      getFileName(fileName);
      int size = readFile(fileName, story);
      cin.ignore(180, '\n');
      parseWord(story, size);
      display(story, size);

      cout << endl << "Do you want to play again (y/n)? ";
      cin >> letter;
      if (toupper(letter) == 'Y')
         playAgain = true;
      else
         playAgain = false;
   }

   cout << "Thank you for playing." << endl;
   return;
}

/**********************************************************************
 * The readFile function opens the information in the array
 ************************************************************************/
int readFile(char fileName[], char story[][32])
{
   int numWords = 0;
   ifstream fin;
   fin.open(fileName);

   while (fin >> story[numWords])
      
   {
      numWords++;
   }

   
   fin.close();
   return numWords;
}

/**********************************************************************
 * This function reads through the story, changes certain characters, 
 * and prints the results. 
 ***********************************************************************/
void parseWord(char story[][32], int size)
{
   for (int i = 0; i < size; i++)
      if (story[i][0] == '<')
      {
         
         switch (story[i][1])
            
         {
            case '#':
               story[i][0] = '\n';
               story[i][1] = 0;
               break;
            case '{':
               story[i][0] = ' ';
               story[i][1] = '\"';
               story[i][2] = 0;
               break;
            case '}':
               story[i][0] = '\"';
               story[i][1] = 0;
               break;
            case ']':
               story[i][0] = '\'';
               story[i][1] = 0;
               break;
            case '[':
               story[i][0] = ' ';
               story[i][1] = '\'';
               story[i][2] = 0;
               break;
            default:
               cout << '\t';
               for (int j = 1; story[i][j] != '>'; j++)
               {
                  if (j == 1)
                     cout << (char)toupper(story[i][j]);
                  else if (story[i][j] == '_')
                     cout << ' ';
                  else
                     cout << story[i][j];
               }
               cout << ": ";
               cin.getline(story[i], 256);
         }
      }
   cout << endl;
   return;
}

/**********************************************************************
 * The display function makes the data in the array readable to humans
 * by including things like punctuation and spacing. 
 ***********************************************************************/
void display(char story[][32], int size)
{

   for (int i = 0; i < size; i++)
   {
      cout << story[i];
      
      if (story[i + 1][0] != '\"' &&         
         story[i + 1][0] != ' ' &&         
         story[i][0] != ' ' &&         
         story[i + 1][0] != '.' &&         
         story[i][0] != '\n' &&         
         story[i + 1][0] != '\n' &&         
         story[i + 1][0] != ',' &&         
         story[i + 1][0] != '?' &&         
         story[i + 1][0] != '\'' &&         
         story[i + 1][0] != '!')
        
         cout << ' ';
    
   }
   return;
}
