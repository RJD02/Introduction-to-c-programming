/*
 *
 * In this question, you have to output the "moving average" of a
sequence of non-negative numbers. The moving average is the sequence
of averages of the last 2 entries. For the first number, no average
is output.
Notice that we need atleast two variables.
For example, if the sequence of numbers is

a1, a2, a3, a4, a5

then the 2-moving average is

(a1+a2)/2, (a2+a3)/2, (a3+a4)/2, (a4+a5)/2 


Input
-----

The input is a sequence of non-negative floating point numbers,
terminated by a -1. The -1 is not part of the sequence. There will be
at least 3 numbers in the sequence.

Output
--------------------------------------------------------------------------------------------
You have to output the moving average of the sequence. The output
should be printed correct to one digit after the decimal. 
 *
 * */

#include<stdio.h>

int main() {
	float a, a1;	//Since our sequence is a floating sequence i.e. it contains all decimal values
	scanf("%f", &a);	//equivalent to do while loop
	for(;;) {
		a1 = a;	//Cycling the previous value
		scanf("%f",&a);
		if(a == -1) //Base condition
			break;
		printf("%.1f ", (a + a1) / 2);	//in c programming language you can specify the amount of digits you want by specifying the number as in format specifier
	}
	return 0;

}
//If you are thinking I'm writing do while or whilel loop can be used then why am I not using it
//We will be looking at clever do while loops but for that we first need to look at amount lines we waste without those loops
//I am well equiped with a begineer's trouble finding logic... so for now I'm keeping it simple
//You should also follow KISS principle
/*
 * K = Keep
 * I = It
 * S = Simple
 * S = Stupid
 *
*/
