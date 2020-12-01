/*
 * We say that a string 's' is an anagram of another string 't' if the
 * letters in 's' can be rearranged to form 't'.
 *
 * For example, "butterfly" is an anagram of "flutterby", since a
 * rearrangement of the first word results in the second.
 *
 * We say that a position 'i' in 's' and 't' match, if 's' is an anagram of
 * 't', and s[i]==t[i].
 *
 * In this question, you will be given two words, 's' and 't'. You have
 * to output the number of matching positions if s is an anagram of t,
 * and -1 if s is not an anagram of t.
 *
 * Input
 * -----
 * The input consists of two lines. The first line contains the first
 * string, with length <= 100 characters. The second line contains the
 * second string, with length <= 100 characters.
 *
 * Output
 * ------
 * If the first string is an anagram of the second string, then output
 * the number of matching positions. Otherwise, print -1.
 *
 * Sample Input 1
 * --------------
 * butterfly
 * flutterby
 *
 * Sample Output 1
 * ---------------
 * 2
 *
 * Sample Input 2
 * --------------
 * home
 * come
 *
 * Sample Output 2
 * ---------------
 * -1
 * */

//Pre-Requisite: Character array passing by value and by reference

#include <stdio.h>
#include <string.h>

//Sorting the character array
//Remember that characters are numbers with special meaning, so they can be treated as numbers , as in array of numbers
//Just the implementation of Insertion Sort
void sort(char *a)
{
   for (int i = 1; *(a + i) != '\0'; i++)
   {
      int  j   = i - 1;
      char key = *(a + i);
      while (j >= 0 && key < *(a + j))
      {
         *(a + j + 1) = *(a + j);
         j--;
      }
      *(a + j + 1) = key;
   }
}


//This function checks if after sorting we have anything uncommon
int check(char a[], char b[])
{
   sort(a);
   sort(b);
   for (int i = 0; *(a + i) != '\0'; i++)
   {
      if (a[i] != b[i])                 //Since anagram must have same lengths and must have same letter frequency, if this fails we return and say that this is not a anagram
      {
         return 0;
      }
   }
   return 1;            //Else it is an anagram
}


//This function checks the frequency of characters in both array, or string
int freq(char a[], char b[])
{
   int count = 0;

   for (int i = 0; *(a + i) != '\0'; i++)
   {
      if (a[i] == b[i])
      {
         count++;
      }
   }
   return count;
}


int main()
{
   char s[100], t[100];

   scanf("%s %s", s, t);
   char a[100], b[100];
   //I have creted another copy of bith arrays, because when I pass in by value, the original array got sorted, which I don't want
   //It's a bug that I haven't fixed and found a way across it
   //If you find it, then just message me!
   for (int i = 0; s[i] != '\0'; i++)
   {
      a[i] = s[i];
   }
   for (int i = 0; t[i] != '\0'; i++)
   {
      b[i] = t[i];
   }
   if (!check(s, t) || (strlen(s) != strlen(t)))
   {
      printf("-1");
      return 0;
   }
   printf("%d", freq(a, b));            //Outputs the number of matching characters from both arrays or strings
   return 0;
}


//Time Complexity; O(n ^ 2);
