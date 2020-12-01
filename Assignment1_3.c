/*
 * Input : Triplet of three numbers (a,b,c)
 * Output : 1 if they are either in strictly increasing (a>b>c) or decreasing (a<b<c) order
 * 0, otherwise.
 *
 */

#include <stdio.h>

int main()
{
   int a, b, c;                   //declaring variables

   scanf("%d %d %d", &a, &b, &c); //scanning the variables from input
   //This is a bit tricky part
   //For this understand that in c, the decision statements are evaluated from right to left in case of or(||) condition
   //And in case of and(&&) condition the condition is evaluated from right to left
   //Reading the problem clarifies the strictly increasing and decreasing part.
   if (((a > b) && (b > c)) || ((c > b) && (b > a)))    //The condition to check strictly increasing and decreasing
   {
      printf("1");
   }
   else
   {
      printf("0");
   }
   return 0;
}
