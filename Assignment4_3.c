/*
 *
 * Write a program that replaces the occurence of a given character (say c)
 * in a primary string (say PS) with another string (say s).
 *
 * Input:
 * The first line contains the primary string (PS)
 * The next line contains a character (c)
 * The next line contains a string (s)
 *
 * Output:
 * Print the string PS with every occurence of c replaced by s.
 *
 * NOTE:
 * - There are no whitespaces in PS or s.
 * - Maximum length of PS is 100.
 * - Maximum length of s is 10.
 * */

//Pre-Requistes: String indexing operations.

#include <stdio.h>
#include <string.h>

#define sf    scanf
#define pf    printf

int main()
{
   char ps[100]; //An character array of size 100

   sf("%s", ps); //Scanning the array of characters
   char c;       //Character which we are going to replace
   sf(" %c", &c);
   char s[10];   //The replacement string
   sf("  %s", s);
   //Basic logic is, instead of modifying the main string which will complicate things
   //We simply create another string and wherever the character c shows up we replace further characters by s.
   char ss[100];
   int  count = 0;      //Keeps count of the newly created string in which we are going to store our answer
   for (int i = 0; ps[i] != '\0'; i++)
   {
      if (ps[i] == c)                       //Checking if the letter in the main string is matching the one that we need to replace
      {
         for (int j = 0; s[j] != '\0'; j++) //replace everything until s teminates, as this is a replacement string
         {
            ss[count] = s[j];
            count++;                            //This keeps incrementing till it hits the end of replacement string
         }
      }
      else
      {
         ss[count] = ps[i];                     //else we just copy the data of main string into our output string like a GANGSTA!
         count++;
      }
   }
   ss[count] = '\0';    //Important: Every string must be terminated by '\0', otherwise the program may behave like it is on fire
   pf("%s", ss);        //Printing the output string
   return 0;
}


//Again, if you dont't know the following things then I highly recommend you to ignore is.
//The statement below are for my OCD.
//Time Complexity: Constant amount of time required.
