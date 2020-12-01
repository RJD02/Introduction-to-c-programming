/*
 * Write a C program to list all the factorial numbers less than or equal
 * to an input number n.
 *
 * A number N is called a factorial number if it is the factorial of a
 * positive integer. For example, the first few factorial numbers are
 *
 * 1, 2, 6, 24, 120, ...
 *
 * Note* - We do not list the factorial of 0.
 *
 * Input
 * -----
 * A positive integer, say n.
 *
 * Output
 * ------
 * All factorial numbers less than or equal to n.
 *
 */

//I know this is kinda no-brainer but
//Pre-Requisite: You should know what a factorial is
//or the notation n!

#include <stdio.h>
//This function basically gives us the value of factorial
//Again, this method can be implemented using recursion, but I'm fan of KISS.
int factorial(int k)
{
   int re = 1;

   for (int i = 1; i <= k; i++)
   {
      re = re * i;
   }
   return re;
}


//Just suck the logic up, there's nothing much I could explain above
int main()
{
   int n;

   scanf("%d", &n);
   int i    = 1;
   int fact = factorial(i);
   while (n >= fact)          //We are stepping into while loops
   {
      printf("%d ", fact(i)); //The idea is to iterate through this whole n numbers and print all the factorials
      i++;                    //Just a simple post-increment
   }
   return 0;
}
