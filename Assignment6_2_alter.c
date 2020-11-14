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

#include<stdio.h>

#define sfn(n) scanf("%d", &n)
#define sf scanf
//#define sf(g) scanf("%d %d", &g.n1, &g.n2)
#define pf printf

struct Graph {
	int n1, n2;
};

typedef struct Graph Graph;

//The basic idea is to draw out a structure which has two values.
int main() {
	int n;
	sfn(n);
	Graph g[n];
	for(int i = 0; i < n ;i++) {
		sf("%d %d", &g[i].n1, &g[i].n2);
	}
	int key;
	sfn(key);
	for(int i = 0; i < n; i++) {
		if(g[i].n1 == key) {
			pf("%d\n", g[i].n2);
		}
		else if(g[i].n2 == key) {
			pf("%d\n", g[i].n1);
		}
	}
	return 0;
}
