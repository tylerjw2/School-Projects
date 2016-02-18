/***********************************************************************
 * Program:
 *    
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
#include <iomanip>
using namespace std;

bool isLeapYear();
void display(int numdays, int offset, int month, int year);
int computeOffset(int month, int year);
void displayTable(int offset, int daysMonth);
void displayHeader(int month, int year);
int numDaysMonth(int month, int year); // return num days in a given month
int numDaysYear(int year); // return num days in a given year
int getMonth();
int getYear();

/**********************************************************************
 * Main calls the month, year, number of days, and offset functions,
 * then calls display to show the result
 ***********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int numdays = numDaysMonth(month, year);
   int offset = computeOffset(month, year);
   cout << endl;
   display(numdays, offset, month, year);
}

/**********************************************************************
 * This function prompts the user to enter a number of the month
 * between 1 and 12
 ***********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;
   while (month > 12 || month < 1)
   {
      cout << "Month must be between 1 and 12." << endl;
      cout << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

/**********************************************************************
 * This funtion prompts the user for a year from 1753 or later
 *
 ***********************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;
   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> year;
   }

   return year;
}

/**********************************************************************
 * This function determines whether a given year is a leap year
 *
 ***********************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 != 0)
      return false;
   else if (year % 100 != 0)
      return true;
   else
      return (year % 400 == 0);
}

/*******************************************************************
* This funtion either returns the normal number of days in a year
 * or adds one depending on if it's a leap year
 ***********************************************************************/
int numDaysYear(int year)
{
   if (isLeapYear(year) == true)
      return 366;
   else
      return 365;
}

/**********************************************************************
 * This function determines how many days will display for a given month
 *
 ***********************************************************************/
int numDaysMonth(int month, int year)
{
   if (isLeapYear(year) && month == 2)
      return 29;
   else
   {
      int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      return days[month];
   }
}
/**********************************************************************
 * This function computes the offset depending on what day of the week
 * the month starts on
***********************************************************************/
int computeOffset(int month, int year)
{
   int sum = 0;
   for (int i = 1753; i < year; i++)
   {
      if (isLeapYear(i))
         sum += 366;
      else
         sum += 365;
   }
   
   for (int i = 1; i < month; i++)
   {
      sum += numDaysMonth(i, year);
   }

   return sum % 7;
}

/**********************************************************************
 * This function displays the table
 *
 ***********************************************************************/
void displayTable(int offset, int daysMonth)
{
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   for (int i = 0; i <= offset && offset != 6; i++)
      cout << "    ";

   for (int i = 1; i <= daysMonth; i++)
   {
      cout << setw(4) << i;
      if ((i + offset + 1) % 7 == 0 && i != daysMonth)
         cout << endl;
   }

   cout << endl;

}

/**********************************************************************
 * This function displays the month and year in the header
 *
 ***********************************************************************/
void displayHeader(int month, int year)
{
   if (month == 1)
   {
      cout << "January, ";
   }
   else if (month == 2)
   {
      cout << "February, ";
   }

   else if (month == 3)
   {
      cout << "March, ";
   }

   else if (month == 4)
   {
      cout << "April, ";
   }

   else if (month == 5)
   {
      cout << "May, ";
   }

   else if (month == 6)
   {
      cout << "June, ";
   }

   else if (month == 7)
   {
      cout << "July, ";
   }

   else if (month == 8)
   {
      cout << "August, ";
   }
   else if (month == 9)
   {
      cout << "September, ";
   }

   else if (month == 10)
   {
      cout << "October, ";
   }

   else if (month == 11)
   {
      cout << "November, ";
   }

   else if (month == 12)
   {
      cout << "December, ";
   }
   cout << year << endl;
   return;
}

/**********************************************************************
 * This function simply calls all information together to display it
 *
 ***********************************************************************/
void display(int numdays, int offset, int month, int year)
{
   displayHeader(month, year);
   displayTable(offset, numdays);
   return;
}
