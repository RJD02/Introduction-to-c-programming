/*
 * A sequence of positive numbers is defined as :
             
          f(n) = f(n-1) + f(n-2)  for all n >2

and f(1) ,f(2) are defined explicitly.

For example : If we define f(1) = 1 and f(2) =2

Then the sequence obtained is 1 2 3 5 8 13.........

The distance of two numbers a and b is defined as the |a-b| or the positive difference of the numbers.
For example: Distance of 2 and 3 is |2-3|=1 .
                      Distance of 14 and 9 is |14-9| = 5

In this question you will be given the first two elements of the sequence separated by the space and in next line a number let say p. 
You need to output the minimum distance of p to the elements of sequence.
 
Example : 
I/P : 1 1
       6
So, the sequence is 1 1 2 3 5 8 13.......
Minimum distance of 6 to sequence is |5-6| = 1
O/P : 1
Constraints :
First two elements(f(1) and f(2)) of the sequence are in monotonically increasing order and are positive integers. 
p is an integer.
* */

//Pre_Requisites: This time actually google recursion and understand basics of recursion. And the difference between iteration and recursion

//All three algorithms work
//YUP, they all do
//We will one by one analyse each of them
#include<stdio.h>
#include<stdlib.h>

#define sf scanf
#define pf printf

//This one is a recursive function
//First check the return type of the function
int checking(int n1, int n2, int p) {	//Here n1 = f(n - 1), n2 = f(n - 2) and p = number that we have to find whether it exists in the sequence or not
	if(n1 >= p) return abs(p - n1);	//abs() returns the absolute value, that is the |n1 - n2|, mod of the difference
	if(n2 >= p) return abs(p - n2);	//If either of the n1, or n2 are close to p then we will simply return their difference
	return checking(n2, n1 + n2, p);	//Now this is a recursive call
	//Note that we actually fulfilled our base condition and then when everything was good, we made a recursive call
	//In recursion, this is the thing that we have to be carefull about.
}

//This one is a iterative functiom
int check(int n1, int n2, int p) {
	int curr = n1 + n2, min = 1000;	//I needed a plus INFINITY, and c doesn't have INFINITY, so I have to initialize it with a random max value
	//The current already starts adding these two.
	if(p <= n1) 	//Base condition
		return abs(p-n1);
	if(p <= n2) return abs(p-n2);
	for(; curr < p; ) {
		n1 = n2;	//To cycle.
		n2 = curr;
		curr = n1 + n2;
	}
  return abs(curr - p);
}

int main() {
	int n1, n2, p;
	sf("%d %d %d", &n1, &n2, &p);
	pf("%d", checking(n1, n2, p));
	return 0;
}
//Since this problem is close to Fibonnaci Number Problem, this doesn't have a runtime
