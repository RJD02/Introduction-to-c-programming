/*
 * You are given two integers, say M and N.
 * You have to output 1, if remainder is 1 when N divides M
 * otherwise output 0
 *
 * Input
 * ----------------------------
 * Two integers, say M and N.
 *
 * Output
 * ---------------------------------------------------
 * You have to output 1 if remainder is 1 when M/N.
 * You have to output 0 , otherwise.
*/

#include<stdio.h>

int main() {
	int m, n;	//Declaring containers
	scanf("%d %d", &m, &n);	//Scanning variables
	if(m % n == 1) {	//We use modulo operator to get remainder.
		printf("1");	//if condition is true
	}
	else {
		printf("0");	//if the above condition is not satisfied.
	}
	return 0;
}
