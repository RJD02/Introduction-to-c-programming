/*
You are given 5 dice, each having numbers 1 to 6. A player throws
all the five dice. Depending on the outcome, the player gets a certain
number of points.


1. If all numbers are the same, then the player gets the sum of the
numbers + 2000

2. If at least three numbers are the same but not all 5 are the same
number, then the player gets the sum of all the numbers + 1000

3. If all numbers are different, the player gets the sum of the
numbers + 500

4. Otherwise, the player gets the sum of the numbers.

You are given a sequence of 5 numbers, each from 1 to 6, representing
the outcome of the throw. You should output the score, calculated
according to the rules above.

Sample Input 1
--------------
1 2 3 4 5

Sample Output 1
---------------
515

Sample Input 2
--------------
5 5 5 5 5

Sample Output 2
---------------
2025

Sample Input 3
--------------
4 4 4 5 4

Sample Output 3
---------------
1021
*/

#include <stdio.h>
int main()
{
    //Purely implementation.
    int a, b, c, d, e, sum = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if (a == b && b == c && c == d && d == e)
    {
        sum = 2000 + a * 5;
        printf("%d", sum);
    }
    else if (a == b && b == c || b == c && c == d)
    {
        sum = 1000 + a + b + c + d + e;
        printf("%d", sum);
    }
    else if (a != b && b != c && c != d && d != e)
    {
        sum = 500 + a + b + c + d + e;
        printf("%d", sum);
    }
    else
    {
        sum = a + b + c + d + e;
        printf("%d", sum);
    }

    return 0;
}