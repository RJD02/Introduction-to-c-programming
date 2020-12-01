/*
 * You are given a sorted(either in the increasing or in the decreasing order) sequence of positive numbers, ending with a -1. You can assume that there are atleast three numbers(i.e we have to take atleast three variables or containers) before the ending -1.
 *
 * Note : -1 is not a part of input. It only signifies that input has ended.
 * We have to ignore the last -1
 *
 * Let us call the sequence x0  x1 ... xn -1.
 *
 * You have to output 1 if there are atleast three distinct numbers in the sequence.
 * otherwise output 0
 * Here distinct mean, x0 != x1 != x2.
 * That is all three numbers are different
 *
 * Below is the most important point
 * Kindly do not use arrays in the code
 */

#include <stdio.h>

int main()
{
   int x0 = 0, x1 = 0, x2, count_of_distinct = 0;       //Why initialize?

   //Because the variables might contain garbage values, which might be counted as distinct, there is a fair probability of this happening.
   //This also ensures that atleast two of them have same values to begin with
   for (int i = 0; x2 != -1; i++) //You can also use a while loop
   {
      scanf("%d", &x2);           //Scanning the latest value
      x0 = x1;
      x1 = x2;                    //Cycling to replace the previous and previous to previous values as we head forward
      if (x0 != x1)               //First check if previous and current are equal
      {
         count_of_distinct++;     //If they are distinct then increase the counter, that is count this pair
      }
      if (count_of_distinct > 3)  //According to the problem we just need to find three distinct numbers which are not equal to each other
      {                 //If we find it we just print 1,which is according to the problem statement
         printf("1");
         return 0;                      //Notice that I have terminated the main function here
         //If we find three distinct numbers then we don't care what lies ahead
         //We can rest assure that atleast one pair exists and that's all we want to do
         //So after this we can simply terminate the whole program
      }
   }
   printf("0");         //If we don't find any distinct triplets or pairs, then we simply state that the array of numbers given to us doesn't have any
   //Now we can terminate our program for good.
   return 0;
}
