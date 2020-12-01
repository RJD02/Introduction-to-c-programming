/*
 * Write a C function to find the kth occurrence of an odd integer in a sequence of non-negative integers, and then call your function from main.
 *
 * Your function should be according to the following declaration:
 *
 * int find_odd(int k);
 *
 * Input
 * You are given the input in two lines:
 *
 * The first line contains a positive integer k.
 * In the second line, you will be given a sequence of numbers.
 *
 * You have to find the kth occurrence of n in the sequence below.
 *
 * The second line consists of a sequence of non-negative integers,
 * terminated with a -1.  The -1 is not part of the sequence.
 *
 * Output
 * If there are  k odd numbers in the sequence, then output the  kth
 * occurrence of odd in the sequence. Otherwise, output  -1.
 *
 *
 * Sample Input
 * 2
 * 1 1 3 2 3 4 1 -1
 *
 * Sample Output
 * 1
 *
 * */

//Main flaw in this problem is they have not specified the working of this find_odd(int k) function which I'm going to use
//to my advantage and design something very simple
#include <stdio.h>

int find_odd(int k);

int main()
{
   int k;

   scanf("%d", &k);
   int i = 0;
   do
   {
      if (find_odd(i))
      {
         k--;
         if (k == 0)
         {
            printf("%d", i);
            return 0;
         }
      }
      scanf("%d", &i);
   } while (i != -1);
   printf("-1");
   return 0;
}


//As I said earlier that I'm going to use their mistake to my advantage
//So, my function only returns a boolean yes ot no
//Which hardly saves me 2 lines in main function
//But you have to find a suitable function that this find_odd() finction can do
//Think abour it and implement it on your local machine
//Anyways, my find_odd() function just returns 1 or 0
//Which is enough for me as the condition evaluated in if() are either true of false, which is equivalent to 1 or 0
int find_odd(int k)
{
   if (k % 2 == 1)      //if a number is divisible by 2 then it is indeed an even number
   {
      return 1;         //Another clever termination, since if condition is true, that's all we want, so we terminate the function giving it an return value.
   }
   return 0;            //If out initial condition fails then we return 0, otherwise we don't even reach till this statement, cause our function is terminated above.
}
