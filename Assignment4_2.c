/*
 *Find the number of distinct numbers in a given sequence. The sequence need not be sorted.


Input
The input consists of two lines.
The first line consists of a positive number N. N is at most 1000. -> fits in ANSI C int
The second line consists of N numbers separated by spaces.

Output
The output should be the number of distinct elements in the sequence.

Sample Input
4 
1 2 3 1 


Sample Output
3
*/
//Same as Assignment2_2.c
//refer that to get the general idea
//Pre-Requistes: Array indexing operations and passing array by value, and by reference

#include<stdio.h>
//To make life easier
#define sf scanf
#define pf printf

//To scan the array
void scanArray(int *a, int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &*(a + i));
	}
}

//Insertion sort to sort the given array
void sort(int *a, int n) {
	for(int i = 1; i < n; i++) {
		int key = *(a+ i); int j = i - 1;
		while( j >= 0 && key < *(a + j)) {
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = key;
	}
}

//So, my basic idea is to take the array, sort it, and then do a linear search
//That is, when the elements will be sorted, the work will get easier, since we have to only compare the current element and the previous element
int main() {
	int n;
	sf("%d", &n);	//Scanning the size of the array
	if(n <= 1) {	//Base condition, since it is not possible to find disntinct element with only one value
		pf("%d", n);
		return 0;
	}
	int a[n];
	scanArray(a, n); sort(a, n);	//This is allowed, until you put semicolons in the right space and in right order
	int count = 1, val = a[0]; int prev = a[0];	//This is allowed too. With this initialization we skip one iteration
	for(int i = 1; i < n; i++) {
		if(val == a[i] || a[i] == prev)	//Same comparison, since we dont want any repetition in our distinct elements!
			prev = a[i];
		else if(val != a[i] && a[i] != prev){	//If the elment are distinct increment the counter.
			prev = a[i];
			count++;
		}
	}
	pf("%d", count);	//Print the count of numbers which are distinct in the given array
	return 0;
}
//Again, if you dont't know the following things then I highly recommend you to ignore is.
//The statement below are for my OCD.
//Time complexity is: O(n ^ 2)
//which can be reduced by using merge sort or heap sort
//Best running time: O(n * lgn)
