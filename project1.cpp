/***********************************************************************
* Program:
*    
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
#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/

float computeTax(float income);
float computeTithing(float income);
float getIncome();
float getBudgetLiving();
float getActualLiving();
float getActualOther();
float getActualTithing();
float getActualTax();
void display();

/*************************************************
 * Function to get income
 ************************************************/
float getIncome()
{
   float income;   
   // Prompt for monthly income
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/*************************************************
 * Function to get budgeted living expenses
 ************************************************/
float getBudgetLiving()
{
   // Prompt for living expenses
   float budgetLiving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;
}

/*************************************************
 * Function to get actual living expenses
 ************************************************/
float getActualLiving()
{
   
   float actualLiving;
   // Prompt for actual living expenses
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}

/*************************************************
 * Function to get actual tax
 ************************************************/
float getActualTax()
{
   float actualTax;
   // Prompt for actual other expenses
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;
   return actualTax;
}

/*************************************************
 * Function to get actual tithe offerings
 ************************************************/
float getActualTithing()
{
   float actualTithing;
   // Prompt for actual tithe offerings
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   return actualTithing;
}

/*************************************************
 * Function to get actual other expenses
 ************************************************/
float getActualOther()
{
   float actualOther;
   // Prompt for actual other expenses
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;
}

/*************************************************
 * Function to display all information
 ************************************************/
void display(float income,float budgetLiving,float actualTax,
             float actualTithing,float actualLiving, float actualOther)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   float budgetTax = computeTax(income);
   float budgetTithing = computeTithing(income);
   float budgetOther = income - budgetTax -
      budgetTithing - budgetLiving;
   float actualDifference = income - actualTax -
      actualTithing - actualLiving - actualOther;
   float budgetDifference = income - budgetTax - budgetTithing
      - budgetLiving - budgetOther; 
   cout << endl;
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11)
        << income << "    $" << setw(11) << income << endl;   
   cout << "\tTaxes           $" << setw(11)
        << budgetTax << "    $" <<  setw(11) << actualTax << endl; 
   cout << "\tTithing         $" << setw(11)
        << budgetTithing << "    $" << setw(11) << actualTithing << endl;  
   cout << "\tLiving          $" << setw(11)
        << budgetLiving << "    $" << setw(11) << actualLiving << endl;
   cout << "\tOther           $" << setw(11)
        << budgetOther << "    $" << setw(11) << actualOther << endl;  
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11)
        << budgetDifference << "    $" << setw(11) <<
      actualDifference << endl;  
   return;
}

/*************************************************
 * Function to compute taxes from income
 ************************************************/
float computeTax(float income)
{
   float yearly = income * 12;
   float rate;
   if (yearly >= 0 && yearly < 15100)
      rate = yearly * .10;
   else if (yearly >= 15100 && yearly < 61300)
      rate = 1510 + (yearly - 15100) * .15;
   else if (yearly >= 61300 && yearly < 123700)
      rate = 8440 + (yearly - 61300) * .25;
   else if (yearly >= 123700 && yearly < 188450)
      rate = 24040 + (yearly - 123700) * .28;
   else if (yearly >= 188450 && yearly < 336550)
      rate = 42170 + (yearly - 188450) * .33;
   else if (yearly >= 336550)
      rate = 91043 + (yearly - 336550) * .35;

   rate = rate / 12;

   return rate;
}

/**********************************************************************
 * Function to compute the amount of tithing needed
 ***********************************************************************/
float computeTithing(float income)
{
   return income * .1; 
}

/**********************************************************************
 * Main calls for other functions to return information, and assigns other
 * functions to do calculations and display results.
 ***********************************************************************/
int main()
{
   // Greeting
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   
   float income = getIncome();
   float budgetLiving = getBudgetLiving();
   float actualLiving = getActualLiving();
   float actualTax = getActualTax();
   float actualTithing = getActualTithing();
   float actualOther = getActualOther();
   display(income, budgetLiving, actualTax, actualTithing, actualLiving,
      actualOther);
}
