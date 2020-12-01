/*
 * Create a database of students using structures, where in each entry of the database will have the following fields:
 * a name, which is a string with at most 128 characters
 * their marks in physics which is an int between 0 and 100
 * their marks in chemistry which is an int number between 0 and 100
 * their marks in mathematics which is an int number between 0 and 100
 * You have to output a list of students in the following order.
 * if a student 'A' has lower marks in physics than a student 'B', then A's data is listed before B.
 * If A and B have the same physics marks and A has lower chemistry marks than B, then A is listed before B.
 * If A and B have the same marks in physics and chemistry, and A has lower marks in mathematics than B, then A is listed before B.
 * If all marks are equal and A's name precedes B's name in the dictionary order, then A is listed before B.
 * .
 *
 * Input Format :
 * First line contains the number of students n, where 1<=n<=100.
 * In following n lines each line contains(space separated)  a name and their respective marks in physics, chemistry, maths, where 0<=marks<=100.
 *
 * Output Format :
 * Sorted database of n lines
 * */

#include <stdio.h>
#include <stdlib.h>

#define sf    scanf
#define pf    printf

struct Student
{
   char name[128];
   int  phy, chem, math;
};

typedef struct Student Student;

void swap(Student *a, Student *b)
{
   Student temp = *a;

   *a = *b;
   *b = temp;
}


void compare(Student *a, int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (a[i].phy > a[j].phy)
         {
            swap(&a[i], &a[j]);
         }
      }
   }

   for (int i = 0; i + 1 < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if ((a[i].phy == a[j].phy) && (a[i].chem > a[j].chem))
         {
            swap(&a[i], &a[j]);
         }
      }
   }

   for (int i = 0; i + 1 < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if ((a[i].phy == a[j].phy) && (a[i].chem == a[j].chem) && (a[i].math > a[j].math))
         {
            swap(&a[i], &a[j]);
         }
      }
   }
}


void printDetails(Student *a, int n)
{
   for (int i = 0; i < n; i++)
   {
      pf("%s-%d-%d-%d\n", a[i].name, a[i].phy, a[i].chem, a[i].math);
   }
}


int main()
{
   int n;

   sf("%d", &n);
   Student s[n];
   for (int i = 0; i < n; i++)
   {
      sf("%s", s[i].name);
      sf(" %d %d %d", &s[i].phy, &s[i].chem, &s[i].math);
   }
   compare(s, n);
   printDetails(s, n);
   return 0;
}
