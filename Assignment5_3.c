/*
 * Write a recursive program to print the reverse of the string ending with 0.
 * Input : String ending with 0
 * Output : Reverse of the string without 0.
 *
 * Example : I/P : abcd0
 *              O/P: dcba
 * NOTE: You have to use recursion to solve this, and are NOT allowed to use array to store the input!!
 * */

//Pre-Requisite: Understanding beetween recursion and iteration

#include <stdio.h>

void revstr()
{
   char c = getchar();          //To read input from the keyboard

   if (c == '0')
   {
      return;           //Since in problem statement it is given that the string will be terminated by '0'
   }
   revstr();            //A recursive call
   putchar(c);          //Puts the character to the terminal
}


//I recommend using pen and paper and trying out following example

/*
 * INPUT: asdfg0
 * Try using pen and paper and trck the revstr function.
 */

//Simple enough
int main()
{
   revstr();
   return 0;
}


//Time complexity: Constant
