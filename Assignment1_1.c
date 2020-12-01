/*
 * You will be given 3 integers as input. The inputs may or may not be
 * different from each other.
 * You have to output 1 if sum of first two inputs is greater than the third input,
 * and 0 otherwise
 * Input
 * -------------------------------------
 * Three integers separated by space.
 *
 * Output
 * ----------------------------------
 * 1 if sum of first two inputs is greater than third input
 * 0 otherwise
 *
 *
 */
//Pretty Self-Explanatory
#include <stdio.h>

int main()
{
   int first, second, third;                   //Variables to get and store the numbers.

   scanf("%d %d %d", &first, &second, &third); //Scanning the inputs
   if (first + second > third)                 //according to the problem statement we have to check whther the first two numbers are greater than the third
   {
      printf("1");                             //Required output
   }
   else
   {
      printf("0");              //If the condition fails
   }
   return 0;
}
