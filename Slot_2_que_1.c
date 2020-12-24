/*
You are given two strings representing the first name and the
surname of a person. The first name is separated from the surname by a
single ':' character. The end of the surname is indicated by a second
':' character.

Both the first name and the surname will have at least one character,
and each will have at most 100 characters. 

You must output the properly capitalized version of the first name and
the surname. The first letter of the first name and the first letter
of the surname must be capitalized. All other letters must be small
letters. You must separate the first name from the surname by a ':'
and also terminate the surname with a ':'.

Sample Input 1
--------------
joHn:SMITH:

Sample Output 1
---------------
John:Smith:

Sample Input 2
--------------
jAne:Doe:


Sample Output 2
---------------
Jane:Doe:
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char tolower1(char a) {
	if(a >= 'A' && a<='Z')
      a = a + 32;
  return a;
}

int main()
{
   int i, j, n, m, count = 0;
   char name[200], surname[100];
   scanf("%s", name);
   for(i = 0; name[i] != ':'; i++)
   	count++;
   for(i = 0; name[i] != '\0'; i++)
   	name[i] = tolower1(name[i]);
   name[0] = name[0] - 32;
   name[count] = ':';
   count++;
   name[count] = name[count] - 32;
   printf("%s\n", name);
   return 0;
}