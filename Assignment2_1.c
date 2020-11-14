/*
 * 
In this assignment, you will be given an NxN matrix. You have to
determine whether the matrix is a upper triangular or lower triangular matrix or both or not a triangular matrix. 

The diagonal of the matrix M of size NxN is the set of entries
M(0,0),M(1,1), M(2,2), ..., M(N,N). 

A matrix is upper triangular if every entry below the diagonal is
0. For example,  
1 1 1
0 0 1
0 0 2
is an upper triangular matrix. (The diagonal itself, and the entries
above can be zeroes or non-zero integers.) 

A matrix is lower triangular if every entry above the diagonal is
0. For example, 
2 0 0
3 1 0
4 2 2
is a lower triangular matrix  (The diagonal itself, and the entries
below can be zeroes or non-zero integers.) . 

A matrix is not a triangular matrix if it is neither a upper triangular nor a  lower
triangular.

You may not use arrays for this program.

Input
First, you will be given N, which is the size of the matrix.

Then you will be given N rows of integers, where each row consists of
N integers separated by spaces. 

Output
If the input matrix is lower triangular, then print -1.
If the input matrix is upper triangular, then print 1.
If the input matrix is both lower and upper triangular, then print 2.
If the input matrix is not a triangular matrix, then print 0.

Kindly do not use arrays in the code.
*/

/*
 * From here on I will give some pre-requistes that you have to know to solve the problem
 * In this problem you need to know some basic matrix teminologies like how scan a variable.
 * And some knowledge about incrementing a variable.
 * Don't worry I will be using the post-increment throughout this document.
 * And probably post-increment is all you need.
 * Don't know why Shruti mam gives such tough increment problems.
 *
*/

#include<stdio.h>

int main() {
	int n, number_in_matrix, count_of_upper_triangle = 0, count_of_lower_triangle = 0;	//First time I named variables according to the job they do
	//Mini wave celebration!!
	scanf("%d", &n);	//Scanning the number of rows and columns which in this question are the same
	for(int i = 0; i < n; i++) {	//Looping for the rows
		for(int j = 0; j < n; j++) {	//Looping for the columns
			scanf("%d", &number_in_matrix);	//Scanning the current matrix[i][j] value
			if(i < n && j < i && number_in_matrix != 0) {	//According to the problem we need to figure if this matrix is an upper triangular matrix
				//For upper triangular matrix the row number is greater than the column number
				count_of_upper_triangle++;		//Counting for number of non-zero elements so that the matrix becomes likely that it is a upper triangular matrix
			}
			//Notice that the next statement is not an else
			//We want to run above condition as well as the next condition
			//Because there is no guarentee that it will be one or the other, so we need to check for both condition
			if(i < n && j > i && number_in_matrix != 0) {	//Now figuring if this matrix is a lower triangular matrix
				//For lower triangular matrix the column number is greater than the row number and off course
				count_of_lower_triangle++;
			}
		}
	}
	//Notice that we are using 'else if' in next few lines, because according to problem, we have a priority and we need to just print according to the condition
	if(count_of_lower_triangle == 0 && count_of_upper_triangle == 0) {	// if matrix is neither a upper nor a lower triangular matrix, then we print according to the condition stated in problem
		printf("2");
	}
	else if(count_of_lower_triangle == 0) {	//if the matrix is not lower triangular matrix, see the above problem
		printf("-1");
	}
	else if(count_of_upper_triangle == 0) {	//if the matrix is not upper triangular matrix, see the above problem
		printf("1");
	}
	else {	//if matrix is none of the stated condition.
		printf("0");
	}
	return 0;
}
