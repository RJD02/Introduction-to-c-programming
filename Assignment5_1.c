/*
 * The Collatz function is defined for a positive integer n as follows.
 *
 * f(n) = 3n+1 if n is odd
 *
 *     = n/2     if n is even
 *     = 1 if n=1
 *
 *
 * We consider the repeated application of the Collatz function starting with a given integer n, as follows:
 *
 * f(n), f(f(n)), f(f(f(n))), …
 *
 *
 * It is conjectured that no matter which positive integer n you start from, this sequence eventually will have 1 in it. It has been verified to hold for numbers up to 5 × 260  [Wikipedia: Collatz Conjecture].
 *
 *
 * e.g. If n=7, the sequence is
 *
 * f(7) = 22
 *
 * f(f(7)) = f(22) = 11
 *
 * f(11) = 34
 *
 * f(34) = 17
 *
 * f(17) = 52
 *
 * f(52) = 26
 *
 * f(26) = 13
 *
 * f(13) = 40
 *
 * f(40) = 20
 *
 * f(20) = 10
 *
 * f(10) = 5
 *
 * f(5) = 16
 *
 * f(16) = 8
 *
 * f(8) = 4
 *
 * f(4) = 2
 *
 * f(2) = 1
 *
 * Thus if you start from n=7, you need to apply f 16 times in order to first get 1.
 *
 *
 * In this question, you will be given a positive number <= 32,000. You have to output the sequence when f is applied consecutively till 1.
 * */

//Pre-Requuistes: Knowledge of recursion, and I mean real knowledge, not what Veena mam taught us, go search for recursion and comeback to this point
//I will wait!
//Knew you will not go, comeon, I will figure some logic out for your laziness

#include <stdio.h>
#include <stdlib.h>

//Just to make life easy
#define sf(n)    scanf("%d", &n)
#define pf(n)    printf("%d ", (int)n)

//This is the iterative one, and I want you to implement your own recurive function
//For now, let's analyse the below function
void iterativeCollatz(int n)
{
   if (n == 1)  //Cannot perform any action if n = 1, and just print 1, these cases are called edge cases
   {
      printf("1");
   }
   while (n != 1)
   {
      if (n % 2 == 1)           //As condition states if even n = 3n + 1.
      {
         n = 3 * n + 1;
      }
      else
      {
         n = n / 2;                     //And if odd n = n/2
      }
      pf(n);
   }
}


int main()
{
   int n;

   sf(n);
   iterativeCollatz(n);         //calling the void type function called iterativeCollatz and passing the input parameter
   return 0;
}


//Again, if you don't understand following lines, don't bother
//Time Complexity: depends on n.
