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