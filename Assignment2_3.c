/*
 * You are given a non-negative sequence of numbers, ending with a -1. You can assume that there are at least two numbers(i.e. we must have atleast two variables) before the ending -1.
 *
 * Note : -1 is not a part of input. It only signifies that input has ended.
 * We need to ignore the last -1
 *
 * Let us call the sequence x0  x1 ... xn -1.
 *
 * You have to output the second largest element of the sequence. if there is no second largest element in the sequence then output 0.
 *
 * Kindly do not use arrays in the code.
 */

#include <stdio.h>

int main()
{
   int x0 = 0, x1 = 0, x2 = 0;          //Declaring three variables
   int highest = 0, second_highest = 0; //Declaring two variables for storing highest and second-highest number of the sequence given

   //Why initialise?
   //Because it is given that the numbers are non-negative and will be greater than zero
   //Thus we save our program by an if condition to check if the declared variables are zero
   //You need to plan before coding
   while (x2 != -1)             //we scan till the sequence is terminated by -1
   {
      scanf("%d", &x2);
      x0 = x1;
      x1 = x2;                          //Cycling the values as we move ahead
      if (highest < x1)                 //finding the highest in the sequence
      {                 //And only way to do that is by looking at the current elment.
         second_highest = highest;      //Now that we found the highest we can store the previous or second highest element in out variable
         highest        = x1;           //Setting the highest value we found till now
      }
   }
   printf("%d", second_highest);        //Printing the second highest value from the sequence
   return 0;
}


//For side problem,
//Solve this problem using arrays and message me
//"DONE!!"
