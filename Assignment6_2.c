/*
 * A graph is abstractly a collection of vertices which are labelled by
non-negative integers, and a collection of edges. A graph called an
undirected graph if we talk of merely the presence of an edge between
vertices i and j, rather than its direction. 

For example, the following is a graph:


In this problem, you are given the edges in an undirected graph. An
edge is a pair of non-negative integers (i, j) which indicates that
the vetex i is connected to vetex j by an edge.

Afterwards, you will be given a vertex number n. You have to output
the list of vertices which are connected n by an edge, in the order in
which the edges were input.

Input

You are given the following.

1. The first line contains an integer, E, between 1 and 1000

2. This is followed by E lines, where each containing a pair of
numbers i and j where i and j are both non-negative integers <=
34,000. No edge will be listed more than once.

3. The last line contains a non-negative integer n <= 34,000. n is
assured to be a vertex listed in one of the E lines in part (2).

Output

You have to output the list of nodes to which n has an edge, in the
order in which the edges were input, one line for each vertex.
* */

//For this I actully have two algorithms, that is I have two solutions
//The one with structure is in file called Assignment6_2_alter.c

//For now lets look at
//Algorithm with Parallel Arrays
#include<stdio.h>
#include<stdlib.h>

#define sf(n) scanf("%d", &n)
#define pf(n) printf("%d\n", (int)n)

//Scans two array simultaneously
void scanArrayWith2D(int *a, int *b, int n) {
	int j = 0, k = 0;
	for(int i = 0; i < 2 * n; i++) {
		if(i % 2 == 0) {	//First we take a then we take b
			sf(*(a + j));
			j++;
		}
		else if(i % 2 == 1) {
			sf(*(b + k));
			k++;
		}
	}
}

//This does the basic querying and shows the info related in other array
void solve(int *a, int *b, int n, int key) {
	for(int i = 0; i < n; i++) {
		if(*(a + i) == key) pf(*(b + i));
		else if(*(b + i) == key) pf(*(a + i));
	}
}

/*
 * So basic idea is that I maintain two arrays parallely
 * and when query about one is asked I can hand in the info of the other array
*/

int main() {
	int n;
	sf(n);
	int a[n], b[n];
	scanArrayWith2D(a, b, n);
	int key;
	sf(key);
	solve(a, b, n, key);
	return 0;
}
