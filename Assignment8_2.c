/*
 * You are given a non-negative number less than or equal to 100000000 (1
 * followed by 8 zeroes). You have to divide the number into the
 * following components, and print them in the following order.
 *
 * 1. The part of the number which is less than a thousand.
 * 2. The part of the number which is between a thousand and a lakh
 * 3. The part of the number which is between a lakh and a crore
 *
 * and so on. You should terminate printing when no higher power of 10 is
 * present to be printed.
 *
 * For example, suppose the input number is
 *
 * 134847
 *
 * Then the output should be
 * 847
 * 34
 * 1
 *
 * The question can be done with or without using arrays.
 *
 * Hint: Using % (that is, the modulo operator) and / (the division
 * operator on integers) is helpful in solving this question
 * */

#include <stdio.h>
#include <stdlib.h>

#define pf(n)    printf("%d\n", (int)n)
#define sf(n)    scanf("%d", &n);

int main()
{
   int n;

   sf(n);
   pf(n % 1000);
   n = n / 1000;
   while (n > 0)
   {
      pf(n % 100);
      n = n / 100;
   }
   return 0;
}
