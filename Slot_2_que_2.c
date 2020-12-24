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